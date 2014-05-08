//
//  Letter_S.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/01.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_S.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Curve.h"


void drawS(){
    glPushMatrix();
        glTranslatef(0,0.6, 0);
        drawCurve(0, 270);
        glTranslatef(0,-1.2, 0);
        glRotatef(180, 0, 1, 0);
        drawCurve(90, 360);
    glPopMatrix();
}