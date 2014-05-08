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


#include "Letter_S.h"
#include "Letter_R.h"
#include "Letter_T.h"
#include "Letter_M.h"
#include "Letter_F.h"
#include "Letter_B.h"
#include "Curve.h"








const int WINDOW_W = 1920;
const int WINDOW_H = 1080;


int x_y_display=0, y_z_display=0, x_z_display=0;


//for view control
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.3;

bool MousePressed; // Used in Mouse Drag to change the Viewpoint
float pitch0, yaw0;
int mouseX0, mouseY0;


bool flapFish = false;
bool flapFirst = false;
bool disco = false;
bool displayLines = true;
bool flapFin = false;
bool flapFinFirst = true;


float rotationAngle = 0;
float finRotation = 0;

int swimSpeed = 10;


void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (float) h / (float) w,
				2.0 * (float) h / (float) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (float) w / (float) h,
				2.0 * (float) w / (float) h, -2.0, 2.0, -10.0, 10.0);
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
void drawGrids(){
    float offset; int gd;
	glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(-20, 0, 0);
    glVertex3f(+20, 0, 0);
    glVertex3f( 0 ,-20, 0);
    glVertex3f(	0, +20, 0);
    glVertex3f( 0, 0,-20);
    glVertex3f(	0, 0, +20);
    
	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);
    
	glBegin(GL_LINES);
    
    if (x_y_display) {
        glColor3f(0.0,0.7,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}
    
    if (y_z_display) {
        glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);
			glVertex3f(	0, 10, offset);
		}}
    
    if (x_z_display) {
        glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);
			glVertex3f(	10, 0, offset);
		}}
    
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}








void keyboardDown(unsigned char key, int x,int y){
    if (key =='f') {
        flapFish = !flapFish;
    }
    if (key == 'F') {
        flapFirst = !flapFirst;
    }
    if (key == 'v') {
        flapFin = !flapFin;
    }
    if (key == '+') {
        G_zoom*=1.5;
    }
    if (key == '-') {
        G_zoom/=1.5;
    }
    if (key == 'd') {
        disco=!disco;
    }
    
    if (key == '1') {
        swimSpeed = 10;
    }
    
    if (key == '2') {
        swimSpeed = 100;
    }
    
    if (key == 'l') {
        displayLines = !displayLines;
    }
    
    
    glutPostRedisplay();
    
    
}









void drawBodyPiece(){
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        drawM();
        for (int i = 0; i != 3; i++) {
            glTranslatef(-0.5, 0, 0.5);
            glRotatef(90, 0, 1, 0);
            drawM();
        }
    glPopMatrix();
}


void randomColour(){
    glColor3f(arc4random()%255/255.0, arc4random()%255/255.0, arc4random()%255/255.0);
}

void viewControl(){
    glLoadIdentity();
    
	//Rotate everything
	glRotatef(G_theta[0], 1.0, 0.0, 0.0);
	glRotatef(G_theta[1], 0.0, 1.0, 0.0);
	glRotatef(G_theta[2], 0.0, 0.0, 1.0);
    
	//zoom (NB glOrtho projection)
	glScalef(G_zoom,G_zoom,G_zoom);
    
}

void drawEyes(){
    glPushMatrix();
        glTranslatef(-0.375, 0, -0.5);
        glRotatef(270, 0, 1, 0);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5, 0.5, 0.5);
        drawR();
        glTranslatef(0, 0, 1.5);
        drawR();
    glPopMatrix();
}

void drawTopFin(){
    glPushMatrix();
        glTranslatef(-0.3, 0, 0);
        glRotatef(90, 1, 0, 0);
        glRotatef(180, 0, 0, 1);
        glRotatef(finRotation, 0, 0, 1);
        glScalef(0.5, 0.5, 0.5);
        drawB();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.3, 0, 0);
        glRotatef(90, 1, 0, 0);
        glRotatef(-finRotation, 0, 0, 1);
        glScalef(0.5, 0.5, 0.5);
        drawB();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0, -1, 0);
        glRotatef(-45, 0, 0, 1);
        glRotatef(finRotation, 1, 0, 0);
        glScalef(0.5, 0.5, 0.5);
    glPopMatrix();
}

