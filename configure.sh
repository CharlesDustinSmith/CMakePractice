#!/bin/sh

# Removing the build project if it exists
DIR=./out
green='\033[0;32m'
white='\e[0;37m'
purple='\e[0;35m'
INFO="${green}[INFO]${white}"
if [ -d "$DIR"];
then 
    echo "\n${INFO} ${purple}${DIR}${white} directory already exist, commencing deletion. \n"
    rm -rf out
else 
    echo "\n${INFO} ${purple}${DIR}${white} directory does not exist, commencing creation. \n"
fi

# Building the source tree 
echo "\n${INFO} Building Source Tree. "
cmake -D GLFW_BULID_DOCS=OFF -D USE_ADDER=ON -D CMAKE_CXX_FLAGS="-Werror -Wall -Wextra" -D CMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake -S . -G "Unix Makefiles" -B out/build

# Building the project
echo "\n${INFO} Building The Project Creating Executable. "
cmake --build out/build --config Debug --clean-first

# Running the project 
cd ./out/build
./HelloWorld
