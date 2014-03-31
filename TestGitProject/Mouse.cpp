  //
//  Mouse.cpp
//  GLUT commandLine
//
//  Created by Saint on 2014/02/04.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Mouse.h"

int Mouse::currentX = 0;
int Mouse::currentY = 0;
int Mouse::lastX = 0;
int Mouse::lastY = 0;
int Mouse::deltaX = 0;
int Mouse::deltaY = 0;


void Mouse::move(int x, int y){
    currentX = x;
    currentY = y;
}

 void Mouse::update(){

     deltaX = currentX - lastX;
     deltaY = currentY - lastY;
     
     lastX = currentX;
     lastY = currentY;
     
     
}