#pragma once
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

class Quad
{
public:
	Quad();
	~Quad();
	void Render();
	void Update();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void rotateLeft();
	void rotateRight();
	void setPos(int _x, int _y);
	void setColorRed();
	void setColorGreen();

private:
	float x;
	float y;
	float size;
	float angle;

	float speedX;
	float speedY;
	float rotateSpeed;

};

