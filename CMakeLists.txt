cmake_minimum_required(VERSION 3.22.1)

project(HelloWorld VERSION 1.0.0)

set(CMAKE_MODULE_PATH cmake)

# For vcpkg stuff 
set(CMAKE_TOOLCHAIN_FILE "C:/Users/cdsmi/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/Users/cdsmi/vcpkg/installed/x64-windows/share")
set(OpenCV_DIR "C:/Users/cdsmi/vcpkg/installed/x64-windows/share/opencv")

# Find the package include directorys and find the lirbaries
find_package(GLEW REQUIRED)
find_package(OpenCV REQUIRED)

# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES  
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please check")
endif()

add_subdirectory(external/glfw)

# Adder use logic 
option(USE_ADDER "A simple library for adding 2 floats" ON)
option(TEST_ADDER "Test library for adding 2 floats." ON)
option(TEST_GRAPHICS "Test launching opengl with glfw window." ON)

if(TEST_ADDER)
    add_subdirectory(Adder)
    list(APPEND EXTRA_LIB_DIRS Adder)
    list(APPEND EXTRA_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/Adder")
    list(APPEND EXTRA_LINKS adder)
endif()

configure_file(HelloWorldConfig.h.in HelloWorldConfig.h)

install(FILES "${PROJECT_BINARY_DIR}/HelloWorldConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${HelloWorld_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${HelloWorld_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${HelloWorld_VERSION_PATCH}")
include(CPack) 

if(TEST_ADDER OR TEST_GRAPHICS)
    add_subdirectory(test)
endif()