//
//  Letter_R.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/08.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_R.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "Curve.h"


void Letter_R::drawR(){
    glPushMatrix();
        glRotatef(180, 0, 1, 0);
    
        glPushMatrix();
            glScalef(0.2, 2.5,1);
            glBegin(GL_POLYGON);
                glutSolidCube(1);
            glEnd();
        glPopMatrix();
    
        glPushMatrix();
            glTranslatef(-0.4, 0.5, 0);
            glRotatef(-45, 0, 0, 1);
            Curve::drawCurve(90, 360);
        glPopMatrix();
    
        glPushMatrix();
            glTranslatef(-0.5, -0.6, 0);
            glRotatef(-40, 0, 0, 1);
            glScalef(0.2, 1.5,1);
            glBegin(GL_POLYGON);
                glutSolidCube(1);
            glEnd();
        glPopMatrix();
    
    glPopMatrix();

}