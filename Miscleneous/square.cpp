#include<GL/glut.h>

void display();
void reshape(int, int);
void timer(int);
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

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
	drawBitmapText("Divyanshu Singh Chauhan \n 500060640 ", -7, 0, 0);
} 

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Window 1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0); 
	init();
	glutMainLoop();
}

void reshape(int w, int h)
{
	glViewport(0, 0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

float xPosition = -1;
float yPosition = -1;
float xPositionP = 1;
float yPositionP = 1;
float R = 0.0;
float G = 0.0008;
float B = 0.5;
int state = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
		glVertex2f(xPosition, yPosition);
		glVertex2f(xPosition, yPositionP);
		glVertex2f(xPositionP , yPositionP);
		glVertex2f(xPositionP , yPosition);
	glEnd();
	render();
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);
	switch(state)
	{
		case 1:
			{
					if (xPositionP <= 10)
					{
						xPosition -= 0.15;
						xPositionP += 0.15;
						yPosition -= 0.15;
						yPositionP += 0.15;
						R += 0.01;
						G += 0.01;
						B += 0.01;
					}
					else
					{
						state = 2;
					}
					render();
					break;
			}
		case 2:
			{
					if (xPositionP >= 1)
					{
						xPosition += 0.15;
						xPositionP -= 0.15;
						yPosition += 0.15;
						yPositionP -= 0.15;
						R -= 0.01;
						G -= 0.01;
						B -= 0.01;
					}
					else
					{
						state = 1;
					}
					render();
					break;	
			}
	}
		
}
