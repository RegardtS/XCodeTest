//
//  Curve.cpp
//  TestGitProject
//
//  Created by Saint on 2014/04/01.
//  Copyright (c) 2014 Saint. All rights reserved.
//

#include "Curve.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <cmath>


#define PI 3.142
#define r1 .5
#define r2 .7

float cF = PI / 180.0;

double Curve::degreesToRadians(double degrees){
    return degrees * M_PI/180;
}
double Curve::dsin(double theta){
    return sin(degreesToRadians(theta));
}
double Curve::dcos(double theta){
    return cos(degreesToRadians(theta));
}


void Curve::drawCurve(float startAngle, float stopAngle) {
    // near surface
    glBegin(GL_QUAD_STRIP);
    for (float theta = startAngle; theta <= stopAngle; theta = theta + 1.0) {
        float thetaRad = theta * cF;
        glNormal3f(0, 0, 1);
        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), 0.5);
        glNormal3f(0, 0, 1);
        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0.5);
    }
    glEnd();
    // far surface
    glBegin(GL_QUAD_STRIP);
    for (float theta = startAngle; theta <= stopAngle; theta = theta + 1.0) {
        float thetaRad = theta * cF;
        glNormal3f(0, 0, -1);
        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), -0.5);
        glNormal3f(0, 0, -1);
        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), -0.5);
    }
    glEnd();
    // inner surface
    glBegin(GL_QUAD_STRIP);
    for (float theta = startAngle; theta <= stopAngle; theta = theta + 1.0) {
        float thetaRad = theta * cF;
        glNormal3f(-r1 * cos(thetaRad), -r1 * sin(thetaRad), 0);
        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), 0.5);
        glNormal3f(-r1 * cos(thetaRad), -r1 * sin(thetaRad), 0);
        glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), -0.5);
    }
    glEnd();
    // outer surface
    glBegin(GL_QUAD_STRIP);
    for (float theta = startAngle; theta <= stopAngle; theta = theta + 1.0) {
        float thetaRad = theta * cF;
        glNormal3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0);
        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0.5);
        glNormal3f(r2 * cos(thetaRad), r2 * sin(thetaRad), 0);
        glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), -0.5);
    }
    glEnd();
    // At start angle we need to create a polygon
    glBegin(GL_POLYGON);
    glVertex3f(r2 * cos(startAngle * cF), r2 * sin(startAngle * cF), 0.5);
    glVertex3f(r1 * cos(startAngle * cF), r1 * sin(startAngle * cF), 0.5);
    glVertex3f(r1 * cos(startAngle * cF), r1 * sin(startAngle * cF), -0.5);
    glVertex3f(r2 * cos(startAngle * cF), r2 * sin(startAngle * cF), -0.5);
    glEnd();
    // At stopAngle we need to create a polygon
    glBegin(GL_POLYGON);
    glNormal3f(r1 * cos(stopAngle * cF), r1 * sin(stopAngle * cF), 0);
    glVertex3f(r1 * cos(stopAngle * cF), r1 * sin(stopAngle * cF), 0.5);
    glNormal3f(r2 * cos(stopAngle * cF), r2 * sin(stopAngle * cF), 0);
    glVertex3f(r2 * cos(stopAngle * cF), r2 * sin(stopAngle * cF), 0.5);
    glNormal3f(r2 * cos(stopAngle * cF), r2 * sin(stopAngle * cF), 0);
    glVertex3f(r2 * cos(stopAngle * cF), r2 * sin(stopAngle * cF), -0.5);
    glNormal3f(r1 * cos(stopAngle * cF), r1 * sin(stopAngle * cF), 0);
    glVertex3f(r1 * cos(stopAngle * cF), r1 * sin(stopAngle * cF), -0.5);
    glEnd();
}