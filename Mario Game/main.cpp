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
 next 3 pipes in the level will hit mario when at 49 when mario is moving right. When mario is moving left will hit at -250. I beleive that this inconsistancy could be due to floating point comparison errors.
 
 When trying to hit bricks/blocks from the left their getX needs to return 50, when trying to hit from the right their getX needs to return -149
 
 Game has some underlying bugs that happen only some of the time
	-When pressing z to sprint it has a 50% chance to be on 25 to 75 interval instead of a 00 to 50 interval. The issue in this is that all hit detection for walls rely on 00 to 50 interval meaning that mario will go straight through walls. The likely fix to this would be to put a range area for the wall detection but this also causes the issue of mario not being able to jump if he hits a wall on a 25 to 75 interval. Because of this fact, fixing this small issue turns out to be massive headache. When releasing the z button wall detection works perfectly fine due to moving on a 00 to 25 to 50 to 75 interval
	-Second issue is that when jumping around on the pyramids mario very frequently can clip through the top most brick layer causing him to land of a secondary brick below the top most brick. This causes an issue since now he is technically inside of a brick which will cause the game to constantly think he is under something making him unable to jump. After looking at this issue for a considerable amount of time I still have not clue as to why he is able to clip through especially since this issue does not occur every single time. It only occurs some of the time. It also tends to happen more often when neither the left or right keys are being pressed. Can still occur when one of those keys are pressed but only happens rarely in this case. Also not sure why it occurs more frequently with no arrow keys being pressed.
 */
