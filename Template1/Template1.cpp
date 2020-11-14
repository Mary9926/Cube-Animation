//cube
#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

float zDirection = -8.0;
float angle = 0.0;
float angleTip = 0;
float angleView = 0;

void DrawCube() {
	glBegin(GL_QUADS);
	//front red
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	//back green
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	//right blue
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//left yellow
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	//top cyan
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//bottom purple
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
}
void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, zDirection);
	glRotatef(angleTip, 1, 0, 0);  // Up and down arrow keys
	glRotatef(angleView, 0, 1, 0);  // Right/left arrow keys 
	//---------random rotation-------------------//
	/*glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);*/
	DrawCube();
	glutSwapBuffers();//swaps the buffers of the current window if double buffered
}
void Reshape(int width, int hight) {
	glViewport(0, 0,(GLsizei)width,(GLsizei)hight);
	glMatrixMode(GL_PROJECTION);//camera
	glLoadIdentity();
	gluPerspective(60, 1, 1.0, 60.0);
	/*field of view angle, in degrees, in the y direction. 
	The aspect ratio is the ratio of x (width) to y (height).
	distance from the viewer to the near clipping plane (always positive).
	distance from the viewer to the far clipping plane (always positive).*/
	glMatrixMode(GL_MODELVIEW); //moves the eye and objects
}

void Arrows(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:  angleView -= 3;  break;
		case GLUT_KEY_RIGHT:  angleView += 3;  break;
		case GLUT_KEY_UP:  angleTip -= 3;  break;
		case GLUT_KEY_DOWN:  angleTip += 3;  break;
	}
	glutPostRedisplay();
}

void Timer(int) 
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Timer, 0);
	angle += 1;
	if (angle > 360.0) 
	{
		angle = angle - 360.0;
	}
}

void MyInit() {
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glEnable(GL_DEPTH_TEST); // enable depht testing
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//Bit mask to select a window with a depth buffer.
	glutInitWindowSize(600, 600);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CUBE");//create widnow, hello title bar
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(Arrows);
	glutTimerFunc(0, Timer, 0);
	MyInit();
	glutMainLoop();//enter main loop and process events
	//return 0;
}