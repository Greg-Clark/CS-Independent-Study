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
#include <string>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>


float posZ = 0.0f;

//position of ball
float ballPosX = 0.0f, ballPosY = 0.0f;

//position of paddles
float rightRectPosX = 0.8f, rightRectPosY = 0.0f;
float leftRectPosX = -0.8f, leftRectPosY = 0.0f;

//paddles' scores'
int leftRectScore = 0, rightRectScore = 0;

//speed of ball
float moveBallY = 0.006;
float moveBallX = 0.02;

//amount paddles move
float move_unit = 0.05;

bool gameOver = false;
std::string winner;

bool keyBuffer[256];


std::string convertScoreToStirng()
{
	std::string s = std::to_string(leftRectScore) + " - " + std::to_string(rightRectScore);
	return s;
}

void scoreboard(std::string s,float x,float y)
{
	glRasterPos2f(x, y);

	for (int i = 0; i < s.length(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void gameOverScoreboard(std::string s, float x, float y)
{
	glRasterPos2f(x, y);

	for (int i = 0; i < s.length(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void updateScore(std::string pointGoesTo)
{
	
	moveBallX = 0.02;
	if(pointGoesTo == "Right")
	{
		rightRectScore++;
	}
	else if(pointGoesTo == "Left")
	{
		leftRectScore++;
		moveBallX *= -1;
	}
	//resets position of things in game
	ballPosX = 0.0;
	ballPosY = 0.0;
	leftRectPosY = 0;
	rightRectPosY = 0;
	int randNum = rand()%100;
	if(randNum > 90)		//10% chance
		moveBallY = 0.06;
	else if(randNum > 70)		//20% chance
		moveBallY = 0.04;
	else if(randNum > 50)		//20% chance
		moveBallY = 0.02;
	else if(randNum > 10)		//40% chance
		moveBallY = 0.006;
	else					//10% chance
		moveBallY = 0;
}

void drawBall()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.01, 0.01);
	glVertex2f(0.01, -0.01);
	glVertex2f(-0.01, -0.01);
	glVertex2f(-0.01, 0.01);
	glEnd();
}

void drawRectangle()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.01, 0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(-0.01, -0.2);
	glVertex2f(-0.01, 0.2);
	glEnd();
}

void updatePongs();

void display()
{
	glClearColor(0, 0, 0, 1);		//sets background color
    glClear(GL_COLOR_BUFFER_BIT);	//clears any previous objects
	
	updatePongs();
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, -1.0f);

	glPushMatrix(); // make a new layer
	glTranslatef(ballPosX, ballPosY, posZ);
	drawBall();
	glPopMatrix(); // remove the layer

	glPushMatrix(); // make another layer
	glTranslatef(rightRectPosX, rightRectPosY, posZ);
	drawRectangle();
	glPopMatrix(); // remove the layer

	glPushMatrix();
	glTranslatef(leftRectPosX, leftRectPosY, posZ);
	drawRectangle();
	glPopMatrix();
	
	scoreboard(convertScoreToStirng(), -0.1, 0.9);
	if(gameOver)
	{
		gameOverScoreboard(winner, -0.1, 0.2);
	}
	
	glFlush();
}




bool isTouchingRight()	//checks to see if ball is touching right paddle
{
	if(ballPosX >= rightRectPosX-0.02 && ballPosX <= rightRectPosX+0.04 && ballPosY <= rightRectPosY+0.2 && ballPosY >= rightRectPosY-0.2)
	{
		return true;
	}
	return false;
}

bool isTouchingLeft()	//checks to see if ball is touching left paddle
{
	if(ballPosX <= leftRectPosX+0.02 && ballPosX >= leftRectPosX-0.04 && ballPosY <= leftRectPosY+0.2 && ballPosY >= leftRectPosY-0.2)
	{
		return true;
	}
	return false;
}

void rightdeflectionAngleUp()
{
	if(ballPosY == rightRectPosY+0)
	{
		moveBallY = 0;
	}
	else if(ballPosY < rightRectPosY+0.05)
	{
		moveBallY = 0.006;
	}
	else if(ballPosY < rightRectPosY+0.1)
	{
		moveBallY = 0.02;
	}
	else if(ballPosY < rightRectPosY+0.15)
	{
		moveBallY = 0.04;
	}
	else if(ballPosY < rightRectPosY+0.2)
	{
		moveBallY = 0.06;
	}
}

void rightDeflectionAngleDown()
{
	if(ballPosY > rightRectPosY-0.05)
	{
		moveBallY = -0.006;
	}
	else if(ballPosY > rightRectPosY-0.1)
	{
		moveBallY = -0.02;
	}
	else if(ballPosY > rightRectPosY-0.15)
	{
		moveBallY = -0.04;
	}
	else if(ballPosY > rightRectPosY-0.2)
	{
		moveBallY = -0.06;
	}
}

void leftDeflectionAngleUp()
{
	if(ballPosY == leftRectPosY+0)
	{
		moveBallY = 0;
	}
	else if(ballPosY < leftRectPosY+0.05)
	{
		moveBallY = 0.006;
	}
	else if(ballPosY < leftRectPosY+0.1)
	{
		moveBallY = 0.02;
	}
	else if(ballPosY < leftRectPosY+0.15)
	{
		moveBallY = 0.04;
	}
	else if(ballPosY < leftRectPosY+0.2)
	{
		moveBallY = 0.06;
	}
}

void leftDeflectionAngleDown()
{
	if(ballPosY > leftRectPosY-0.05)
	{
		moveBallY = -0.006;
	}
	else if(ballPosY > leftRectPosY-0.1)
	{
		moveBallY = -0.02;
	}
	else if(ballPosY > leftRectPosY-0.15)
	{
		moveBallY = -0.04;
	}
	else if(ballPosY > leftRectPosY-0.2)
	{
		moveBallY = -0.06;
	}
}

void rightdeflectionAngle()
{
	if(ballPosY >= rightRectPosY)
	{
		rightdeflectionAngleUp();
	}
	else
		rightDeflectionAngleDown();
}

void LeftdeflectionAngle()
{
	if(ballPosY >= leftRectPosY)
		leftDeflectionAngleUp();
	else
		leftDeflectionAngleDown();
}

void makeBallMove()
{
	if(leftRectScore >= 7)
	{
		gameOver = true;
		winner = "Left Side Wins!";
		//causes game to stop being played
		moveBallY = 0;
		moveBallX = 0;
		move_unit = 0;
	}
	if(rightRectScore >= 7)
	{
		gameOver = true;
		winner = "Right Side Wins!";
		//causes game to stop being played
		moveBallY = 0;
		moveBallX = 0;
		move_unit = 0;
	}
	if(ballPosY >= 0.99 || ballPosY <= -0.99)
		moveBallY *= -1.0;
	if(ballPosX >= 0.99)
		updateScore("Left");
	else if(ballPosX <= -0.99)
		updateScore("Right");
	//increases the speed of the ball
	else if(isTouchingRight())
	{
		//determines the angle the ball gets launched
		//depending on where it hits the paddle
		rightdeflectionAngle();
		
		//max speed for the ball
		if(moveBallX <= 0.06)
		{
			moveBallX += 0.001;
		}
		moveBallX *= -1;
	}
	//increases the speed of the ball
	else if(isTouchingLeft())
	{
		//determines the angle the ball gets launched
		//depending on where it hits the paddle
		LeftdeflectionAngle();
		
		//max speed for the ball
		if(moveBallX >= -0.06)
		{
			moveBallX -= 0.001;
		}
		moveBallX *= -1;
	}
	ballPosY += moveBallY;
	ballPosX += moveBallX;
		
	glutPostRedisplay();
}


void updatePongs()
{
	if(keyBuffer[GLUT_KEY_UP])
	{
		if(rightRectPosY < .8)
			rightRectPosY += move_unit;
	}
	if(keyBuffer[GLUT_KEY_DOWN])
	{
		if(rightRectPosY > -.8)
		rightRectPosY -= move_unit;
	}
	if(keyBuffer['w'])
	{
		if(leftRectPosY < .8)
		leftRectPosY += move_unit;
	}
	if(keyBuffer['s'])
	{
		if(leftRectPosY > -.8)
		leftRectPosY -= move_unit;
	}
	
	glutPostRedisplay();
}


void keyPress(int key, int x, int y)
{
	keyBuffer[key] = true;
}

void keyPressUp(int key, int x, int y)
{
	keyBuffer[key] = false;
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper Red corner of screen
    //Windows tittle is name of program
	srand((unsigned)time(0));
    glutInit(&argc, argv);				//initialize GLUT
    glutInitWindowSize(1200, 1200);		//set the windows width and heigth
    glutInitWindowPosition(1000, 1000);		//set the initial position of the window
    glutCreateWindow("Movable Object");	//set  name of window
    glutDisplayFunc(display);			//creates the object
	glutSpecialFunc(keyPress);
	glutSpecialUpFunc(keyPressUp);
	glutIdleFunc(makeBallMove);
    glutMainLoop();						// makes it so that program never returns

	
}
