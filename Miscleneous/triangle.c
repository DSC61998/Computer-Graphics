#include<GL/glut.h>

#include<stdio.h>

void drawBitmapText(char *string, float x, float y, float z) 
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void render(void)
{  
	glColor3f(1, 0.3, 0.5);
	drawBitmapText("Divyanshu Singh Chauhan \n 500060640 ", -0.3, -0.5, 0);
} 

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLES);
	glColor3f(1.00,0.00,0.00);
	glVertex2f(0,0.5);
	glColor3f(0.00,1.00,0.00);
	glVertex2f(-0.5,0.0);
	glColor3f(0.00,0.00,1.00);
	glVertex2f(0.5,0);
glEnd();
render();
glFlush();
}

void specialkey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_TRIANGLES);
					glColor3f(1.00,0.00,0.00);
					glVertex2f(0,0.5);
					glVertex2f(-0.5,0.0);
					glVertex2f(0.5,0);
				glEnd();
				render();
				glFlush();
				break;
			}
			case GLUT_KEY_DOWN:
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_TRIANGLES);
					glColor3f(1.00, 0.00, 1.00);
					glVertex2f(0,0.5);
					glVertex2f(-0.5,0.0);
					glVertex2f(0.5,0);
				glEnd();
				render();
				glFlush();
				break;
			}	
	}
}

int main(int argc,char** argv)
{

   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("triangle");
    glutDisplayFunc(display);
    glutSpecialFunc(specialkey);
    glutMainLoop();
    return 0;
}
