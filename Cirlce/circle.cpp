//
//  main.cpp
//  OpenGL Sphere
//
//  Created by Gregory Clark on 10/1/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//



#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif


float ballX = 0.0f;
float ballY = 0.0f;
float ballZ = -1.0f;



void drawBall()
{
	glColor3f(1, 0, 0.0); //set ball color
	glTranslatef(ballX,ballY,ballZ); //position that the ball will be in
	glutSolidSphere (0.5, 100, 100); //create ball. Radius, slices, stacks
									 //slices is the number of subdivisions around the Z axis
									 //stacks is the number of subdivisions along the z axis
}


void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to using RBG(0-1) and alpha(1 sets to opaque)
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	
	drawBall();
	
	glutSwapBuffers();	//displays ball onto screen
	
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(500, 500);   // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutCreateWindow("OpenGL Square Test"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
