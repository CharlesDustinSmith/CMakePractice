#include <iostream>
#include "Adder/adder.h"
#include <GLFW/glfw3.h>


int main() 
{
	std::cout << "Hello World from Charles Smith." << std::endl;
	std::cout << "Testing out adder " << add( 72.3f, 73.8f ) << std::endl;

	GLFWwindow *window;

	if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

	window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
	
	if( !window )
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}

	// Main loop
	while( !glfwWindowShouldClose( window ) )
	{
		// // Draw gears 
		// draw();

		// // Update animation
		// animate();

		// Swap buffers
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	// Terminate GLFW 
	glfwTerminate();

	return 0;
}
