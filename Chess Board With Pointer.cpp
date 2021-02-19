#include <glut.h>
#include <stdlib.h>
float p1 = 25, p2 = 25;
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
	glPointSize(50);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0.1);
	glVertex2f(p1, p2);
	glEnd();
	glFlush();
	glutPostRedisplay();
}
void move_up() {
	if (p2 < 350)
		p2 += 50;
}
void move_down() {
	if (p2 > 50)
		p2 -= 50;
}
void move_left() {
	if (p1 > 50)
		p1 -= 50;
}
void move_right() {
	if (p1 < 350)
		p1 += 50;
}
void keyboard(int key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case GLUT_KEY_UP:
		move_up();
		break;
	case GLUT_KEY_DOWN:
		move_down();
		break;
	case GLUT_KEY_LEFT:
		move_left();
		break;
	case GLUT_KEY_RIGHT:
		move_right();
		break;
	}
	glutPostRedisplay();
}
void main() {
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Chess Board");
	gluOrtho2D(0, 400, 0, 400);
	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}
