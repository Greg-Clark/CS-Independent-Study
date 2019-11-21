//
//  main.cpp
//  Mario 1-1
//
//  Created by Gregory Clark on 10/11/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

//#ifdef __APPLE__
///* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Objects.hpp"
#include "Controller.hpp"

//#else
//#include <GL/gl.h>
//#include <GL/glut.h>
//#endif

#include <string>
#include <vector>

int main(int argc, char** argv){
	glutInit(&argc, argv);
	Controller* game = new Controller();
	game->run();
	delete game;
}
