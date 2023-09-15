// Figure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GL/glut.h>
#include "Quad.h"


Quad* quad;

void Init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 600, 600, 0, -5, 5);
    quad = new Quad();
}

void Update(int) {
    glutPostRedisplay();
    quad->Update();//ÎÒÊËÞ×ÀÅÌ ÄËß ÏÐÎÂÅÐÊÈ ÏÅÐÅÌÅÙÅÍÈÉ
    glutTimerFunc(30, Update, 0);
}

void Render() {
    glClearColor(0.3f, 0.6f, 0.7f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    quad->Render();
    //glFlush();
    glutSwapBuffers();
}

void Keybord(unsigned char key, int x, int y) 
{
    switch (key)
    {
    case 'a': quad->rotateLeft(); break;
    case 'd': quad->rotateRight(); break;
    }  
}

void SpecialKeyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN: quad->moveDown(); break;
    case GLUT_KEY_UP: quad->moveUp(); break;
    case GLUT_KEY_LEFT: quad->moveLeft(); break;
    case GLUT_KEY_RIGHT: quad->moveRight(); break;
    }
}

void mouseMove(int ax, int ay) {
    //quad->setPos(ax, ay);
}

void mousePressed(int button, int state, int x, int y) {
    
    quad->setPos(x, y);
    switch (button)
    {
    case GLUT_LEFT_BUTTON: quad->setColorGreen(); break;
    case GLUT_RIGHT_BUTTON: quad->setColorRed(); break;
    default:
        break;
    }
}

void mousePressedMove(int ax, int ay) {
    //quad->setPos(ax, ay);
}

int main()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(Render);
    glutTimerFunc(100, Update, 0);
    glutKeyboardFunc(Keybord);
    glutSpecialFunc(SpecialKeyboard);
    glutMotionFunc(mousePressedMove);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mousePressed);
    Init();
    glutMainLoop();
    delete quad;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
