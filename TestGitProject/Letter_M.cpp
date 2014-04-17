//
//  Letter M.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/17.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_M.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


void Letter_M::drawM(){
    
    glPushMatrix();
        glScalef(0.2,1,0.3);
        glTranslatef(-2,0,0);
        glBegin(GL_POLYGON);
            glutSolidCube(1);
        glEnd();
        glTranslatef(4,0,0);
        glBegin(GL_POLYGON);
            glutSolidCube(1);
        glEnd();
	glPopMatrix();
    
	glPushMatrix();
        glTranslatef(-0.17,0.17,0);
        glRotatef(45,0,0,1);
        glScalef(0.2,0.7,0.3);
    
        glBegin(GL_POLYGON);
            glutSolidCube(1);
        glEnd();
    
        glPopMatrix();
    
    glPushMatrix();
    
        glTranslatef(0.17,0.17,0);
        glRotatef(-45,0,0,1);
        glScalef(0.2,0.7,0.3);
    
        glBegin(GL_POLYGON);
            glutSolidCube(1);
        glEnd();
	glPopMatrix();
}