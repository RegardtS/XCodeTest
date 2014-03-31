//
//  Mouse.h
//  GLUT commandLine
//
//  Created by Saint on 2014/02/04.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#ifndef __GLUT_commandLine__Mouse__
#define __GLUT_commandLine__Mouse__

#include <iostream>



class Mouse {
public:
    static int currentX;
    static int currentY;
    
    static int lastX;
    static int lastY;
    
    static int deltaX;
    static int deltaY;
    
    static void move(int x,int y);
    static void update();
};




#endif /* defined(__GLUT_commandLine__Mouse__) */




