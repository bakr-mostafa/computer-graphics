#include <glut.h>
float p1 = 0, p2 = 0, p3x = 0, p3y = 200, p4x = 0, p4y = 200, deltaP1 = 0.1, deltaP2 = 0.02, deltaP3 = 0.1, deltaP4 = 0.02;
void display() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(8);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5 , 1);
	glVertex2f(p1, p1);
	glColor3f(0.5, 1, 0.5);
	glVertex2f(p2, p2);
	glColor3f(0.5, 0.5, 1);
	glVertex2f(p3x, p3y);
	glColor3f(0.5, 1, 0.5);
	glVertex2f(p4x, p4y);
	glEnd();
	glFlush();

	p1 += deltaP1;
	if (p1 > 200 || p1 < 0)
		deltaP1 = -deltaP1;
	p2 += deltaP2;
	if (p2 > 200 || p2 < 0)
		deltaP2 = -deltaP2;
	p3x += deltaP3;
	p3y -= deltaP3;
	if (p3x > 200 || p3x < 0 || p3y > 200 || p3y < 0)
		deltaP3 = -deltaP3;
	p4x += deltaP4;
	p4y -= deltaP4;
	if (p4x > 200 || p4x < 0 || p4y > 200 || p4y < 0)
		deltaP4 = -deltaP4;
	glutPostRedisplay();
}
void main() {
	glutInitWindowPosition(500, 250);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Digonal Points");
	gluOrtho2D(0, 200, 0, 200);
	glutDisplayFunc(display);
	glutMainLoop();
}
