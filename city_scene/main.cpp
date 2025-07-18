
#include<windows.h>
#include <GL/gl.h>
#include<math.h>
#include <GL/freeglut.h>


void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glShadeModel(GL_SMOOTH);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // Using gluOrtho2D

    // Enable anti-aliasing
    //glEnable(GL_BLEND);
    //lBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void building(float positionX, float positionY, float width, float height, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(positionX, positionY);
        glVertex2f(positionX + width, positionY);
        glVertex2f(positionX + width, positionY + height);
        glVertex2f(positionX, positionY + height);
    glEnd();

    //windows
    glColor3f(0.9f,0.9f,0.75f);
    float winPositionX1 = positionX + 0.0175f;
    float winPositionY1 = positionY + 0.05f;
    float winWidth = 0.05f;
    float winHeight = 0.065f;

    for (int i = 0; i<3; i++){
        glBegin(GL_QUADS);
            glVertex2f(winPositionX1, winPositionY1);
            glVertex2f(winPositionX1 + winWidth, winPositionY1);
            glVertex2f(winPositionX1 + winWidth, winPositionY1 + winHeight);
            glVertex2f(winPositionX1, winPositionY1 + winHeight);
        glEnd();

        winPositionY1 += (winHeight + 0.035f);
    }



}

void road(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2f(0.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(1.0,0.2);
        glVertex2f(0.0,0.2);
    glEnd();

    //road divider
    glColor3f(1.0,1.0,1.0);
    float dividerWidth = 0.05f;
    float gap = 0.1f;
    float startY = 0.095f;
    for(float x = 0.025f; x<1.0f; x += dividerWidth + gap){
        glBegin(GL_QUADS);
            glVertex2f(x, startY - 0.003);
            glVertex2f(x + dividerWidth, startY - 0.003);
            glVertex2f(x + dividerWidth, startY + 0.003);
            glVertex2f(x, startY + 0.003);
        glEnd();
    }
}

void sidewalk(){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(0.0,0.2);
        glVertex2f(1.0,0.2);
        glVertex2f(1.0, 0.25);
        glVertex2f(0.0, 0.25);
    glEnd();
}

void sky(){
    glColor3f(0.698, 0.898, 1.0 );
    glBegin(GL_QUADS);
        glVertex2f(0.0, 0.25);
        glVertex2f(1.0, 0.25);
        glVertex2f(1.0, 1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
}

void lampLight(float lampPositionX, float r){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2f(lampPositionX, 0.25);
        glVertex2f(lampPositionX + 0.009, 0.25);
        glVertex2f(lampPositionX + 0.009, 0.25 + 0.24);
        glVertex2f(lampPositionX, 0.25 + 0.24);
    glEnd();

    glColor3f(1.0, 0.898, 0.6);
    int segments = 250;
    float theta = 2.0f * 3.1416f / segments;

    glBegin(GL_POLYGON);
    for(int i=0; i<segments; i++){
        float angle = i * theta;
        float x = lampPositionX  + r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(0.0045 + x, 0.49 + y);
    }
    glEnd();
}

void cloud(float cloudPositionX, float cloudPositionY, float r){
    glColor3f(1.0,1.0,1.0);
    int segments = 250;
    float theta = 2.0f * 3.1415f / segments;

    glBegin(GL_POLYGON);
    for(int i = 0; i<segments; i++){
        float angle = i * theta;
        float x = cloudPositionX + r * cos(angle);
        float y = cloudPositionY + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i<segments; i++){
        float angle = i * theta;
        float x = cloudPositionX + 0.032+  0.85* r * cos(angle);
        float y = cloudPositionY - 0.0075 +  0.85 *r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i<segments; i++){
        float angle = i * theta;
        float x = cloudPositionX - 0.032+  0.85 * r * cos(angle);
        float y = cloudPositionY - 0.0075 +  0.85 * r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void sun(){
    glColor3f(1.0, 0.6, 0.0);
    float segments = 250;
    float theta = 2.0f * 3.1416f / segments;
    float sunPositionX = 0.85;
    float sunPositionY = 0.85;
    float r = 0.06;

    glBegin(GL_POLYGON);
    for(int i=0; i<segments; i++){
        float angle = i * theta;
        float x = sunPositionX + r * cos(angle);
        float y = sunPositionY + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void bird(float birdPositionX, float birdPositionY){
    glColor3f(0.0,0.0,0.0);
            glBegin(GL_LINES);
                glVertex2f(birdPositionX, birdPositionY);
                glVertex2f(birdPositionX+ 0.011, birdPositionY + 0.015);
            glEnd();

            glBegin(GL_LINES);
                glVertex2f(birdPositionX + 0.011 , birdPositionY + 0.015);
                glVertex2f(birdPositionX + 0.011 * 2, birdPositionY );
            glEnd();
            glBegin(GL_LINES);
                glVertex2f(birdPositionX + 0.011 *2, birdPositionY);
                glVertex2f(birdPositionX+ 0.011 * 3, birdPositionY + 0.015);
            glEnd();

            glBegin(GL_LINES);
                glVertex2f(birdPositionX + 0.011 * 3 , birdPositionY + 0.015);
                glVertex2f(birdPositionX + 0.011 * 4, birdPositionY );
            glEnd();
}

void tree(float treePositionX, float r){
    glColor3f(0.4,0.25,0.1);
    glBegin(GL_QUADS);
        glVertex2f(treePositionX, 0.25);
        glVertex2f(treePositionX + 0.015, 0.25);
        glVertex2f(treePositionX + 0.015, 0.335);
        glVertex2f(treePositionX, 0.335);
    glEnd();

    glColor3f(0.25,0.867,0.07);
    int segments = 250;
    float theta = 2.0f * 3.1415f / segments;

    glBegin(GL_POLYGON);
    for(int i=0; i< segments; i++){
        float angle = i * theta;
        float x = treePositionX + r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(0.0075 + x, 0.35+ y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i<segments; i++){
        float angle = i * theta;
        float x = treePositionX + 0.04+  0.85* r * cos(angle);
        float y = 0.35 + 0.012 +  0.8 *r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i<segments; i++){
        float angle = i * theta;
        float x = treePositionX - 0.04+  0.8 * r * cos(angle);
        float y = 0.35 + 0.012 +  0.8 * r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    road();
    sidewalk();
    //calculation: x + building width + gap between building
    building(0.03, 0.25, 0.11, 0.4, 0.1,0.3,0.45);
    building(0.1575, 0.25, 0.085, 0.35, 0.2, 0.6, 0.4);
    // 0.1575+ 0.085 + 0.02 = 0.2625
    building(0.2625, 0.25, 0.085, 0.45, 0.4, 0.75, 0.75);
    // 0.2625 + 0.085 + 0.025 = 0.375
    building(0.375, 0.25, 0.085, 0.35, 0.7, 0.3, 0.2);
    // 0.375 + 0.085 + 0.02 = 0.4775 + 0.005
    building(0.4825, 0.25, 0.085, 0.38, 0.2, 0.2, 0.25);
    tree(0.12, 0.0425);
    tree(0.325, 0.0425);
    tree(0.5675, 0.0425);
    lampLight(0.14, 0.013);
    lampLight(0.4425, 0.013);
    cloud(0.2, 0.85, 0.03);
    cloud(0.45, 0.9, 0.03);
    sun();
    bird(0.135, 0.83);
    bird(0.065, 0.875);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutCreateWindow("City Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
