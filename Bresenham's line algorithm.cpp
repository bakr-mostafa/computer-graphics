#include <glut.h> 
#include <math.h>
void setPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void display(int xa, int ya, int xb, int yb) {
	int dx = abs(xa - xb), dy = abs(ya - yb), twoDy = dy * 2, twoDyDx = 2 * (dy - dx);
	int p = 2 * dy - dx;
	int x, y, xEnd;
	if (xa > xb) {
		x = xb;
		y = yb;
		xEnd = xa;
	}
	else {
		x = xa;
		y = ya;
		xEnd = xb;
	}
	setPixel(x, y);
	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyDx;
		}
		setPixel(x, y);
	}
}
void d() {
	display(0, 0, 40, 60);
}
void main() {
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Line");
	gluOrtho2D(0, 200, 0, 200);
	glutDisplayFunc(d);
	glutMainLoop();
}
