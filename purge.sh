#!/bin/bash

YELLOW="\e[33m"
RED="\e[91m"
GREEN="\e[92m"
BOLD="\e[1m"

RESET_COLOR="\e[0m"

echo -e $YELLOW$BOLD

if [ -d out ]; then
    rm -r out;
    echo -e "Removing 'out' directory..."
fi;
if [ -d .vs ]; then
    rm -r .vs;
    echo -e "Removing '.vs' directory..."
fi;
if [ -d build/.vs ]; then
    rm -r build/.vs
    echo -e "Removing 'build/.vs' directory..."
fi;
if [ -d build/babel.dir ]; then
    rm -r build/babel.dir
    echo -e "Removing 'build/babel.dir' directory..."
fi;
if [ -d build/bin ]; then
    rm -r build/bin
    echo -e "Removing 'build/bin' directory..."
fi;
if [ -d build/CMakeFiles ]; then
    rm -r build/CMakeFiles
    echo -e "Removing 'build/CMakeFiles' directory..."
fi;
if [ -d build/lib ]; then
    rm -r build/lib
    echo -e "Removing 'build/lib' directory..."
fi;
if [ -d build/x64 ]; then
    rm -r build/x64
    echo -e "Removing 'build/x64' directory..."
fi;

if [ -f build/ALL_BUILD.vcxproj ]; then
    rm -f build/*.vcxproj*
    echo -e "Removing 'vcxproj' files..."
fi;
if [ -f build/Babel.sln ]; then
    rm -f build/Babel.sln
    echo -e "Removing 'Babel.sln' file..."
fi;
if [ -f build/cmake_install.cmake ]; then
    rm -f build/cmake_install.cmake
    echo -e "Removing 'cmake_install.cmake' file..."
fi;
if [ -f build/CMakeCache.txt ]; then
    rm -f build/CMakeCache.txt
    echo -e "Removing 'CMakeCache.txt' file..."
fi;

echo -e "${GREEN}Project cleaned${RESET_COLOR}";

