#include <iostream>
#include <GLFW/glfw3.h>
#include <HelloWorldConfig.h>
<<<<<<< HEAD
=======
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
>>>>>>> 23cc1b763cd3c1b6a672cbd05b08772f575a759d
#ifdef USE_ADDER
	#include <adder.h>
#endif

int main( int argc, char *argv[] ) 
{
	std::cout << "Hello World from Charles Smith." << std::endl;

	#ifdef USE_ADDER
		std::cout << "Testing out adder " << add( 72.3f, 73.8f ) << std::endl;
	#else
		std::cout << "USE_ADDER=OFF therefore the adder library was not used in the source code." << std::endl;
	#endif

	std::cout << "Program name : " << HelloWorld_NAME << std::endl;
	std::cout << "Program Version : " << HelloWorld_VER << std::endl;
	std::cout << "argv[0]: " << argv[0] << " Version: " << HelloWorld_VERSION_MAJOR 
			  << "." << HelloWorld_VERSION_MINOR 
			  << "." << HelloWorld_VERSION_PATCH << std::endl;
	std::cout << "argc: " << argc << std::endl;

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
