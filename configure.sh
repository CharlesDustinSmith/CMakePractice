#!/bin/sh

cmake -DGLFW_BULID_DOCS=OFF -DUSE_ADDER=ON -S . -B out/build -DCMAKE_TOOLCHAIN_FILE=/home/charlessmith/vcpkg/scripts/buildsystems/vcpkg.cmake

