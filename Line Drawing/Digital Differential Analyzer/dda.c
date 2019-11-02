#include<stdio.h>
#include<math.h>
#include <gl/glut.h>

float x1, x2, yy1, y2;
	
//function for initializing glut
void myInit() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-20, 20, -20, 20);
	
}

//function for drawing the line
void draw_line(float x1[100], float y1[100], int counter)
{
	int x, y;
	glClear(GL_COLOR_BUFFER_BIT); //clearing the frame buffer
	glBegin(GL_LINES);					
	for(x = -20; x <= 20; x++)
	{
		glColor3f(1.00, 1.00, 1.00);
		glVertex2i(x, 20);
		glVertex2i(x, -20);		
	}
	for(y = -20; y <= 20; y++)
	{
		glVertex2i(20, y);
		glVertex2i(-20, y);		
	}
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.00, 0.00, 0.00);
		glVertex2i(x1[0], y1[0]);	
		glVertex2i(x1[counter-1], y1[counter-1]);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(0.00, 0.00, 1.00);
	for(x = 0; x < counter - 1; x++)
	{
		y = x + 1;
		glVertex2i(x1[x], y1[x]);	
		glVertex2i(x1[y], y1[y]);
	}
	glEnd();

}

// function for creating the slope of the line 
float slope(float x1, float x2, float y1, float y2)
{
	return (y2 - y1)/(x2 - x1);
}

// function for rounding of the value of Y in case of m < 1
int calculateY(float y)
{
	int result = round(y);
	return result;
}

// function for rounding of the value of x in case of m > 1
int calculateX(float x)
{
	int result = round(x);
	return result;
}

// function for implementing the digital differential analyzer
void dda(float x1, float x2, float y1, float y2)
{
	float X1[100];
	float Y1[100];
	int counter = 0;
	float m = slope(x1, x2, y1, y2);
	printf("slope : %f \n", m);
	float x, y;
	x = x1;
	y = y1;
	int resultX = 0;
	int resultY = 0;
	if(m <= 1)																//case - 1
	{
		while(x <= x2)
		{
			resultX = (int)x;
			resultY = calculateY(y);
			printf("X actual: %f Y actual : %f X output: %d Y output : %d\n", x, y, resultX, resultY);
			x = x + 1;
			y = y + m;
			X1[counter] = x;
			Y1[counter] = y;
			counter++;
		}	

	}
	if(m > 1)																//case - 2
	{
		while(y <= y2)
		{
			resultY = (int)y;
			resultX = calculateY(x);
			printf("X actual: %f Y actual : %f X output: %d Y output : %d\n", x, y, resultX, resultY);
			x = x + 1/m;
			y = y + 1;
			X1[counter] = x;
			Y1[counter] = y;
			counter++;
		}

	}
	draw_line(X1, Y1, counter);
}

void myDisplay() 
{
	dda(x1, x2, yy1, y2);
	glFlush();
}

int main(int argc, char **argv)
{
	printf("Enter the cordinates value \n");
	scanf("%f", &x1);
	scanf("%f", &yy1);
	scanf("%f", &x2);
	scanf("%f", &y2);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
