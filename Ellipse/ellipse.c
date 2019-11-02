/*
#include <stdio.h> 

void midptellipse(int rx, int ry, int xc, int yc) 
{ 

	float dx, dy, d1, d2, x, y; 
	x = 0; 
	y = ry; 

	// Initial decision parameter of region 1 
	d1 = (ry * ry) 
		- (rx * rx * ry) 
		+ (0.25 * rx * rx); 
	dx = 2 * ry * ry * x; 
	dy = 2 * rx * rx * y; 

	// For region 1 
	while (dx < dy) 
	{ 

		// Print points based on 4-way symmetry 
		printf("(%f, %f)\n", x + xc, y + yc); 
		printf("(%f, %f)\n", -x + xc, y + yc); 
		printf("(%f, %f)\n", x + xc, -y + yc); 
		printf("(%f, %f)\n", -x + xc, -y + yc); 

		// Checking and updating value of 
		// decision parameter based on algorithm 
		if (d1 < 0) { 
			x++; 
			dx = dx + (2 * ry * ry); 
			d1 = d1 + dx + (ry * ry); 
		} 
		else { 
			x++; 
			y--; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d1 = d1 + dx - dy + (ry * ry); 
		} 
	} 

	// Decision parameter of region 2 
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
		+ ((rx * rx) * ((y - 1) * (y - 1))) 
		- (rx * rx * ry * ry); 

	// Plotting points of region 2 
	while (y >= 0) { 

		// printing points based on 4-way symmetry 
		printf("(%f, %f)\n", x + xc, y + yc); 
		printf("(%f, %f)\n", -x + xc, y + yc); 
		printf("(%f, %f)\n", x + xc, -y + yc); 
		printf("(%f, %f)\n", -x + xc, -y + yc); 

		// Checking and updating parameter 
		// value based on algorithm 
		if (d2 > 0) { 
			y--; 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + (rx * rx) - dy; 
		} 
		else { 
			y--; 
			x++; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + dx - dy + (rx * rx); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	// To draw a ellipse of major and 
	// minor radius 15, 10 centred at (0, 0) 
	midptellipse(10, 10, 0, 0); 

	return 0; 
} 
*/

#include<stdio.h>
#include <gl/glut.h>
#include <math.h>

int rx = 4;
int ry = 2;
int xc = 0;
int yc = 0;
int X[100];
int Y[100];
int counter = 0;
int k;
int j;

void display()
{
	float dx, dy, d1, d2, x, y; 
	x = 0; 
	y = ry; 

	// Initial decision parameter of region 1 
	d1 = (ry * ry) 
		- (rx * rx * ry) 
		+ (0.25 * rx * rx); 
	dx = 2 * ry * ry * x; 
	dy = 2 * rx * rx * y; 

	// For region 1 
	while (dx < dy) 
	{ 
		
		
		printf("(%f, %f)\n", x + xc, y + yc); 
		printf("(%f, %f)\n", -x + xc, y + yc); 
		printf("(%f, %f)\n", x + xc, -y + yc); 
		printf("(%f, %f)\n", -x + xc, -y + yc); 

		// Checking and updating value of 
		// decision parameter based on algorithm 
		if (d1 < 0) { 
			x++; 
			dx = dx + (2 * ry * ry); 
			d1 = d1 + dx + (ry * ry); 
		} 
		else { 
			x++; 
			y--; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d1 = d1 + dx - dy + (ry * ry); 
		} 
	} 

	// Decision parameter of region 2 
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
		+ ((rx * rx) * ((y - 1) * (y - 1))) 
		- (rx * rx * ry * ry); 

	// Plotting points of region 2 
	while (y >= 0) 
	{ 
		printf("(%f, %f)\n", x + xc, y + yc); 
		printf("(%f, %f)\n", -x + xc, y + yc); 
		printf("(%f, %f)\n", x + xc, -y + yc); 
		printf("(%f, %f)\n", -x + xc, -y + yc); 

		// Checking and updating parameter 
		// value based on algorithm 
		if (d2 > 0) { 
			y--; 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + (rx * rx) - dy; 
		} 
		else { 
			y--; 
			x++; 
			dx = dx + (2 * ry * ry); 
			dy = dy - (2 * rx * rx); 
			d2 = d2 + dx - dy + (rx * rx); 
		} 
	} 
}

	void init() 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(-5, 5, -5, 5);
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Ellipse");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
