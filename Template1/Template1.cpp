//cube

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

float zDirection = -8.0;
int state = 1;

void MyDisplay() {
	
	// The new scene
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, zDirection);
	glBegin(GL_QUADS);

	//front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	//back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	//right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);	
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//left
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	//top
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//bottom
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
	glutSwapBuffers();


}
void Reshape(int w, int h) {
	glViewport(0, 0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}
void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Timer, 0);
	/*switch (state)
	{
	case 1:
		if (x_position < -5)
			x_position += 0.30;
		else
			state = -1;
			break;
	case -1:
		if (x_position > -15)
			x_position -= 0.30;
		else
			state = 1;
			break;

	}*/

}

void MyInit() {
	glClearColor(0.0, 0.0, 0.0, 1.0); 
}




int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CUBE");//create widnow, hello title bar
	
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	glutTimerFunc(0, Timer, 0);
	MyInit();
	glutMainLoop();//enter main loop and process events
	//return 0;
}