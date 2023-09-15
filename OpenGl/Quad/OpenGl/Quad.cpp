#include "Quad.h"

Quad::Quad()
{
	x = 0;
	y = 0;
	size = 20;
}

Quad::~Quad()
{
	//
}

void Quad::Render()
{
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.3f, 0.8f);
	glVertex3f(-size, size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(size, -size, 0);
	glVertex3f(-size, -size, 0);
	glEnd();
}
