package br.lnls.dig.gradle.nativedistribution.tasks

import org.gradle.api.distribution.Distribution
import org.gradle.api.file.FileCollection
import org.gradle.api.internal.file.copy.CopyAction
import org.gradle.api.internal.resolve.ProjectModelResolver
import org.gradle.api.tasks.bundling.AbstractArchiveTask
import org.gradle.api.tasks.Input
import org.gradle.api.tasks.InputFiles
import org.gradle.api.tasks.OutputFile
import org.gradle.language.nativeplatform.DependentSourceSet
import org.gradle.language.nativeplatform.HeaderExportingSourceSet
import org.gradle.model.internal.registry.ModelRegistry
import org.gradle.nativeplatform.NativeBinarySpec
import org.gradle.nativeplatform.NativeLibrarySpec
import org.gradle.nativeplatform.SharedLibraryBinarySpec
import org.gradle.platform.base.ComponentSpecContainer

import br.lnls.dig.gradle.nativedistribution.model.internal.RpmDistribution
import br.lnls.dig.gradle.nativedistribution.tasks.internal.Dependency
import br.lnls.dig.gradle.nativedistribution.tasks.internal.RpmArchiveHeadersAction
import br.lnls.dig.gradle.nativedistribution.tasks.internal.RpmArchiveSharedLibrariesAction
import br.lnls.dig.gradle.sysfiles.model.SysFilesSet

class Rpm extends AbstractArchiveTask {
    RpmDistribution distribution
    File buildDir
    String installationPrefix

    @Input
    LinkedHashSet<Dependency> dependencies

    private File outputDirectory

    FileCollection executables
    FileCollection exportedHeaders
    FileCollection sharedLibraries
    FileCollection sysFiles
    FileCollection unpackagedDependencies

    public Rpm() {
        extension = 'rpm'
        installationPrefix = '/usr/local'

        dependencies = new LinkedHashSet<>()
    }

    @OutputFile
    public File getOutputFile() {
        return new File(outputDirectory, distribution.outputFileName)
    }

    public void setOutputDirectory(File outputDirectory) {
        this.outputDirectory = outputDirectory
    }

    @Override @InputFiles
    public FileCollection getSource() {
        def source = super.getSource()

        source += unpackagedDependencies

        if (distribution.isDevelopment())
            source += exportedHeaders
        else
            source += sharedLibraries + executables + sysFiles

        return source
    }

    @Override
    protected CopyAction createCopyAction() {
        if (distribution.isDevelopment())
            return new RpmArchiveHeadersAction(this)
        else
            return new RpmArchiveSharedLibrariesAction(this)
    }

    public addDependency(String name, String version) {
        dependencies.add(new Dependency(name, version))
    }

    public void setDistribution(Distribution distribution) {
        this.distribution = new RpmDistribution(distribution, project)

        executables = distribution.executableFiles
        exportedHeaders = distribution.exportedHeaders
        sharedLibraries = distribution.sharedLibraryFiles
        sysFiles = distribution.sysFiles
    }

    protected FileCollection collectExportedHeadersFromBinaries(
            Set<SharedLibraryBinarySpec> binaries) {
        return binaries
            .collect { it.inputs }
            .collect { it.withType(HeaderExportingSourceSet) }
            .sum()
            .collect { it.exportedHeaders }
            .sum() ?: project.files()
    }

    public void resolveDependencies(ProjectModelResolver resolver) {
        unpackagedDependencies = project.files()

        addDependenciesFrom(distribution.executables, resolver)
        addDependenciesFrom(distribution.sharedLibraries, resolver)
    }

    public void addDependenciesFrom(Set<NativeBinarySpec> binaries,
            ProjectModelResolver resolver) {
        binaries.inputs.each { sources ->
            def sourcesWithDependencies = sources.findAll { source ->
                source instanceof DependentSourceSet
            }

            sourcesWithDependencies.each { source ->
                source.libs.each { lib ->
                    addDetectedDependency(lib, resolver)
                }
            }
        }
    }

    protected void addDetectedDependency(Object dependency,
            ProjectModelResolver resolver) {
        if (dependency instanceof Map)
            addDetectedDependencySpecification((Map)dependency, resolver)
        else
            throw new RuntimeException("Unknown dependency: $dependency")
    }

    private void addDetectedDependencySpecification(Map specification,
            ProjectModelResolver resolver) {
        def projectPath = specification.get("project")
        def libraryName = specification.get("library")
        def projectModel = resolver.resolveProjectModel(projectPath)
        def packageTask = getProjectPackageTask(projectPath, projectModel)

        if (packageTask != null) {
            dependsOn packageTask
            addDependencyToProjectRpm(projectPath)
        } else
            includeFilesOfProjectLibraryDependency(libraryName, projectModel)
    }

    private Rpm getProjectPackageTask(String projectPath,
            ModelRegistry projectModel) {
        def tasks = projectModel.find("tasks", Object)
        def expectedName = name

        return tasks.find { task -> task.name == expectedName }
    }

    private void addDependencyToProjectRpm(String projectPath) {
        def projectName = projectPath.split(':').last()

        if (distribution.isDevelopment())
            projectName += "-devel"

        addDependency(projectName, project.version.toString())
    }

    private void includeFilesOfProjectLibraryDependency(String libraryName,
            ModelRegistry projectModel) {
        def library = getDependencyLibrary(libraryName, projectModel)
        def libraryBinaries = getMatchingLibraryBinaries(library)

        if (distribution.isDevelopment())
            includeHeadersOfProjectLibraryDependency(libraryBinaries)
        else
            includeBinariesOfProjectLibraryDependency(libraryBinaries)
    }

    private NativeLibrarySpec getDependencyLibrary(String libraryName,
            ModelRegistry projectModel) {
        def components = projectModel.find("components", ComponentSpecContainer)

        return components.withType(NativeLibrarySpec).get(libraryName)
    }

    private Set<SharedLibraryBinarySpec> getMatchingLibraryBinaries(
            NativeLibrarySpec library) {
        def sharedLibraryBinaries = library.binaries
                .withType(SharedLibraryBinarySpec)

        return sharedLibraryBinaries.findAll { binary ->
            return binary.buildType.name == distribution.buildType.name &&
                binary.flavor.name == distribution.flavor.name &&
                binary.targetPlatform.compatibilityString ==
                        distribution.platform.compatibilityString
        }
    }

    private void includeHeadersOfProjectLibraryDependency(
            Set<SharedLibraryBinarySpec> binaries) {
        unpackagedDependencies += collectExportedHeadersFromBinaries(binaries)
    }

    private void includeBinariesOfProjectLibraryDependency(
            Set<SharedLibraryBinarySpec> binaries) {
        def binaryFiles = binaries.collect { binary ->
            binary.sharedLibraryFile
        }

        unpackagedDependencies += project.files(binaryFiles)
    }
}
