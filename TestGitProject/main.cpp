//
//  main.cpp
//  TestGitProject
//
//  Created by Saint on 2014/03/22.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#ifdef __APPLE__
#include "TargetConditionals.h"
#ifdef TARGET_OS_MAC
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#elif defined _WIN32 || defined _WIN64
#include <gl\glut.h>
#endif

#include <math.h>

#include <iostream>
#include <cmath>
#include "Mouse.h"

#import "Vector3f.h"

#include "Letter_S.h"
#include "Letter_R.h"
#include "Letter_T.h"
#include "Curve.h"




const int WINDOW_W = 1200;
const int WINDOW_H = 720;

const float MOUSE_SENSITIVITY = 1;
const float WALKING_SPEED = 1;
const float MAX_TILT = 85;

float LAST_TIME;
float CURRENT_TIME;
float DELTA_TIME;

int MOUSE_LAST_X;
int MOUSE_LAST_Y;
int MOUSE_CURRENT_X;
int MOUSE_CURRENT_Y;
int MOUSE_DELTA_X;
int MOUSE_DELTA_Y;



float artZ = 0.0;


Vector3f CAMERA_POSITION;
Vector3f CAMERA_ROTATION;


bool KEYS[256];








void reshape(int w, int h){
    if (h == 0){
        h = 1;
    }
    
    float ratio = (float) w / h;
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    glViewport(0,0, w, h);
    
    gluPerspective(45,ratio,0.01,1000);
    
    glMatrixMode(GL_MODELVIEW);
    
    
}

void drawAxes(){
    glColor3f(128/255.0, 128/255.0, 128/255.0); //nice gray color
    //x
    glBegin(GL_LINES);
    glVertex3f(-20, 0, 0);
    glVertex3f(20, 0, 0);
    glEnd();
    
    
    //y
    glBegin(GL_LINES);
    glVertex3f(0, -20, 0);
    glVertex3f(0, 20, 0);
    glEnd();
    
    
    //z
    glBegin(GL_LINES);
    glVertex3f(0, 0, -20);
    glVertex3f(0, 0, 20);
    glEnd();
    
    
}

void drawCube(){
    glBegin(GL_POLYGON);
    
    
    glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
    glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
    glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
    glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
    
    glEnd();
}

void drawO(){
    
    
    // float r1 = 0.5;
    // float r2 = 0.4;
    // float PI = 3.142;
    
    
//    glBegin(GL_QUAD_STRIP);
//    for (float theta = 0; theta <= 360; theta++) {
//        float thetaRad = theta * PI / 180;
//        glColor3f(0, 0, 1);
//        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), 0.5);
//        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), -0.5);
//    }
//    glEnd();
//    
//    glBegin(GL_QUAD_STRIP);
//    for (float theta = 0; theta <= 360; theta++) {
//        float thetaRad = theta * PI / 180;
//        glColor3f(1, 0, 0);
//        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0.5);
//        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), -0.5);
//    }
//    glEnd();
//    
//    
//    
//    glBegin(GL_QUAD_STRIP);
//    for (float theta = 0; theta <= 360; theta++) {
//        float thetaRad = theta * PI / 180;
//        glColor3f(0, 1, 0);
//        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0.5);
//        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), 0.5);
//    }
//    glEnd();
//    
//    glBegin(GL_QUAD_STRIP);
//    for (float theta = 0; theta <= 360; theta++) {
//        float thetaRad = theta * PI / 180;
//        glColor3f(1, 1, 0);
//        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), -0.5);
//        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), -0.5);
//    }
//    glEnd();
//    
//    
    
    
    
}








void keyboardDown(unsigned char key, int x,int y){
    KEYS[key] = true;
    
    
    // std::cout << key;
}

void keyboardUp(unsigned char key, int x,int y){
    KEYS[key] = false;
}


