Configure and build with cmake using cmake-gui or use command-line

linux commmand line ez mode
```sh
    ./configure.sh 
    ./build.sh
    ./run.sh
```

##Cpack
1. You must reconfigure the project using the following command and create a License file
```sh
    ./configure.sh
```
2. You must then move over to the build directory and enter the following: 
```sh 
    cd build
    ./HelloWorld-1.0.0-Linux.sh
```
3. After doing the previous commands, a HelloWorld-1.0.0-Linux folder will appear, enter that folder and then enter the following commands:
```sh
    cd HelloWorld-1.0.0-Linux/bin
    ./HelloWorld
```

###Also install the following VSCode extension tools to make development a bit more easier.
1. CMake by: `twxs`
2. CMake Tools by: `Microsoft`

#Running CMake on Windows 
1. Add the msbuild.exe to your path directory
    1.1 Environment Variables / Path / "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin"
2. Build the project
    ```sh
        cd build
        MSBuild.exe .\HelloWorld.sln
    ```
3. Run the executable 
    ```sh
        cd Debug
        .\HelloWorld.exe
    ```
