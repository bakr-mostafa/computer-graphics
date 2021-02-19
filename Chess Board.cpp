#include <glut.h>
void display() {
	bool c = 0;
	for (int y = 0; y <= 400; y += 50) {
		for (int x = 0; x <= 400; x += 50) {
			glBegin(GL_POLYGON);
			glColor3f(c, c, c);
			glVertex2f(0 + x, 0 + y);
			glVertex2f(50 + x, 0 + y);
			glVertex2f(50 + x, 50 + y);
			glVertex2f(0 + x, 50 + y);
			glEnd();
			c = !c;
		}
	}
	glFlush();
}
void main() {
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Chess Board");
	gluOrtho2D(0, 400, 0, 400);
	glutDisplayFunc(display);
	glutMainLoop();
}
