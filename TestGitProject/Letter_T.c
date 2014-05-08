//
//  Letter_T.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/15.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_T.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>



void drawT(){
    glPushMatrix();
        glPushMatrix();
            glScalef(0.2, 2.5,1);
            glBegin(GL_POLYGON);
                glutSolidCube(1);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 1.2, 0);
            glScalef(2, 0.2, 1);
            glRotatef(90, 1, 0, 0);
            glBegin(GL_POLYGON);
                glutSolidCube(1);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}