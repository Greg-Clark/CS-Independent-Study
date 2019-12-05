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


float posX = 0, posY = 0, posZ = 0;



void rectangle(){			//creates shape
    glBegin(GL_QUADS);	//creates polygon shape, GL_QUADS could also be used
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.0714, -0.1);
    glVertex2f(-0.0714, 0.1);
    glVertex2f(0.0714, 0.1);
    glVertex2f(0.0714, -0.1);
    glEnd();

}

void display(){
    //Clear Window
	glClearColor(0, 0, 0, 1);		//sets background color
    glClear(GL_COLOR_BUFFER_BIT);	//clears any previous objects
	
	
    //glMatrixMode(GL_MODELVIEW);		//Applies subsequent matrix operations to the modelview matrix stack.
    glLoadIdentity();				//loads matrix with identity matrix
    //glPushMatrix();					//makes matrix on top of stack identitical to the one below it
    glTranslatef(posX,posY,posZ); 	//sets position of rectangle
    rectangle();
    //glPopMatrix();					//replaces current matrix with one below it
    glFlush();						//displays rectangle
}


float moveX = (0.0714f/4.0);
float moveY = (0.1f/4.0);	//sets how much the object will move(1/10th) of the screen
void moveSqaure()
{
	if(posY >= 0.9 || posY <= -0.9)
		moveY *= -1;
	if(posX >= 0.9 || posX <= -0.9)
		moveX *= -1.0;
	posY += moveY;
	posX += moveX;
	
	glutPostRedisplay();
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);				//initialize GLUT
    glutInitWindowSize(700,500);		//set the windows width and heigth
    glutInitWindowPosition(0, 0);		//set the initial position of the window
    glutCreateWindow("Movable Object");	//set  name of window
    glutDisplayFunc(display);			//creates the object
	glutIdleFunc(moveSqaure);			//causes the sqaure to be moved contantly
    glutMainLoop();						// makes it so that program never returns

	
}
