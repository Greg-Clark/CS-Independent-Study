//
//  main.cpp
//  OpenGL 2 Shapes
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


//#include <iostream>
//#include <stdlib.h>
//#include <math.h>
//#include <GLUT/glut.h>	//this is the only #include that is needed

//#include <GL/glut.h>
//#include "windows.h" //used for microsoft windows




void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to using RBG(0-1) and alpha(1 sets to opaque)
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // sets the color using RBG
	glVertex2f(1, 1);    // position of object using x, y as a multiple, 1 being max
	glVertex2f( 1, -1);
	glVertex2f( 0,  0);
	glEnd();
	
	glFlush();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-1.0, 1.0);
	glVertex2f(-1.0, -1);
	glVertex2f(0.0, 0.0);
	glEnd();
	
	
	glFlush();  // Render now
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, -1);
	glVertex2f(0.0, 0.0);
	glEnd();
	
	glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(500, 500);   // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutCreateWindow("Multiple Shapes Test"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
