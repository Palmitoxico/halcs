/*
 * Copyright (C) 2015 LNLS (www.lnls.br)
 * Author: Lucas Russo <lucas.russo@lnls.br>
 *
 * Released according to the GNU LGPL, version 3 or any later version.
 */

#include "bpm_server.h"

const char *build_revision = GIT_REVISION;
const char *build_date = __DATE__ " " __TIME__;
const char *build_user_name = GIT_USER_NAME;
const char *build_user_email = GIT_USER_EMAIL;

char *revision_clone_build_rev (void)
{
    return hutils_clone_str (build_revision);
}

char *revision_clone_build_date (void)
{
    return hutils_clone_str (build_date);
}

char *revision_clone_build_user_name (void)
{
    return hutils_clone_str (build_user_name);
}

char *revision_clone_build_user_email (void)
{
    return hutils_clone_str (build_user_email);
}

int revision_copy_build_revision (char *dest, size_t size)
{
    return hutils_copy_str (dest, build_revision, size);
}

int revision_copy_build_date (char *dest, size_t size)
{
    return hutils_copy_str (dest, build_date, size);
}

int revision_copy_build_user_name (char *dest, size_t size)
{
    return hutils_copy_str (dest, build_user_name, size);
}

int revision_copy_build_user_email (char *dest, size_t size)
{
    return hutils_copy_str (dest, build_user_email, size);
}
