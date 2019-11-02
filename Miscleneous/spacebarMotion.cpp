#include <stdio.h> 
#include <stdlib.h> 
#include<GL/glut.h>
#include<math.h> 
#include <time.h> 

int Xi[100];
int Yi[100];
int X[100];
int Y[100];
int counter = 0;
int lower = -10;
int upper = 10;
float theta;

/*
void myMouseFunc(int button, int state, int x, int y)
{
	float r = (rand() % 9) / 8;
	float g = (rand() % 9) / 8;
	float b = (rand() % 9) / 8;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
			Xi[counter] = x;
			Yi[counter] = 480 - y;
				glBegin(GL_POLYGON); 
		    	for ( i = 0; i < 360 ; i ++) 
				{   		
					glColor3f(r, g, b);
					theta = i*3.142/180;
					glVertex2f(Xi[counter] + 20 * cos(theta), Yi[counter] + 20 * sin(theta)); 
				} 
		glEnd();
		counter++;
		glFlush();
	}
}
*/

void processKeys(unsigned char key, int x, int y) 
{
	glClear(GL_COLOR_BUFFER_BIT);
    if (key == 32)
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);

		int xcor = (rand() % (upper - lower + 1)) + lower;
		int ycor = (rand() % (upper - lower + 1)) + lower;
		
		/*int i; 
       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(r, g, b);
				theta = i*3.142/180;
				glVertex2f(xcor + 1 * cos(theta), ycor + 1 * sin(theta)); 
			} 
		glEnd();
		glFlush();
		*/
		int j;
		for(j = 0; j < 5; j++)
		{
			X[j] =  (rand() % (upper - lower + 1)) + lower;
			Y[j] = (rand() % (upper - lower + 1)) + lower;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		int i; 
	 
       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(1, 0, 0);
				theta = i*3.142/180;
				glVertex2f(X[0] + 1 * cos(theta), Y[0] + 1 * sin(theta)); 
			} 
		glEnd();
		
		       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(0, 0, 1);
				theta = i*3.142/180;
				glVertex2f(X[1] + 1 * cos(theta), Y[1] + 1 * sin(theta)); 
			} 
		glEnd();
		
		       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(0, 1, 0);
				theta = i*3.142/180;
				glVertex2f(X[2] + 1 * cos(theta), Y[2] + 1 * sin(theta)); 
			} 
		glEnd();
		
		       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(1, 1, 1);
				theta = i*3.142/180;
				glVertex2f(X[3] + 1 * cos(theta), Y[3] + 1 * sin(theta)); 
			} 
		glEnd();
		
		       	glBegin(GL_POLYGON); 
		   for ( i = 0; i < 360 ; i ++) 
			{   
				glColor3f(1, 1, 0);
				theta = i*3.142/180;
				glVertex2f(X[4] + 1 * cos(theta), Y[4] + 1 * sin(theta)); 
			} 
		glEnd();
		glFlush();
		
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc , char**argv)		//used to initialize glut library
{
	glutInit(&argc, argv);	//initializing glut library
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);	//initializing view mode
	glutInitWindowSize(640, 480); 
    glutInitWindowPosition(0, 0);
	glutCreateWindow("Window 1");
	glutDisplayFunc(display);
	glutKeyboardFunc(processKeys);
	glutMainLoop();
}

