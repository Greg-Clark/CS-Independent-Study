//
//  Controller.cpp
//  Mario 1-1
//
//  Created by Gregory Clark on 11/6/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Controller.hpp"
#include <iostream>


void Controller::run()
{
	glutInitWindowSize(1200, 1200);
	//glutInitWindowSize(1890, 1890); //used for monitor
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Mario");
	createObjects();
	glutDisplayFunc(display);
	glutSpecialFunc(keyPress);
	glutSpecialUpFunc(keyUpPress);
	glutMainLoop();
}

void Controller::createObjects()
{

	//loads in all the floors
	obj.push_back(new Floor(OGFloorX, OGFloorY, 6.9, this));
	obj.push_back(new Floor(OGFloorX+7.1, OGFloorY, 1.5, this));
	obj.push_back(new Floor(OGFloorX+8.9, OGFloorY, 6.4, this));
	obj.push_back(new Floor(OGFloorX+15.5, OGFloorY, 7.5, this));

	//loads in items in order of the level
	obj.push_back(new Block(OGBlock, squareHeight, this));

	obj.push_back(new Brick(OGBrick, squareHeight, this));
	obj.push_back(new Block(OGBlock+0.5, squareHeight, this));
	obj.push_back(new Brick(OGBrick+0.2, squareHeight, this));
	obj.push_back(new Block(OGBlock+0.7, squareHeight, this));
	obj.push_back(new Brick(OGBrick+0.4, squareHeight, this));

	obj.push_back(new Block(OGBlock+0.6, squareHeight+0.4, this));

	//start of all pipes. Pos: 11
	obj.push_back(new Pipe(OGPipeX, OGPipeY, OGPipeHeight, this));
	obj.push_back(new Pipe(OGPipeX+0.8, OGPipeY, OGPipeHeight*2, this));
	obj.push_back(new Pipe(OGPipeX+1.4, OGPipeY, OGPipeHeight*3, this));
	obj.push_back(new Pipe(OGPipeX+2.3, OGPipeY, OGPipeHeight*3, this));
	
	obj.push_back(new Pipe(OGBrick+14.2, OGPipeY, OGPipeHeight, this));
	
	obj.push_back(new Pipe(OGBrick+15.8, OGPipeY, OGPipeHeight, this));
	//end of all pipes. Pos: 16
	
	obj.push_back(new Brick(OGBrick+5.5, squareHeight, this));
	obj.push_back(new Block(OGBlock+6.0, squareHeight, this));
	obj.push_back(new Brick(OGBrick+5.7, squareHeight, this));

	//found it to make much more sense to just use OGBricks
	//from here on out. Too hard to keep track of all
	//individual object positions
	obj.push_back(new Brick(OGBrick+5.8, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+5.9, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.0, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.1, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.2, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.3, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.4, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.4, squareHeight+0.4, this));


	obj.push_back(new Brick(OGBrick+6.8, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+6.9, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+7.0, squareHeight+0.4, this));
	obj.push_back(new Block(OGBrick+7.1, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+7.2, squareHeight, this));

	obj.push_back(new Brick(OGBrick+7.8, squareHeight, this));
	obj.push_back(new Brick(OGBrick+7.9, squareHeight, this));

	obj.push_back(new Block(OGBrick+8.4, squareHeight, this));
	obj.push_back(new Block(OGBrick+8.7, squareHeight, this));
	obj.push_back(new Block(OGBrick+8.7, squareHeight+0.4, this));
	obj.push_back(new Block(OGBrick+9.0, squareHeight, this));

	obj.push_back(new Brick(OGBrick+9.6, squareHeight, this));

	obj.push_back(new Brick(OGBrick+9.9, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+10.0, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+10.1, squareHeight+0.4, this));

	obj.push_back(new Brick(OGBrick+10.6, squareHeight+0.4, this));
	obj.push_back(new Block(OGBrick+10.7, squareHeight+0.4, this));
	obj.push_back(new Block(OGBrick+10.8, squareHeight+0.4, this));
	obj.push_back(new Brick(OGBrick+10.9, squareHeight+0.4, this));

	obj.push_back(new Brick(OGBrick+10.7, squareHeight, this));
	obj.push_back(new Brick(OGBrick+10.8, squareHeight, this));

	//first pyramid
	drawPyramid(11.2, 4);

	//second pyramid
	drawMirrorPyramid(11.8, 4);

	//third pyramid
	drawPyramid(12.6, 4);
	drawColumn(13.0, 4);

	drawMirrorPyramid(13.3, 4);

	

	obj.push_back(new Brick(OGBrick+14.7, squareHeight, this));
	obj.push_back(new Brick(OGBrick+14.8, squareHeight, this));
	obj.push_back(new Block(OGBrick+14.9, squareHeight, this));
	obj.push_back(new Brick(OGBrick+15.0, squareHeight, this));

	

	drawPyramid(16.0, 8);
	drawColumn(16.8, 8);

	createFlag(17.7);


	drawCastle(18.9);

	obj.push_back(new Mario(0, -0.8, this)); //push mario on last so he is in front of everything
	mariosVecPos = (int)obj.size()-1;	//put this line next whenever a mario is created to know its position in vector
	
	//this is so that mario can be put behind one of the castle walls
	drawColumnBrick(18.9+0.3, 5);
	drawColumnBrick(18.9+0.4, 3);

	
}

