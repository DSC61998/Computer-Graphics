
#include <stdio.h> 
#include <stdlib.h> 
#include<GL/glut.h>
#include<math.h> 
#include <time.h> 

int X[100];
int Y[100];
int Xi[10];
int Yi[10];
int counter = 0;
int lowerx = 0;
int upperx = 640;
int lowery = 0;
int uppery = 480;
float theta;
int i = 1;

void processKeys(unsigned char key, int x, int y) 
{
    if (key == 32)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		float r = (rand() % 9) / 8;
		float g = (rand() % 9) / 8;
		float b = (rand() % 9) / 8;
		
		int j, i;

		srand(time(0));
		for(j = 0; j < counter; j++)
		{
			X[j] =  (rand() % (upperx - lowerx + 1)) + lowerx;
			Y[j] =  (rand() % (uppery - lowery + 1)) + lowery;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		x = Xi[0];
		y = Yi[0];
		for(double k=0; k<450; k+=0.05)
    	{
        	glClear(GL_COLOR_BUFFER_BIT);
    		glBegin(GL_POLYGON); 
    		if(k <= 150)
    		{
    			for ( i = 0; i < 360 ; i ++) 
				{   		
					glColor3f(0.5, 0, 0);
					theta = i*3.142/180;
					glBegin(GL_POLYGON);
					glVertex2f((Xi[0] + k) + 3 * cos(theta), (Yi[0]) + 3 * sin(theta));
					glVertex2f((Xi[1]) + 3 * cos(theta), (Yi[1] + k) + 3 * sin(theta));
					glVertex2f((Xi[2] + k) + 3 * cos(theta), (Yi[2]) + 3 * sin(theta)); 
					glEnd();
				} 
				
	    		glFlush();	
    		}
    		
    		if(k > 150 && k < 300)
    		{
    			for ( i = 0; i < 360 ; i ++) 
				{   		
					glColor3f(1, 1, 0);
					glBegin(GL_POLYGON);
					theta = i*3.142/180;
					glVertex2f((Xi[0] + k) + 2 * cos(theta), (Yi[0]) + 2 * sin(theta)); 
					glVertex2f((Xi[1] + k) + 2 * cos(theta), (Yi[1] + k) + 2 * sin(theta));
					glVertex2f((Xi[2]) + 2 * cos(theta), (Yi[2] + k) + 2 * sin(theta)); 
					glEnd();
				} 
	    		glFlush();	
    		}
    		
    		if(k >= 300 && k < 450)
    		{
    			for ( i = 0; i < 360 ; i ++) 
				{   
					glColor3f(1, g, b);
					theta = i*3.142/180;
					glVertex2f((Xi[0] + k) + 1 * cos(theta), (Yi[0]) + 1 * sin(theta)); 
					glVertex2f((Xi[1] + k) + 1 * cos(theta), (Yi[1]) + 1 * sin(theta));
					glVertex2f((Xi[2]) + 1 * cos(theta), (Yi[2] + k) + 1 * sin(theta)); 
				} 
				glEnd();
	    		glFlush();	
    		}
    	}
	}
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
			Xi[counter] = x;
			Yi[counter] = 480 - y;
			counter++;
			int i,j;		
			for(j = 0; j < counter; j++)
			{
				glBegin(GL_POLYGON); 
		    	for ( i = 0; i < 360 ; i ++) 
				{   		
				
					theta = i*3.142/180;
					glVertex2f(Xi[j] + 20 * cos(theta), Yi[j] + 20 * sin(theta)); 
				} 
		glEnd();
		}
		glFlush();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 640, 0, 480);
	
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
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
}

