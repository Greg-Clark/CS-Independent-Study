//
//  main.cpp
//  Mario 1-1
//
//  Created by Gregory Clark on 10/11/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Objects.hpp"
#include "Controller.hpp"





#include <string>
#include <vector>

int main(int argc, char** argv){
	glutInit(&argc, argv);
	Controller* game = new Controller();
	game->run();
	delete game;
}


/*
 Notes on game
 
 Mario's hit boxes when returned from getX run from -50 to 50 meaning that his image is printed from -0.05 to 0.05.
 Mario's getY position when on the floor is at -0.8
 
 The hitbox on the pipe will correctly hit mario when moving right when the pipe's position is at 50. It will correctly be hit when moving left when its postion is at -249
 Pipe Hitbox for getY is at -0.8
 */
