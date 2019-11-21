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
