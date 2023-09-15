#include "Quad.h"


Quad::Quad()
{
	x = 0;
	y = 0;
	angleX = 0; angleY = 0; angleZ = 0;
	speedX = 0; speedY = 0; speedZ = 0;
	size = 20;
	srand(time(0));
	speedX = rand() % 10;
	speedY = rand() % 10;
	rotateSpeed = rand() % 10;
	loadTexture();
}

Quad::~Quad()
{
}

void Quad::Update()
{
	/*x += speedX;
	y += speedY;
	
	angleX += rotateSpeed;
	angleY += rotateSpeed;
	angleZ += rotateSpeed;

	if (angleX > 360) angleX = 0;
	if (angleY > 360) angleY = 0;
	if (angleZ > 360) angleZ = 0;

	if (x + size > 100 || x - size < -100)
		speedX *= -1;
	if (y + size > 100 || y - size < -100)
		speedY *= -1;

	x += speedX;
	y += speedY;

	if (x + size > 200 || x - size < -200)
		speedX *= -1;
	if (y + size > 200 || y - size < -200)
		speedY *= -1;

	*/
}

void Quad::Render()
{
	glTranslatef(x, y, 0);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleZ, 0, 0, 1);

	
	//front
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.2f, 0.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, -size);
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(size, size, -size);
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(size, -size, -size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -size);

	//left
	glColor3f(0.4f, 0.5f, 0.6f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, -size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, size);


	//back	
	glColor3f(0.7f, 0.8f, 0.9f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, size);
	
	//right
	
	glColor3f(0.1f, 0.8f, 0.9f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -size);


	//button
	
	glColor3f(0.1f, 0.5f, 0.6f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, -size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -size, -size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, size);


	//top
	
	glColor3f(0.5f, 0.3f, 0.6f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, -size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, -size);
	glEnd();

	glRotatef(-angleZ, 0, 0, 1);//возвращаем объект обратно
	glRotatef(-angleY, 0, 1, 0);
	glRotatef(-angleX, 1, 0, 0);
	glTranslatef(-x, -y, 0);
}


void Quad::moveUp()
{
	if (y + size < 200)
		y += 10;
}

void Quad::moveDown()
{
	if (y - size > -200)
		y -= 10;
}

void Quad::moveRight()
{
	if (x + size < 200)
		x += 10;
}

void Quad::moveLeft()
{
	if (x - size > -200)
		x -= 10;
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

void Quad::loadTexture()
{
	AUX_RGBImageRec* tex;
	tex = auxDIBImageLoadA("text.bmp");
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		tex->sizeX, tex->sizeY, 0, GL_RGB, 
		GL_UNSIGNED_BYTE, tex->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}



