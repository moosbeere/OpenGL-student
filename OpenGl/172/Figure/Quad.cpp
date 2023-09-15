#include "Quad.h"

Quad::Quad()
{
	x = 0;
	y = 0;
	z = 0;
	size = 20;
	angleX = 0; angleY = 0; angleZ = 0;
	srand(time(0));
	speedX = rand() % 10;
	speedY = rand() % 10;
	speedZ = rand() % 10;
	rotateSpeed = rand() % 10;
}

Quad::~Quad()
{
	//
}

void Quad::Render()
{
	glTranslatef(x, y, 0);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleZ, 0, 0, 1);
	glBegin(GL_QUADS);

	//front
	glColor3f(0.5f, 0.3f, 0.8f);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);

	//right
	glColor3f(0.4f, 0.3f, 0.4f);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);

	//back
	glColor3f(0.4f, 0.3f, 0.4f);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);

	//top
	glColor3f(0.6f, 0.8f, 0.4f);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);

	//left
	glColor3f(0.6f, 0.3f, 0.4f);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);

	//bottom
	glColor3f(0.4f, 0.3f, 0.7f);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, -size, -size);
	glVertex3f(-size, -size, -size);
	glEnd();

	glRotatef(-angleZ, 0, 0, 1);
	glRotatef(-angleY, 0, 1, 0);
	glRotatef(-angleX, 1, 0, 0);
	glTranslatef(-x, -y, 0);
}

void Quad::Update()
{
	x += speedX;
	y += speedY;
	angleX += rotateSpeed;
	angleY += rotateSpeed;
	angleZ += rotateSpeed;

	if (angleZ > 360) angleZ = 0;
	if (angleX > 360) angleX = 0;
	if (angleY > 360) angleY = 0;

	if (z + size > 5 || z - size < -5)
		speedZ *= -1;
	if (x + size > 200 || x - size < -200)
		speedX *= -1;
	if (y + size > 200 || y - size < -200)
		speedY *= -1;
}

void Quad::moveUp()
{
	if(y+size < 200) y += 10;
}

void Quad::moveDown()
{
	if (y-size > -200) y -= 10;
}

void Quad::moveLeft()
{
	if (x - size > -200) x -= 10;
}

void Quad::moveRight()
{
	if (x+size < 200) x += 10;
}

void Quad::rotateLeft()
{
	angleX += 10;
}

void Quad::rotateRight()
{
	angleX -= 10;
}

void Quad::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Quad::setColorRed()
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void Quad::setColorGreen()
{
	glColor3f(0.0f, 1.0f, 0.0f);
}

void Quad::rotateForward()
{
	angleZ += 10;
}

void Quad::rotateBackward()
{
	angleZ -= 10;
}
