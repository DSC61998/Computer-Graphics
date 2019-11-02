#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float x1, x2, yy1, y2;
	
//function for initializing glut
void myInit() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10, 10, -10, 10);
}

//function for drawing the line
void draw_line(float x1[10], float y1[10], int counter)
{
	int x, y;
	glClear(GL_COLOR_BUFFER_BIT); //clearing the frame buffer
	glBegin(GL_LINES);					
	for(x = -10; x <= 10; x++)
	{
		glColor3f(1.00, 1.00, 1.00);
		glVertex2i(x, 10);
		glVertex2i(x, -10);		
	}
	for(y = -10; y <= 10; y++)
	{
		glVertex2i(10, y);
		glVertex2i(-10, y);		
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

// function for implementing the digital differential analyzer
void bresenhams(float x1, float x2, float y1, float y2)
{
	float X1[100];
	float Y1[100];
	int counter = 0;
	float resultX = 0;
	float resultY = 0;
	
	// pre requirment calculations 
	float m = slope(x1, x2, y1, y2);
	float dy = y2 - y1;
	float dx = x2 - x1;
	float P = (2*dy - dx);

	float x, y;
	x = x1;
	y = y1;

	if(m <= 1)															//case - 1
	{
		while(x <= x2 && y <= y2)
		{
			if(P < 0)
			{
				X1[counter] = x;
				Y1[counter] = y;
				counter++;
				resultX = x;
				resultY = y;	
				x = x + 1;
				P = P + (2 * dy);
				printf("X actual: %f Y actual : %f || P : %f || X after computation: %f Y after computation : %f\n", resultX, resultY, P, x, y);
			}
			if(P >= 0)
			{
				X1[counter] = x;
				Y1[counter] = y;
				counter++;
				resultX = x;
				resultY = y;
				x = x + 1;
				y = y + 1;
				P = P + (2 * dy) - (2 * dx);
				printf("X actual: %f Y actual : %f || P : %f || X after computation: %f Y after computation : %f\n", resultX, resultY, P, x, y);
			}
		}
	}
	if(m > 1)																//case - 1
	{
		while(x <= x2 && y <= y2)
		{
			if(P < 0)
			{
				X1[counter] = x;
				Y1[counter] = y;
				counter++;
				resultX = x;
				resultY = y;
				y = y + 1;
				P = P + (2 * dx);
				printf("X actual: %f Y actual : %f || X after computation: %f Y after computation : %f\n", resultX, resultY, x, y);
			}
			if(P >= 0)
			{
				X1[counter] = x;
				Y1[counter] = y;
				counter++;
				resultX = x;
				resultY = y;
				x = x + 1;
				y = y + 1;
				P = P + (2 * dx) - (2 * dy);
				printf("X actual: %f Y actual : %f || X after computation: %f Y after computation : %f\n", resultX, resultY, x, y);
			}
		}
	}
	draw_line(X1, Y1, counter);
}

void myDisplay() 
{
	bresenhams(x1, x2, yy1, y2);
	glFlush();
}

int main(int argc , char**argv)
{
	printf("Enter the cordinates values \n");
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