void Controller::drawPyramid(float x, int height)
{
	float temp;
	
	for(int i = 1; i <= height; ++i)
	{
		temp = (i-1)/10.0f;
		drawColumn(x+temp, i);
	}
}

void Controller::drawMirrorPyramid(float x, int height)
{
	float temp;
	
	for(int i = height; i >= 0; --i)
	{
		temp = (height/10.0f) - (i/10.0f);
		drawColumn(x+temp, i);
	}
	
}

void Controller::drawColumn(float xPos, int height)
{
	float temp;
	for(int i = 0; i < height; ++i)
	{
		temp = (float)i/10.0f;
		obj.push_back(new DarkBrick(OGBrick + xPos, squareHeight-0.3+temp, this));
	}
}

void Controller::drawColumnBrick(float xPos, int height)
{
	float temp;
	for(int i = 0; i < height; ++i)
	{
		temp = (float)i/10.0f;
		obj.push_back(new Brick(OGBrick + xPos, squareHeight-0.3+temp, this));
	}
}

void Controller::drawCastle(float xPos)
{
	drawColumnBrick(xPos, 3);
	drawColumnBrick(xPos+0.1, 5);
	drawColumnBrick(xPos+0.3, 5);
	drawColumnBrick(xPos+0.4, 3);
	obj.push_back(new Brick(OGBrick+xPos+0.2, squareHeight, this));
	obj.push_back(new Brick(OGBrick+xPos+0.2, squareHeight+0.1, this));
	obj.push_back(new Brick(OGBrick+xPos+0.2, squareHeight+0.2, this));
}

void Controller::createFlag(float xPos)
{
	//drawColumn(xPos, 1); //create base of flag
	flagPosition = (int)obj.size();
	for(float i = -0.8f; i < 0.7; i += 0.1)
	{
		obj.push_back(new Floor(xPos+OGBrick+0.049, i, 0.01, this));
	}
	
	obj.push_back(new Brick(OGBrick+xPos, squareHeight+1.2, this));
	obj.push_back(new Brick(OGBrick+xPos-0.09, squareHeight+1.2, this));
}







void Controller::display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(animation)
	{
		if(obj[mariosVecPos]->getY() != -800)	//has mario climb down flag
		{
			obj[mariosVecPos]->move();
			obj[mariosVecPos]->doSomething();
			for(int i = 0; i < obj.size(); i++)
			{
				if(i != mariosVecPos)
				{
					obj[i]->doSomething();
				}
			}
		}
		else if(obj[obj.size()-1]->getX() > -25)	//have mario walk to castle
		{
			for(int i = 0; i < obj.size(); i++)
			{
				obj[i]->move();
				obj[i]->doSomething();
			}
		}
		else{
			for(int i = 0; i < obj.size(); i++)	//keeps everything displaying
			{
				scoreboard("You Win!", 0.0, 0.0);
				obj[i]->doSomething();
			}
		}
		glutPostRedisplay();
		glFlush();
		return;
	}
	
	if(obj[mariosVecPos]->getY() < -850)	//displays a game over message if mario falls in a pit
	{
		scoreboard("GAME OVER", 0, 0);
	}
	
	if(keyBuffer['z'])		//if z is pressed double speed(sprint)
	{
		if(obj[obj.size()-1]->getX() % 50 == 0)	//this protects mario on the 50 interval. If mario lands on a 25, 75 interval he can clip through walls
		{
			moveObjects = 0.05;
		}
		else
			moveObjects = 0.025;
	}
	else						//if nothing is pressed normal speed
		moveObjects = 0.025;
	
	
	//checks to see if mario is touching any of the objects
	for(int i = 0; i < flagPosition; ++i)
	{
		if((isTouching(obj[i], i) && i != mariosVecPos))
		{
			moveObjects = 0.0;	//if mario is touching an object then all
		}						//objects stop moving
	}
	//loops through all the objects and moves them accordingly
	for(int i = 0; i < obj.size(); ++i)
	{
		obj[i]->move();
		obj[i]->doSomething();
	}
	if(runAnimation())
		animation = true;
	glutPostRedisplay();
	glFlush();
}









void Controller::keyPress(int key, int x, int y)
{
	keyBuffer[key] = true;
}

void Controller::keyUpPress(int key, int x, int y)
{
	keyBuffer[key] = false;
}

