//
//  Controller.hpp
//  Mario 1-1
//
//  Created by Gregory Clark on 11/6/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "Objects.hpp"
#include <vector>
#include "Global Variables.hpp"



class Controller
{
public:
	
	Controller() { }
	void run();
	void createObjects();
	
	void drawPyramid(float x, int height);
	
	void drawMirrorPyramid(float x, int height);
	
	void drawColumn(float xPos, int height);
	
	void drawColumnBrick(float xPos, int height);
	
	void drawCastle(float xPos);
	
	void createFlag(float xPos);

	
	static void display();
	
	static void keyPress(int key, int x, int y);
	
	static void keyUpPress(int key, int x, int y);
	
	static bool isTouching(Object* p, int i);

	
	//checks to see if mario is touching something while he is jumping
	bool isTouchingBlock();
	bool nothingBelow();
	bool bumpHead();
	
	bool isAtEdge();
	bool isAtPit();
	
	static bool runAnimation();
	
	bool insideObject();
	
	~Controller();
	
	
	
private:
	
	
	
	int m_WindowX;
	int m_WindowY;
	char* m_WindowName;
	int  m_windowPosX;
	int m_windowPosY;
	float squareHeight = -0.5f;
	float OGBlock = 0.8;
	float OGBrick = OGBlock + 0.4; //1.2
	float OGPipeX = OGBlock + 1.2; //2.0
	float OGPipeHeight = 0.2;
	float OGPipeY = -0.8;
	float OGFloorX = -1;
	float OGFloorY = -1;
	bool isOnBrick = false;
	
};



#endif /* Controller_hpp */
