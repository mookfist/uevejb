#!/bin/bash
rm -rf ./_build
for f in $(find . -name "CMakeFiles" -or -name "cmake_install.cmake" -or -name "Makefile" -or -name "CMakeCache.txt"); do rm -r $f; done
