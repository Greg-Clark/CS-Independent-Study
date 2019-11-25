//
//  Objects.cpp
//  Mario 1-1
//
//  Created by Gregory Clark on 11/6/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include "Objects.hpp"
#include <OpenGL/gl.h>
#include <GLUT/glut.h>



void Object::move()
{
	if(animation)
	{
		m_x -= 0.01;
		return;
	}
	if(keyBuffer[GLUT_KEY_RIGHT] && obj[mariosVecPos]->getX() == 0)
	{
		m_x -= moveObjects;
	}
	if(keyBuffer[GLUT_KEY_LEFT] && !(control->isAtEdge()))
	{
		m_x += moveObjects;
	}
}

int Object::getX()
{
	return (int)(m_x * 1000); //multiple by 1000 to get rid of floating point comparison error
}

int Object::getY()
{
	return (int)(m_y * 1000);
}

int Object::getHeight() //returns how tall an object is
{
	return 100;
}

int Object::getLength() //returns how long an object is
{
	return (int)(m_length*1000);
}


void Block::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0);
	drawBlock();
	glPopMatrix();
}

void Block::drawBlock()
{
	glBegin(GL_QUADS);
	glColor3f(255.0f/255.0f, 165.0f/255.0f, 0.0f/255.0f);	//color for orange
	glVertex2f(0, 0);
	glVertex2f(0.1, 0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0, 0.1);
	glEnd();
}






void Brick::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0);
	drawBrick();
	glPopMatrix();
}

void Brick::drawBrick()
{
	glBegin(GL_QUADS);
	glColor3f(170.0f/255.0f, 121.0f/255.0f, 66.0f/255.0f);	//color for brown
	glVertex2f(0, 0);
	glVertex2f(0.1, 0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0, 0.1);
	glEnd();
}






void DarkBrick::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0);
	drawDarkBrick();
	glPopMatrix();
}

void DarkBrick::drawDarkBrick()
{
	glBegin(GL_QUADS);
	glColor3f(170.0f/255.0f, 121.0f/255.0f, 66.0f/255.0f);	//color for brown
	glVertex2f(0, 0);
	glColor3f(0, 0, 0);
	glVertex2f(0.1, 0);
	glColor3f(170.0f/255.0f, 121.0f/255.0f, 66.0f/255.0f);	//color for brown
	glVertex2f(0.1, 0.1);
	glColor3f(1, 1, 1);
	glVertex2f(0, 0.1);
	glEnd();
}

void Pipe::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0);
	drawPipe();
	glPopMatrix();
}

void Pipe::drawPipe()
{
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);	//color for brown
	glVertex2f(0, 0);
	glVertex2f(0.2, 0);
	glVertex2f(0.2, m_height);
	glVertex2f(0, m_height);
	glEnd();
}

int Pipe::getHeight()
{
	return (int)(m_height*1000);
}






void Floor::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0);
	drawFloor();
	glPopMatrix();
}

void Floor::drawFloor()
{
	glBegin(GL_QUADS);
	glColor3f(170.0f/255.0f, 121.0f/255.0f, 66.0f/255.0f);	//color for brown
	glVertex2f(0, 0);
	glVertex2f(m_length, 0);
	glVertex2f(m_length, 0.2);
	glVertex2f(0, 0.2);
	glEnd();
}








void Mario::doSomething()
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0.0f);
	drawMario();
	glPopMatrix();
}

void Mario::drawMario()
{
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(-0.05, 0);
	glVertex2f(0.05, 0);
	glVertex2f(0.05, 0.2);
	glVertex2f(-0.05, 0.2);
	glEnd();
}


void Mario::move()
{
	
	if(animation)
	{
		if(this->getY() < -800)
		{
			m_y = -0.8;
		}
		else if(this->getY() > -800)
		{
			m_y -= 0.005;
		}
		return;
	}
	
	
	if(keyBuffer[GLUT_KEY_UP] && !isJumping)
	{
		//not needed until hit detection and
		//actual jumping is implemented
		//if(m_y < -0.2)
		makeMarioJump();
	}
	if(keyBuffer[GLUT_KEY_DOWN])
	{
		if(m_y > -0.8)
			m_y -= 0.05;
		else
			m_y = -0.8;
	}
	//these 2 if statements are used for mario on left edge
	if(keyBuffer[GLUT_KEY_LEFT] & control->isAtEdge() & m_x > -0.95)
	{
		m_x -= moveObjects;
	}
	if(keyBuffer[GLUT_KEY_RIGHT] & control->isAtEdge())
	{
		if(m_x > 0)
			m_x = 0;
		else
			m_x += moveObjects;
	}
	if(keyBuffer[GLUT_KEY_RIGHT])	//mario had an issue when returning where he would sometimes not have his position set exactly back to zero. Theses if statements resolved that issue
	{
		if(m_x >= -0.001)
			m_x = 0;
	}
	if(isJumping)
	{
		if(control->isTouchingBlock())
		{
			//mario stops at the blocks position height
			velocity = 0;
			isJumping = false;
		}
		if(control->bumpHead())
			velocity = 0;
		m_y += velocity;
		velocity -= 9.8/1000; //only important thing is the ratio here between initial velocity
		
		
		
	}
	else if(control->nothingBelow())
	{
		//makes mario stop on blocks below
		if(control->isTouchingBlock())
			velocity = 0;
		else
			velocity -= 9.8/1000;
		m_y += velocity;
		
	}
	if(m_y <= -0.8 && !control->isAtPit())
	{
		velocity = 0;
		m_y = -0.8;
		isJumping = false;
	}
	
	
}



void Mario::makeMarioJump()
{
	//velocity needs to be related to the "gravity"
	//mario will always jump/fall at same rate due to games
	//tick speed
	velocity = 0.112f;
	isJumping = true;
}

void Mario::setYPosition(int pos)
{
	m_y = (pos/1000.0);
}

bool Mario::velocityIsNeg()
{
	if(velocity <= 0)
		return true;
	return false;
}

int Mario::getHeight()
{
	return 100;
}
