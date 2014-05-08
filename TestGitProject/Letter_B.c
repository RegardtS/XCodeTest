//
//  Letter_B.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/17.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_B.h"



#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Curve.h"


void drawMainLineB(){
    glPushMatrix();
        glTranslatef(-0.25, 0, 0);
        glScalef(0.2,2.2,1);
        glBegin(GL_POLYGON);
            glutSolidCube(1);
        glEnd();
	glPopMatrix();
}

void drawCurveB(){
	glPushMatrix();
        glTranslatef(-0.30,0.47, 0.0);
        glRotatef(180,0,1,0);
        drawCurve(90, 270);
        glTranslatef(0, -1, 0);
        drawCurve(90, 270);
	glPopMatrix();
}


void drawB(){
	drawMainLineB();
    drawCurveB();
}