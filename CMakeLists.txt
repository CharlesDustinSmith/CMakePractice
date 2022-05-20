cmake_minimum_required(VERSION 3.22.1)

project(HelloWorld VERSION 1.0.0)

set(CMAKE_MODULE_PATH cmake)

find_package(GLEW REQUIRED)

# FIND LIBRARY FOR CMAKE 3.22.1 (NO [REQUIRED] IN CMAKE YET)
# find_library(myglewlib glew NAMES glew2 GLEW GLEW2 DOC "glew library")
# if(${myglewlib} STREQUAL myglewlib-NOTFOUND)
#     message(FATAL_ERROR "no glew found, the Names or suggested libraries could be wrong or you did not run <sudo apt-get install libglew-dev>")
# else()
#     message(STATUS "Glew library found, :)")
# endif()

# find_library(myglulib glu NAMES GLU DOC "glu library")
# if(${myglulib} STREQUAL myglulib-NOTFOUND)
#     message(FATAL_ERROR "No GLU Library found, the names maybe wrong or you did not sudo apt install it.")
# else()
#     message(STATUS "GLU Library found, :)")
# endif()

# find_library(mygllib gl NAMES GL DOC "gl library")
# if(${mygllib})
#     message(FATAL_ERROR "No GL Library found, the names maybe wrong or you may not have GLFW set up correctly.")
# else()
#     message(STATUS "GL library found, :)")
# endif()

# Adder use logic 
option(USE_ADDER "A simple library for adding 2 floats" ON)

if(USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIB_DIRS Adder)
    list(APPEND EXTRA_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/Adder")
    list(APPEND EXTRA_LINKS adder)
endif()

configure_file(HelloWorldConfig.h.in HelloWorldConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

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

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external/gflw/src
    ${EXTRA_LIB_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw ${GLEW_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/HelloWorldConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${HelloWorld_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${HelloWorld_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${HelloWorld_VERSION_PATCH}")
include(CPack) 