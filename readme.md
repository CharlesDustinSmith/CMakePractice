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