//checks to see if any of the objects are touching mario
bool Controller::isTouching(Object* p, int i)
{
	if(keyBuffer['x'])	//allows to you go through all walls and get out of pits
		return false;
	if(obj[mariosVecPos]->getY() < -850) //causes mario to stop moving while in a pit
		return true;
	if(keyBuffer[GLUT_KEY_RIGHT])	//when mario comes from left side
	{
		if(p->getX() - 50 == 0
		   && ((obj[mariosVecPos]->getY() >= p->getY()
				&& obj[mariosVecPos]->getY() < p->getY() + p->getHeight())
			   || (obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() >= p->getY()
				   && obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() < p->getY() + p->getHeight())))
		{
			//std::cout << i << ", " << p->getX() << std::endl;
			return true;
		}
		else if(p->getX() - 49 == 0
				&& ((obj[mariosVecPos]->getY() >= p->getY()
					 && obj[mariosVecPos]->getY() < p->getY() + p->getHeight())
					|| (obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() >= p->getY()
						&& obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() < p->getY() + p->getHeight())))
		{
			//std::cout << i << ", " << p->getX() << std::endl;
			return true;
		}
	}
	if(keyBuffer[GLUT_KEY_LEFT])	//when mario comes from right side
	{
		if(p->getX() + p->getLength() + 49 == 0
		   && ((obj[mariosVecPos]->getY() >= p->getY()
				&& obj[mariosVecPos]->getY() < p->getY() + p->getHeight())
			   || (obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() >= p->getY()
				   && obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() < p->getY() + p->getHeight()))) //this is for the pipes
		{
			//std::cout << i << ", " << p->getX() << std::endl;
			return true;
		}
		else if(p->getX() + p->getLength() + 50 == 0
				&& ((obj[mariosVecPos]->getY() >= p->getY()
					 && obj[mariosVecPos]->getY() < p->getY() + p->getHeight())
					|| (obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() >= p->getY()
						&& obj[mariosVecPos]->getY() + obj[mariosVecPos]->getHeight() < p->getY() + p->getHeight()))) //this is for the pipes
		{
			//std::cout << i << ", " << p->getX() << std::endl;
			return true;
		}
	}
	return false;
}

//will have mario stop whenever he jumps on a block
bool Controller::isTouchingBlock()
{
	for(int i = 0; i < flagPosition; ++i)
	{
		if(i != mariosVecPos
		   && obj[mariosVecPos]->getY() > obj[i]->getY()
		   && obj[mariosVecPos]->getY() < obj[i]->getY()+obj[i]->getHeight()
		   && obj[i]->getX() > -obj[i]->getLength() - 49
		   && obj[i]->getX() < 49
		   && obj[mariosVecPos]->velocityIsNeg())
		{
			
			obj[mariosVecPos]->setYPosition((obj[i]->getY() + obj[i]->getHeight()));
			if(insideObject())
			{
				obj[mariosVecPos]->setYPosition(obj[mariosVecPos]->getY() + obj[i]->getHeight());
			}
			isOnBrick = true;
			return true;
		}
	}
	return false;
}

//Makes mario fall when not standing on any blocks
bool Controller::nothingBelow()
{
	isOnBrick = false;
	for(int i = 0; i < flagPosition; ++i)
	{
		if(i != mariosVecPos
		   && (obj[mariosVecPos]->getY() == obj[i]->getY() + obj[i]->getHeight())
		   && obj[i]->getX() > -obj[i]->getLength() - 49
		   && obj[i]->getX() < 49)
		{
			isOnBrick = true;
		}
	}
	return !isOnBrick;
}

bool Controller::bumpHead()
{
	for(int i = 0; i < flagPosition; ++i)
	{
		if(i != mariosVecPos
		   && obj[mariosVecPos]->getY() >= obj[i]->getY()-(2*obj[i]->getHeight())
		   && obj[mariosVecPos]->getY() <= obj[i]->getY()
		   && obj[i]->getX() > -obj[i]->getLength() - 49
		   && obj[i]->getX() < 49
		   &&  !(obj[mariosVecPos]->velocityIsNeg()))
		{
			//std::cout << i << ", " << obj[i]->getX() << ", " << obj[i]->getY() << std::endl;
			return true;
		}
	}
	
	return false;
}




//has mario move to the edge of the screen
bool Controller::isAtEdge()
{
	if(obj[0]->getX() >= (OGFloorX * 1000))	//obj[0] is the fisrt floor object
		return true;
	return false;
}

bool Controller::isAtPit()
{
	for(int i = 1; i <= 3; ++i)
	{
		if(obj[i]->getX() >= 0 && obj[i]->getX() <= 200)
		return true;
	}
	
	return false;
}

//runs an animation of mario running into castle.
//Is not implemented anywhere else. Should work
//it just needs to be called. Tricky part is
//running the animation
bool Controller::runAnimation()
{
	if(obj[flagPosition]->getX() <= 0)
		return true;
	return false;
}




bool Controller::insideObject()
{
	for(int i = 0 ; i < obj.size(); ++i)
	{
		if(i != mariosVecPos
		   && obj[mariosVecPos]->getY() == obj[i]->getY()
		   && obj[i]->getX() > -obj[i]->getLength() - 49
		   && obj[i]->getX() < 49)
		{
			return true;
		}
	}
	return false;
}

void Controller::scoreboard(std::string s,float x,float y)
{
	glColor3f(1, 1, 1);
	glRasterPos2f(x, y);

	for (int i = 0; i < s.length(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}


Controller::~Controller()
{
	for(int i = 0; i < obj.size(); ++i)
	{
		delete obj[i];
	}
	obj.erase(obj.begin(), obj.end());
}



