#!/usr/bin/env bash

# help debug
set -x

if [ -z "$GRADLE" ]; then
    sonar-scanner
fi
