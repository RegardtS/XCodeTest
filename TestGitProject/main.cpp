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


//for view control
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.3;

bool MousePressed; // Used in Mouse Drag to change the Viewpoint
float pitch0, yaw0;
int mouseX0, mouseY0;


bool flapFish = false;
bool flapFirst = false;


float rotationAngle = 0;
float finRotation = 0;




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

void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen( string );
    
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

void drawAxes(){
//    glColor3f(128/255.0, 128/255.0, 128/255.0); //nice gray color
    
    //x
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-20, 0, 0);
    glVertex3f(20, 0, 0);
    glEnd();
    
    
    //y
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(0, -20, 0);
    glVertex3f(0, 20, 0);
    glEnd();
    
    
    //z
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, -20);
    glVertex3f(0, 0, 20);
    glEnd();
    
    
    //alt way to write text
    displayText(0.5, 0, 1, 0, 0, "X");
    displayText(-0.5, 0, 1, 0, 0, "X");
    
    displayText(0,0.5, 0, 1,0, "Y");
    displayText(0,-0.5, 0,1, 0, "Y");
    
}









void keyboardDown(unsigned char key, int x,int y){
    if (key =='f') {
        flapFish = !flapFish;
    }
    if (key == 'F') {
        flapFirst = !flapFirst;
    }
    if (key == 'v') {
        finRotation+=10;
    }
    if (key == '+') {
        G_zoom*=1.5;
    }
    if (key == '-') {
        G_zoom/=1.5;
    }
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




void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(99/255.0, 173/255.0, 208/255.0, 1);
    glLoadIdentity();
    
    
	//Rotate everything
	glRotatef(G_theta[0], 1.0, 0.0, 0.0);
	glRotatef(G_theta[1], 0.0, 1.0, 0.0);
	glRotatef(G_theta[2], 0.0, 0.0, 1.0);
    
	//zoom (NB glOrtho projection)
	glScalef(G_zoom,G_zoom,G_zoom);
    
   
    
    drawAxes();
    

    
    
    
    
    
    
    //DRAWS THE EYES WITH THE LETTER R
    glPushMatrix();
        glTranslatef(-0.375, 0, -0.5);
        glRotatef(270, 0, 1, 0);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5, 0.5, 0.5);
        drawR();
        glTranslatef(0, 0, 1.5);
        drawR();
    glPopMatrix();

    
    
    
    glColor3f(1, 0, 0);
    glTranslatef(-0.5, 0, 0);
    drawBodyPiece();
    
    for (int i = 0; i != 4; i++) {
        
        if (i == 1) {
            //LETTER B FIN
            glPushMatrix();
                glColor3f(0, 0, 1);
                glTranslatef(0.5, 1.2, 0);
                glRotatef(90, 0, 1, 0);
                glRotatef(180, 0, 0, 1);
            
                glScalef(0.5, 0.5, 0.5);
                drawB();
            glPopMatrix();
            
            
            
            
            
            //LETTER S FIN
            glPushMatrix();
                glTranslatef(0, -1, 0);
                glRotatef(-45, 0, 0, 1);
            
                glRotatef(finRotation, 1, 0, 0);
            
                glScalef(0.5, 0.5, 0.5);
            
            
            
               drawS();
            
            
            
//            glTranslatef(0, 0, -2);
//            glRotatef(90, 1, 0, 0);
//            glColor3f(1, 0, 0);
            //        Letter_S::drawS();
            
            glPopMatrix();
        }
        
        
        glColor3f(1, 0, 0);
        
        glTranslatef(0, 0, 1);
        glRotatef(rotationAngle, 0, 1, 0);
        drawBodyPiece();
        
    }
    
    glColor3f(1, 1, 0);
    
    glPushMatrix();
        glTranslatef(0.5, 0.5, 1);
        glRotatef(-90, 0, 1, 0);
        glRotatef(-45, 0, 0, 1);
        drawF();
    glPopMatrix();
    
    
    glColor3f(1, 1, 1);
    glPushMatrix();
        glTranslatef(0.5, -1, 0.75);
        glRotatef(-90, 0, 1, 0);
        glRotatef(-135, 0, 0, 1);
        glScalef(0.5, 0.5, 0.5);
        drawT();
    glPopMatrix();
    
    
    
    
    
    

//    
//     //DRAWS THE BACK FIN WITH THE LETTER F
//    glPushMatrix();
//        glTranslatef(1, 2, 0.5);
//        glRotatef(90, 0, 0, 1);
////        glScalef(0.5, 0.5, 0.5);
//        Letter_F::drawF();
//    glPopMatrix();
//    
//    
//    
//    
//    
//    
//    
//    glPopMatrix();
    
    

    
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
    
    
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
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
    
    //CAMERA_POSITION.z = -1;
    
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

   
    glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
    
    
    Timer(0);
    
    
    glutMainLoop();
    
    return 0;
}
















































