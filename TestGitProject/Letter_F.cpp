//
//  Letter_F.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/17.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Letter_F.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


void Letter_F::drawF(){
    
    glPushMatrix();
	glScalef(0.2,1,1);
	glTranslatef(-2,0,0);
	glBegin(GL_POLYGON);
	glutSolidCube(1);
	glEnd();
	glPopMatrix();
    
	glPushMatrix();
	glTranslatef(-0.2,0.4,0);
	glScalef(0.5,0.2,1);
	glRotatef(90,0,0,1);
	glColor3f(80/255.0,80/255.0,80/255.0);
	glBegin(GL_POLYGON);
	glutSolidCube(1);
	glEnd();
	glPopMatrix();
	
    
	glPushMatrix();
	glTranslatef(-0.2,0,0);
	glScalef(0.5,0.2,1);
	glRotatef(90,0,0,1);
	glColor3f(80/255.0,80/255.0,80/255.0);
	glBegin(GL_POLYGON);
	glutSolidCube(1);
	glEnd();
	glPopMatrix();

}