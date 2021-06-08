#include<stdlib.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int moveh = 0;
int movev = 0;
bool R = true;
bool G = false;
bool Y = false;
int times = 15000;
int updater = times;
int startflag = 0;
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
	case GLUT_KEY_HOME:
		startflag++;
		glutPostRedisplay();
	}
}
void output(float x, float y, float r, float g, float b, string input)
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = input.length();
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, input[i]);
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
		updater = 0.8*times;
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
		updater = 0.2*times;
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
		updater = times;
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
	glVertex2f(-165, 230);
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
	if (((-105 + movev > 90)&&(-105+movev < 210))&&R) //WHERE 125 IS VET POSITION OF RED LIGHT
	{
		//red light jump condition
		cout << "\nRed Light Jump";
		output(0, -245, 1, 1, 1, "Don't Jump Red Light");
	}
	if (-50 + moveh > 0)
	{
		cout << "\nKeep Left";
		output(-240, -245, 1, 1, 1, "Keep Left");

	}
	if ((-100 + moveh < -150) || (-100 + moveh > 150))
	{
		cout << "\nDon't Jump Over FootPath";
		output(-240, -245, 1, 1, 1, "Don't Run Over Footpath");

	}
}

void flash()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(-250,-250);
	glVertex2f(-250, -220);
	glVertex2f(250, -220);
	glVertex2f(259, -250);
	glEnd();
}
void display()
{
	if (startflag==0)
	{
		//startflag = true;
		glClearColor(0.0, 0.0, 0.0, 0.0); //rgb and alpha for transparency idhar green karlo
		glClear(GL_COLOR_BUFFER_BIT);
		string Project_Name = "OpenGL Project";
		float length = Project_Name.length();
		output(0-length*10/2,200, 1, 1, 1, Project_Name);

		string Project_Name2 = "Submitted By";
		float length2 = Project_Name2.length();
		output(0 - length2 * 10 / 2, 160, 1, 1, 1, Project_Name2);

		string Project_Name3 = "Gaurish Garg - 101803621";
		float length3 = Project_Name3.length();
		output(0 - length3 * 10 / 2, 120, 1, 1, 0, Project_Name3);

		string Project_Name4 = "Rishabh Malhotra - 101803615";
		float length4 = Project_Name4.length();
		output(0 - length4 * 10 / 2, 80, 1, 1, 0, Project_Name4);

		string Project_Name5 = "Submitted To";
		float length5 = Project_Name5.length();
		output(0 - length5 * 10 / 2, 40, 1, 1, 1, Project_Name5);

		string Project_Name6 = "Ms Kudratdeep Aulakh";
		float length6 = Project_Name6.length();
		output(0 - length6 * 10 / 2, 0, 1, 1, 0, Project_Name6);
		glFlush();

		string Project_Name7 = "Computer Science and Engineering Department";
		float length7 = Project_Name7.length();
		output(0 - length7 * 10 / 2, -40, 1, 1, 1, Project_Name7);

		string Project_Name8 = "TIET Patiala";
		float length8 = Project_Name8.length();
		output(0 - length8 * 10 / 2, -80, 1, 1, 1, Project_Name8);
		glFlush();
		//glutPostRedisplay();
	}
	if (startflag==1)
	{
		glClearColor(0.0, 1.0, 0.0, 0.0); //rgb and alpha for transparency idhar green karlo
		glClear(GL_COLOR_BUFFER_BIT);
		road();
		footpath();
		middleline();
		signal();
		car();
		flash();
		conditions();
		glFlush();
		glutPostRedisplay();
	}
	
	//glutSwapBuffers();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Traffic Signals");
	glutSpecialFunc(specialkey);
	myinit();
	glutDisplayFunc(display);
	glutTimerFunc(updater, update, 0);
	glutMainLoop();
}
