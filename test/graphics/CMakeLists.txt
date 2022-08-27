add_executable(graphics_test tester.cpp)

target_include_directories(graphics_test PUBLIC ${PROJECT_BINARY_DIR})

target_include_directories(graphics_test 
    PUBLIC external/glfw/include
	${GLEW_INCLUDE_DIRS}
	${GL_INCLUDE_DIRS}
	${GLU_INCLUDE_DIRS}
)

target_link_directories(graphics_test 
	PUBLIC external/glfw/src
	${GLEW_LIB_DIRS}
	${GL_LIB_DIRS}
	${GLU_LIB_DIRS}
)

target_link_libraries(graphics_test glfw ${GLEW_LIBRARIES} ${GL_LIBS} ${GLU_LIBS})

add_test(NAME "GraphicsTest" COMMAND "graphics_test" arg1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS graphics_test DESTINATION bin)