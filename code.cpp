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
