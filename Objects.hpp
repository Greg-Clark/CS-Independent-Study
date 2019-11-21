//
//  Objects.hpp
//  Mario 1-1
//
//  Created by Gregory Clark on 11/6/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#ifndef Objects_hpp
#define Objects_hpp

#include "Global Variables.hpp"
#include "Controller.hpp"


class Controller;

class Object
{
	//tried to make protected but for some reason this confuses
	//OpenGL and will not push objects in correct locations
protected:
	float m_x, m_y;
	Controller* control = nullptr;
public:
	Object(float Xpos, float Ypos, Controller *c) {
		m_x = Xpos;
		m_y = Ypos;
		control = c;
	}
	virtual void setYPosition(float pos) { }
	virtual void doSomething() = 0;
	virtual void move();
	virtual int getX();
	virtual int getY();
	virtual bool velocityIsNeg() { return false; }
	virtual ~Object() { }
};



class Block : public Object
{
protected:
	
public:
	Block(float Xpos, float Ypos, Controller *c) : Object(Xpos, Ypos, c) { }
	virtual void doSomething();
private:
	void drawBlock();
};




class Brick : public Object
{
public:
	Brick(float Xpos, float Ypos, Controller *c) : Object(Xpos, Ypos, c) { }
	virtual void doSomething();
private:
	void drawBrick();
};



class DarkBrick : public Object
{
	public:
		DarkBrick(float Xpos, float Ypos, Controller *c) : Object(Xpos, Ypos, c) { }
	virtual void doSomething();
	private:
	void drawDarkBrick();
};


class Pipe : public Object
{
public:
	Pipe(float Xpos, float Ypos, float length, Controller *c) : Object(Xpos, Ypos, c) {
		m_length = length;
	}
	virtual void doSomething();
private:
	void drawPipe();
	float m_length;
};



class Floor : public Object
{
protected:

public:
	Floor(float Xpos, float Ypos, float length, Controller *c) : Object(Xpos, Ypos, c) {
		m_length = length;
	}
	virtual void doSomething();
	
private:
	void drawFloor();
	float m_length;
};





class Mario : public Object
{
public:
	
	Mario(float Xpos, float Ypos, Controller *c) : Object(Xpos, Ypos, c) {
		control = c;
	}
	virtual void doSomething();
	virtual void move();
	
	virtual void setYPosition(float pos);
	
	virtual bool velocityIsNeg();
	
private:
	void drawMario();
	void makeMarioJump();
	float isJumping = false;
	float velocity = 0;
};



#endif /* Objects_hpp */
