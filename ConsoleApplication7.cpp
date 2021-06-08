#include<stdlib.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int moveh = 0;
int movev = 0;
bool R = true;
bool G = false;
bool Y = false;
int updater = 2000;
void specialkey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		movev++;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		movev--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		moveh--;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		moveh++;
		glutPostRedisplay();
		break;


	}
}
void myinit()
{
	glClearColor(0.0, 1.0, 0.0, 0.0); //rgb and alpha for transparency idhar green karlo
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10.0); //pt size in pixels //PUT 10 PX HERE
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-249, 249, -249, 249.0);

}
void road()
{
	glColor3f(0.2773, 0.2812, 0.2968);
	glBegin(GL_POLYGON);
	glVertex2f(-150, -249);
	glVertex2f(-150, 249);
	glVertex2f(150, 249);
	glVertex2f(150, -249);
	glEnd();
}
void middleline()
{

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(10);
	float y = -250;
	while (y <= 250)
	{
		glVertex2f(0, y);
		glVertex2f(0, y + 10);

		y = y + 20;

	}

	glEnd();
}
void footpath()
{

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-170, -249);
	glVertex2f(-170, 249);
	glVertex2f(-150, 249);
	glVertex2f(-150, -249);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(170, -249);
	glVertex2f(170, 249);
	glVertex2f(150, 249);
	glVertex2f(150, -249);
	glEnd();
}
void car()
{
	glPushMatrix();
	glTranslatef(moveh, movev, 0);
	//front hood
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -125);
	glVertex2f(-87.5, -105);
	glVertex2f(-62.5, -105);
	glVertex2f(-50, -125);
	glEnd();
	//front windsheild
	glColor3f(0.5273, 0.8078, 0.9216);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -125);
	glVertex2f(-93.75, -115);
	glVertex2f(-56.25, -115);
	glVertex2f(-50, -125);
	glEnd();
	//body
	glColor3f(1, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -200);
	glVertex2f(-100, -125);
	glVertex2f(-50, -125);
	glVertex2f(-50, -200);
	glEnd();
	//bodyend
	//back hood
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -200);
	glVertex2f(-87.5, -220);
	glVertex2f(-62.5, -220);
	glVertex2f(-50, -200);
	glEnd();
	//front windsheild
	glColor3f(0.5273, 0.8078, 0.9216);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -200);
	glVertex2f(-93.75, -210);
	glVertex2f(-56.25, -210);
	glVertex2f(-50, -200);
	glEnd();
	glPopMatrix();
	//cout << "\n" << movev;
	//glutPostRedisplay();


}
void update(int value)
{
	if (R)
	{
		cout << "\nIn Red Condition: " << R << " " << Y << " " << G << endl;
		//TO MAKE TO GREEN
		G = true;
		Y = false;
		R = false;
		updater = 1600;
		cout << "\nAfter exxec Red Condition: " << R << " " << Y << " " << G << endl;
		glutTimerFunc(updater, update, 0);
		return;

	}
	if (G)
	{
		cout << "\nIn green Condition: " << R << " " << Y << " " << G << endl;
		Y = true;
		G = false;
		R = false;
		updater = 400;
		cout << "\nAfter exxec green Condition: " << R << " " << Y << " " << G << endl;
		glutTimerFunc(updater, update, 0);

		return;

	}
	if (Y)
	{
		cout << "\nIn yellow Condition: " << R << " " << Y << " " << G << endl;
		R = true;
		G = false;
		Y = false;
		updater = 2000;
		cout << "\nafter exec yellow Condition: " << R << " " << Y << " " << G << endl;
		glutTimerFunc(updater, update, 0);

		return;

	}

	//glutPostRedisplay();
}
void signal()
{
	//plane signal stand
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-135, 120);
	glVertex2f(-135, 230);
	glVertex2f(-165,230);
	glVertex2f(-165, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-145, 90);
	glVertex2f(-145, 120);
	glVertex2f(-155, 120);
	glVertex2f(-155, 90);
	glEnd();
	//slots for colors
	glColor3f(0.515625, 0.40625
		, 0.4375);
	glBegin(GL_POLYGON);
	glVertex2f(-140, 125);
	glVertex2f(-140, 155);
	glVertex2f(-160, 155);
	glVertex2f(-160, 125);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-140, 160);
	glVertex2f(-140, 190);
	glVertex2f(-160, 190);
	glVertex2f(-160, 160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-140, 195);
	glVertex2f(-140, 225);
	glVertex2f(-160, 225);
	glVertex2f(-160, 195);
	glEnd();
	//colors
	if (R)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(-140, 195);
		glVertex2f(-140, 225);
		glVertex2f(-160, 225);
		glVertex2f(-160, 195);
		glEnd();
	}
	if (G)
	{
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(-140, 125);
		glVertex2f(-140, 155);
		glVertex2f(-160, 155);
		glVertex2f(-160, 125);
		glEnd();
	}
	if (Y)
	{
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(-140, 160);
		glVertex2f(-140, 190);
		glVertex2f(-160, 190);
		glVertex2f(-160, 160);
		glEnd();
	}
}
void conditions()
{
	if (-105 + movev > 90 && R) //WHERE 125 IS VET POSITION OF RED LIGHT
	{
		//red light jump condition
		cout << "\nRed Light Jump";
	}
	if (-50 + moveh > 0)
	{
		cout << "\nKeep Left";
	}
	if ((-100 + moveh < -150) || (-100 + moveh > 150))
	{
		cout << "\nDon't Jump Over FootPath";
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	footpath();
	middleline();
	signal();
	car();
	conditions();
	glFlush();
	glutPostRedisplay();
	//glutSwapBuffers();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Blank Window");
	glutSpecialFunc(specialkey);
	myinit();
	glutDisplayFunc(display);
	glutTimerFunc(updater, update, 0);
	glutMainLoop();
}
