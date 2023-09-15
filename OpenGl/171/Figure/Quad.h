#pragma once
#include <GL/glut.h>

class Quad
{
public:
	Quad();
	~Quad();
	void Update();
	void Render();
private:
	float x;
	float y;
	int size;
};

