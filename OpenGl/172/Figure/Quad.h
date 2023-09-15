#pragma once
#include <GL/glut.h>

class Quad
{
public:
	Quad();
	~Quad();
	void Render();

private:
	int x;
	int y;
	int size;
};

