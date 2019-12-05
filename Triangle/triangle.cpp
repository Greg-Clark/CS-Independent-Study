//
//  main.cpp
//  OoenGL Triangle
//
//  Created by Gregory Clark on 9/17/19.
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


#include <iostream>
//#include <stdlib.h>
#include <math.h>
//#include <GLUT/glut.h>	//this is the only #include that is needed

//#include <GL/glut.h>
//#include "windows.h" //used for microsoft windows




void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to using RGB(0-1) and alpha(1 sets to opaque)
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
									//also then requires there to be 4 vertexes
	glColor3f(0.0f, 1.0f, 0.0f); // sets the color using RGB
	//these help to position the shape. Position of object using x, y as a multiple, 1 being max
	//The numbers had f after them, can take them out and nothing changes
	glVertex2f(-1.0, -1.0); //bottom left
	glVertex2f( 1.0, -1.0);	//bottom right
	glVertex2f( 0,  1.0);	//top right
	glVertex2f(0,  1.0); //top left
	glEnd();
	
	glFlush();  // Render now
}

void displayTriangle() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to using RGB(0-1) and alpha(1 sets to opaque)
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	//also then requires there to be at least 3 vertexes for a shape to appear
	glColor3f(1.0f, 0.0f, 0.0f); // sets the color using RGB
	//these help to position the shape. Position of object using x, y as a multiple, 1 being max
	//The numbers had f after them, can take them out and nothing changes
	glVertex2f(-0.5, -0.5); //bottom left
	glVertex2f( 0.5, -0.5);	//bottom right
	glVertex2f( 0,  0.5);	//top
	glEnd();
	
	glFlush();  // Render now
}

void displayUserTriangle() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to using RGB(0-1) and alpha(1 sets to opaque)
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	double angle, xPos = 1, yPos = 1;
	int color;
	double red = 0, blue = 0, green = 0;
	
	std::cout << "Please enter the color for your triangle: 1-red, 2-green, 3-blue: ";
	std::cin >> color;
	std::cout << "Please enter the angle for your triangle(1°-89°): ";	//only works for a right triangle
	std::cin >> angle;
	
	if(angle >= 90 || angle <= 0)
	{
		std::cout << "Incorrect input. Defaulting to a 45° triangle";
		angle = 45;
	}
	if(angle <= 45)
	{
		angle *= (M_PI/180); //converts to radian
		yPos = tan(angle);
		if(yPos >= .5)
		{
			yPos *= 2;
			yPos -= 1;
		}
		else
		{
			yPos -= 1;
		}
	}
	else
	{
		angle = (90 - angle) * (M_PI/180); //converts to radian
		xPos = tan(angle);
		if(xPos >= .5)
		{
			xPos *= 2;
			xPos -= 1;
		}
		else
		{
			xPos -= 1;
		}
	}
	
	
	switch (color) {
		case 1:
			red = 1;
			break;
		case 2:
			green = 1;
			break;
		case 3:
			blue = 1;
			break;
		default:
			red = .5;
			blue = .5;
			green = .5;
			break;
	}
	
	
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	//also then requires there to be at least 3 vertexes for a shape to appear
	glColor3f(red, green, blue); // sets the color using RGB
	//these help to position the shape. Position of object using x, y as a multiple, 1 being max
	//The numbers had f after them, can take them out and nothing changes
	glVertex2f(-xPos, -1.0); //bottom left
	glVertex2f( 1.0, -1.0);	//bottom right
	glVertex2f( 1.0,  yPos);	//top
	glEnd();
	
	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(1200, 1200);   // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutCreateWindow("OpenGL Traingle Test"); // Create a window with the given title
	//glutDisplayFunc(display);				// displays triangle using 4 verticies
	//glutDisplayFunc(displayTriangle); 	// displays triangle using 3 verticies
	glutDisplayFunc(displayUserTriangle);	// displays triangle based on user input
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
