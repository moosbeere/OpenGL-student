#pragma once
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

class Quad
{
public:
	Quad();
	~Quad();
	void Update();
	void Render();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void rotateLeft();
	void rotateRight();
	void setPos(int _x, int _y);
	void setColorRed();
	void setColorGreen();
	void rotateForward();
	void rotateBackward();
private:
	float x;
	float y;
	float angleX, angleY, angleZ;
	int size;
	int screenSize;

	float speedX;
	float speedY;
	float speedZ;
	float rotateSpeed;

};

