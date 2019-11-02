#include <stdio.h> 
#include <stdlib.h> 
#include<GL/glut.h>
#include<math.h>

float x, y, p1, p2;
int xc, yc, rx, ry;

void disp()
{
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POINTS); 
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc + y);   
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-10, 10, -10, 10);
	x = 0;
	y = ry;
	disp();
	p1 = (ry * ry) - (rx * rx * rx) + (rx * rx) / 4;
	while((2.0 * ry * ry * x) <= (2.0 * rx * rx * y))
	{
		x++;
		if(p1 <= 0)
		{
			p1 = p1 + (2.0 * ry * ry * x) + (ry * ry);
		}
		else
		{
			y--;
			p1 = p1 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (ry * ry);
		}
		disp();
		x =- x;
		disp();
		x =-x;
	}
	
	x = rx;
	y = 0;
	disp();
	p2  = (rx * rx) + 2.0 * (ry * ry * rx) + (ry * ry) / 4;
	while((2.0 * ry * ry * x) > (2.0 * rx * rx * y))
	{
		y++;
		if(p2 > 0)
		{
			p2 = p2 + (rx * rx) - (2.0 * rx * rx * y);
		}	
		else
		{
			x--;
			p2 = p2 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
		}
		disp();
		y =- y;
		disp();
		y =- y;
	}
}

int main(int argc , char**argv)		//used to initialize glut library
{
	glutInit(&argc, argv);	//initializing glut library
	printf("Enter the center point of the ellipse ");
	scanf("%f %f", &xc, &yc);
	printf("Enter the value of radius x, radius y");
	scanf("%d %d", &rx, &ry);
	
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);	//initializing view mode
	glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);
	glutCreateWindow("Window 1");
	glutDisplayFunc(display);
	glutMainLoop();
}