void drawBottomFin(){
    glPushMatrix();
        glTranslatef(0.5, 1, 0);
        glRotatef(90, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(0.5, 0.5, 0.5);
        drawS();
    glPopMatrix();
}


void drawBody(){
    glTranslatef(-0.5, 0, 0);
    drawBodyPiece();
    for (int i = 0; i != 4; i++) {
        if (i == 1) {
            if (disco) {
                randomColour();
            }else{
                glColor3f(0, 0, 1);
            }
            drawTopFin();
        }
        
        if (i == 2) {
            if (disco) {
                randomColour();
            }else{
                glColor3f(166/255.0, 0, 0);
            }
            
            drawBottomFin();
        }
        
        if (disco) {
            randomColour();
        }else{
            glColor3f(0, 133/255.0, 0);
        }
        
        
        glTranslatef(0, 0, 1);
        glRotatef(rotationAngle, 0, 1, 0);
        drawBodyPiece();
    }
}

void drawTail(){
    glPushMatrix();
        glTranslatef(0.5, 0.5, 1);
        glRotatef(-90, 0, 1, 0);
        glRotatef(-45, 0, 0, 1);
        drawF();
    glPopMatrix();
    
    
    if (disco) {
        randomColour();
    }else{
        glColor3f(230/255.0, 57/255.0, 155/255.0);
    }
    
    
    glPushMatrix();
        glTranslatef(0.5, -0.75, 0.75);
        glRotatef(-90, 0, 1, 0);
        glRotatef(-135, 0, 0, 1);
        glScalef(0.5, 0.5, 0.5);
        drawT();
    glPopMatrix();
}

void drawScene(){
    if (displayLines) {
        drawAxes();
    }
    drawGrids();
    
    if (disco) {
        randomColour();
    }else{
        glColor3f(159/255.0, 238/255.0, 0);
    }
    
    drawEyes();
    
    
    
    if (disco) {
        randomColour();
    }else{
        glColor3f(0, 133/255.0, 0);
    }
    
    
    drawBody();
    
    
    if (disco) {
        randomColour();
    }else{
        glColor3f(230/255.0, 57/255.0, 155/255.0);
    }
    drawTail();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(99/255.0, 173/255.0, 208/255.0, 1);
    
    viewControl();
    drawScene();

    glFlush();
    glutSwapBuffers();
}

static void Timer(int value){
    
    
    if (flapFish) {
        if (flapFirst) {
            rotationAngle++;
            if (rotationAngle == 10) {
                flapFirst = !flapFirst;
            }
        }else{
            rotationAngle--;
            if (rotationAngle == -10) {
                flapFirst = !flapFirst;
            }
        }
    }
    
    
    
   
    
    if (flapFin) {
        if (flapFinFirst) {
            finRotation+=2;
            if (finRotation == 20) {
                flapFinFirst = !flapFinFirst;
            }
        }else{
            finRotation-=2;
            if (finRotation == 0) {
                flapFinFirst = !flapFinFirst;
            }
        }
    }
    
    
    
    
    
    glutPostRedisplay();
    glutTimerFunc(swimSpeed, Timer, 0);
}

void mouseMotionCallBack(int x, int y)
{
	// Called when the Mouse is moved with left button down
	G_theta[0] = pitch0 + (y - mouseY0);
    G_theta[1] = yaw0 + (x - mouseX0);
	glutPostRedisplay();
}

void mouseClickCallBack(int button, int state, int x, int y)
{
	// Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			pitch0 = G_theta[0];
			yaw0 = G_theta[1];
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			break;
    }
}

int main(int argc, char ** argv){
    
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WINDOW_W,WINDOW_H);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA);
    glutCreateWindow("Shark - Graphics Project");
    glEnable(GL_DEPTH_TEST);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    glutKeyboardFunc(keyboardDown);


    
   
    glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
    
    
    Timer(0);
    
    
    glutMainLoop();
    
    return 0;
}
















































