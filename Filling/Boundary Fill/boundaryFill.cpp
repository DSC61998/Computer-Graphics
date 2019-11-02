#include <gl/glut.h>
#include <math.h>
#include<stdio.h>

typedef struct cordiantePoint{
	float x;
	float y;
}cordiantePoint;

typedef struct Color {
    float r;
    float g;
    float b;
};

float bCol[] = {1, 1, 0};
float color[] = {0, 0, 1};
            
cordiantePoint xy0, xy1, xy2, xy3, xy4, xy5, xy6, xy7, xy8, xy9, xy10, xy;

int flag = 0;
int i = 0;

Color getPixelColor(int x, int y) 
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(int x, int y, Color color) 
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bound_it(int x, int y, float* fillColor, float* bc)
{
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-1,y,fillColor,bc);
        bound_it(x,y+1,fillColor,bc);
        bound_it(x,y-1,fillColor,bc);
    }
}

void processKeys(unsigned char key, int x, int y) 
{
    if (key == 32)
	{
		glColor3f(1, 1, 0);
			if(flag == 3)
			{
					glBegin(GL_LINE_LOOP);   
					glColor3f(1, 1, 0);
						glVertex2f(xy0.x, xy0.y);
					glColor3f(1, 0, 0);
						glVertex2f(xy1.x, xy1.y);
					glColor3f(1, 0, 1);
						glVertex2f(xy2.x, xy2.y);
					glEnd();
					glFlush();
			}
			if(flag == 4)
			{
					glBegin(GL_LINE_LOOP);   
					glColor3f(1, 1, 0);   
						glVertex2f(xy0.x, xy0.y);
						glVertex2f(xy1.x, xy1.y);
						glVertex2f(xy2.x, xy2.y);
						glVertex2f(xy3.x, xy3.y);
					glEnd();
					glFlush();
			}
			if(flag == 5)
			{
					glBegin(GL_LINE_LOOP);   
					glColor3f(1, 1, 0);  
						glVertex2f(xy0.x, xy0.y);
						glVertex2f(xy1.x, xy1.y);
						glVertex2f(xy2.x, xy2.y);
						glVertex2f(xy3.x, xy3.y);
						glVertex2f(xy4.x, xy4.y);
					glEnd();
					glFlush();
			}			
			if(flag == 6)
			{
					glBegin(GL_LINE_LOOP);   
					glColor3f(1, 1, 0);    
						glVertex2f(xy0.x, xy0.y);
						glVertex2f(xy1.x, xy1.y);
						glVertex2f(xy2.x, xy2.y);
						glVertex2f(xy3.x, xy3.y);
						glVertex2f(xy4.x, xy4.y);
						glVertex2f(xy5.x, xy5.y);
					glEnd();
					glFlush();
			}			
			if(flag == 7)
			{
					glBegin(GL_LINE_LOOP);   
					glColor3f(1, 1, 0);   
						glVertex2f(xy0.x, xy0.y);
						glVertex2f(xy1.x, xy1.y);
						glVertex2f(xy2.x, xy2.y);
						glVertex2f(xy3.x, xy3.y);
						glVertex2f(xy4.x, xy4.y);
						glVertex2f(xy5.x, xy5.y);
						glVertex2f(xy6.x, xy6.y);
					glEnd();
					glFlush();
			}
			flag = 0;
	}
}

void myMouseFunc(int button, int state, int x, int y)
{
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{

		if(flag == 0)
		{
			xy0.x = x;
			xy0.y = 480 - y;
			flag++;
		}
		else if(flag == 1)
		{
			xy1.x = x;
			xy1.y = 480 - y;
			flag++;
		}
		else if(flag == 2)
		{
			xy2.x = x;
			xy2.y = 480 - y;
			flag++;
		}
		else if(flag == 3)
		{
			xy3.x = x;
			xy3.y = 480 - y;
			flag++;
		}
		else if(flag == 4)
		{
			xy4.x = x;
			xy4.y = 480 - y;
			flag++;
		}
		else if(flag == 5)
		{
			xy5.x = x;
			xy5.y = 480 - y;
			flag++;
		}
		else if(flag == 6)
		{
			xy6.x = x;
			xy6.y = 480 - y;
			flag++;
		}	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		xy.x = x;
		xy.y = 480 - y;
		bound_it(xy.x, xy.y, color, bCol);
	}
}

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);    
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutKeyboardFunc(processKeys);
	init();
	glutMainLoop();
	return 0;
}