void preProcessEvents(){
    
    
    //UPDATE GLOBAL
    CURRENT_TIME = ((float) glutGet(GLUT_ELAPSED_TIME))/1000;
    DELTA_TIME = CURRENT_TIME - LAST_TIME;
    LAST_TIME = CURRENT_TIME;
    
    Mouse::update();
    
    
    //PROCESS MOUSE
    CAMERA_ROTATION.y += (float)Mouse::deltaX*MOUSE_SENSITIVITY;
    CAMERA_ROTATION.x += (float)Mouse::deltaY*MOUSE_SENSITIVITY;
    
    if (CAMERA_ROTATION.x > MAX_TILT) {
        CAMERA_ROTATION.x = MAX_TILT;
    }
    if (CAMERA_ROTATION.x < -MAX_TILT) {
        CAMERA_ROTATION.x = -MAX_TILT;
    }
    
    
    //PROCESS KEYS
    
    if (KEYS['w']) {
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME) * Curve::dsin(CAMERA_ROTATION.y);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME) * Curve::dcos(CAMERA_ROTATION.y);
    }
    if (KEYS['s']) {
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME) * Curve::dsin(CAMERA_ROTATION.y + 180);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME) * Curve::dcos(CAMERA_ROTATION.y + 180);
    }
    if (KEYS['a']) {
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME) * Curve::dsin(CAMERA_ROTATION.y + 270);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME) * Curve::dcos(CAMERA_ROTATION.y + 270);
    }
    if (KEYS['d']) {
        CAMERA_POSITION.x += (WALKING_SPEED*DELTA_TIME) * Curve::dsin(CAMERA_ROTATION.y + 90);
        CAMERA_POSITION.z += (WALKING_SPEED*DELTA_TIME) * Curve::dcos(CAMERA_ROTATION.y + 90);
    }

    if (KEYS[' ']) {
        CAMERA_POSITION.y += 0.01;
    }
    if (KEYS['z']){
        CAMERA_POSITION.y -= 0.01;
    }
    if (KEYS['1']) {
        artZ++;
    }
    if (KEYS['2']) {
        artZ--;
    }
}



void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen( string );
    
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

void drawTSR(){
    

        glColor3f(1, 64/255.0, 64/255.0);
    
    
    //S
    Letter_S::drawS();
    //R
    Letter_R::drawR();
    //T
    Letter_T::drawT();
    
    

   
    
    
    
}


void display(){
    preProcessEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    
    
    
    glTranslatef(-CAMERA_POSITION.x, -CAMERA_POSITION.y, CAMERA_POSITION.z);
    
    glRotatef(CAMERA_ROTATION.x, 1, 0, 0);
    glRotatef(CAMERA_ROTATION.y, 0, 1, 0);
    glRotatef(CAMERA_ROTATION.z, 0, 0, 1);
    
    drawAxes();
    
    //alt way to write text
    //    displayText(0, 0, 1, 0, 1, "Test");
    
    
    
    glScalef(0.1, 0.1, 0.1);
    
    glPushMatrix();
    drawTSR();
    
    //    glPushMatrix();
    //    glTranslatef(0, -2, 0);
    //    drawTSR();
    //    glPopMatrix();
    //
    //    glPopMatrix();
    
    
    
    
    //instance first cubes
    //        glPushMatrix();
    //            //glScalef(0.5, 0.5, 0.5);
    //            drawCube();
    //            //instance for articulated objects
    //            glPushMatrix();
    //                glTranslatef(0.5, 0.5,  0);
    //                glTranslatef(0.5, -0.5, 0);
    //                drawCube();
    //            glPopMatrix();
    //
    //            glTranslatef(0, 0, -1);
    //            drawCube();
    //
    //
    //        glPopMatrix();
    
    
    
    
    
    glFlush();
    glutSwapBuffers();
    
}






int main(int argc, char ** argv){
    
    //std::cout << "TESTER";
    
    CAMERA_POSITION.z = -1;
    
    //CAMERA_ROTATION.x = 10;
    //aCAMERA_ROTATION.y = 10;
    //    CAMERA_ROTATION.z = 10;
    
    
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WINDOW_W,WINDOW_H);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA);
    glutCreateWindow(" R S T");
    glEnable(GL_DEPTH_TEST);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutMotionFunc(Mouse::move);
    glutPassiveMotionFunc(Mouse::move);
    
    
    
    
    glutMainLoop();
    
    return 0;
}























