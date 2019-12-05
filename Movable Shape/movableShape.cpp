//
//  main.cpp
//  OpenGL Movable Shape
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
    glBegin(GL_POLYGON);	//creates polygon shape, GL_QUADS could also be used
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.1, -0.2);
    glVertex2f(-0.1, 0.2);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.1, -0.2);
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


float move_unit = 0.1f;	//sets how much the object will move(1/10th) of the screen
void keyboardown(int key, int x, int y)	//moves the shape
{
    switch (key){
        case GLUT_KEY_RIGHT:
			if(posX < .9)
				posX += move_unit;
            break;

        case GLUT_KEY_LEFT:
			if(posX > -.9)
				posX -= move_unit;
        break;

        case GLUT_KEY_UP:
			if(posY < .8)
				posY += move_unit;
            break;

        case GLUT_KEY_DOWN:
			if(posY > -.8)
				posY -= move_unit;
        break;

        default:
         break;
    }
    glutPostRedisplay();	//flags that the window needs to be redisplayed to show updates
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program
    glutInit(&argc, argv);				//initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);		//set the windows width and heigth
    glutInitWindowPosition(0, 0);		//set the initial position of the window
    glutCreateWindow("Movable Object");	//set  name of window
    glutDisplayFunc(display);			//creates the object
    glutSpecialFunc(keyboardown);		//checks to see if a key is being pressed
    glutMainLoop();						// makes it so that program never returns

}
