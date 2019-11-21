//
//  Global Variables.hpp
//  Mario 1-1
//
//  Created by Gregory Clark on 11/6/19.
//  Copyright © 2019 Gregory Clark. All rights reserved.
//

#ifndef Global_Variables_hpp
#define Global_Variables_hpp

#include <vector>
#include "Objects.hpp"

class Object;

//these  variables should be put into controller.
//However will not compile if I try to put them in
//Also not sure why they have to be inline but will
//not work properly if not defined as inline
inline std::vector<Object*> obj;
inline bool keyBuffer[256];
inline int mariosVecPos;
inline float moveObjects = 0.05;
inline int flagPosition;

#endif /* Global_Variables_hpp */
