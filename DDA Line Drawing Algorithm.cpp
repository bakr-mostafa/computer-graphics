#include <glut.h> 
#include <math.h>
void setPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void display(int xa, int ya, int xb, int yb) {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	int dx = xb - xa, dy = yb - ya, steps, k;
	float xincrement, yincrement, x = xa, y = ya;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xincrement = dx / float(steps);
	yincrement = dy / float(steps);
	setPixel(x, y);
	for (k = 0; k < steps; k++) {
		x += xincrement;
		y += yincrement;
		setPixel(x, y);
	}
	glFlush();
}
void d() {
	display(0, 0, 40, 60);
}
void main() {
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Test");
	gluOrtho2D(0, 200, 0, 200);
	glutDisplayFunc(d);
	glutMainLoop();
}
