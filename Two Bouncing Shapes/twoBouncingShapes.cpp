//
//  main.cpp
//  OpenGL Bouncing Sqaure
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


float posXRed = -0.5f, posYRed = 0.0f, posZ = 0.0f;
float posXGreen = 0.5f, posYGreen = 0.0f;



void rectangle(){			//creates shape
    glBegin(GL_QUADS);	//creates polygon shape, GL_QUADS could also be used
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.0714, -0.1);
    glVertex2f(-0.0714, 0.1);
    glVertex2f(0.0714, 0.1);
    glVertex2f(0.0714, -0.1);
    glEnd();

}

void DrawTriangle() // draws a triangle
{
glBegin(GL_TRIANGLES);
glVertex3f(-0.1f, -0.1f, 0.0f);
glVertex3f( 0.1f, -0.1f, 0.0f);
glVertex3f( 0.0f, 0.1f, 0.0f);
glEnd();
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.0f);

	glPushMatrix(); // make a new layer
	glTranslatef(posXRed, posYRed, posZ);
	//glTranslatef(-0.5, 0, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	DrawTriangle();
	glPopMatrix(); // remove the layer

	glPushMatrix(); // make another layer
	glTranslatef(posXGreen, posYGreen, posZ);
	glColor3f(0.0f, 1.0f, 0.0f);
	DrawTriangle();
	glPopMatrix(); // remove the layer
	
	glFlush();
}


float moveXRed = (0.0714f/4.0);
float moveYRed = (0.1f/4.0);	//sets how much the object will move(1/10th) of the screen

float moveXGreen = (0.0714f/4.0);
float moveYGreen = (0.1f/4.0);	//sets how much the object will move(1/10th) of the screen

void moveSqaure()
{
	if(posYRed >= 0.9 || posYRed <= -0.9)
		moveYRed *= -1.0;
	if(posXRed >= 0.9 || posXRed <= -0.9)
		moveXRed *= -1.0;
	posYRed += moveYRed;
	posXRed += moveXRed;
	
	if(posYGreen >= 0.9 || posYGreen <= -0.9)
		moveYGreen *= -1.0;
	if(posXGreen >= 0.9 || posXGreen <= -0.9)
		moveXGreen *= -1.0;
	posYGreen += moveYGreen;
	posXGreen += moveXGreen;
	
	glutPostRedisplay();
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper Red corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);				//initialize GLUT
    glutInitWindowSize(1200,1200);		//set the windows width and heigth
    glutInitWindowPosition(1000, 1000);		//set the initial position of the window
    glutCreateWindow("Movable Object");	//set  name of window
    glutDisplayFunc(display);			//creates the object
	glutIdleFunc(moveSqaure);			//causes the sqaure to be moved contantly
    glutMainLoop();						// makes it so that program never returns

	
}
