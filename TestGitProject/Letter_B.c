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

void drawI(){
	//all the codes for the front side
	//front side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.9, 0.1);//1
    glVertex3f(-0.5, -0.9, 0.1);//2
    glVertex3f(-0.25, -0.9, 0.1);//3
    glVertex3f(-0.25, 0.9, 0.1);//4
	glEnd();
    
	
    
	//all the codes for the back side
	//back side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.9, -0.1);//1
    glVertex3f(-0.5, -0.9, -0.1);//2
    glVertex3f(-0.25, -0.9, -0.1);//3
    glVertex3f(-0.25, 0.9, -0.1);//4
	glEnd();
    
	
    
	//all the codes for the left side
	//Left side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.9, -0.1);//1
    glVertex3f(-0.5, -0.9, -0.1);//2
    glVertex3f(-0.5, -0.9, 0.1);//3
    glVertex3f(-0.5, 0.9, 0.1);//4
	glEnd();
    
	
    
	//Right side of all
    //right side side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.9, -0.1);//1
    glVertex3f(-0.25, -0.9, -0.1);//2
    glVertex3f(-0.25, -0.9, 0.1);//3
    glVertex3f(-0.25, 0.9, 0.1);//4
	glEnd();
    
	
    
	//all the codes for the top side
	//top side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.9, -0.1);//1
    glVertex3f(-0.5, 0.9, 0.1);//2
    glVertex3f(-0.25, 0.9, 0.1);//3
    glVertex3f(-0.25, 0.9, -0.1);//4
	glEnd();
    
	//all the codes for the bottom side
	//bottom side of k1
	glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.9, -0.1);//1
    glVertex3f(-0.5, -0.9, 0.1);//2
    glVertex3f(-0.25, -0.9, 0.1);//3
    glVertex3f(-0.25, -0.9, -0.1);//4
	glEnd();
    
	
}

void drawB(){
    glPushMatrix();
//        glTranslatef(0, 0.1, 0);
        glScalef(1.2,1.3,5.0);

        drawI();
	glPopMatrix();
	
	glPushMatrix();
        glTranslatef(-0.30,0.47, 0.0);
        glRotatef(180,0,1,0);
//    glScalef(1, 1, 3);

        drawCurve(90, 270);
        glTranslatef(0, -1, 0);
        drawCurve(90, 270);
    
	glPopMatrix();


}