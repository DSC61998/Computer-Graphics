#include <gl/glut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct cordiantePoint{
float x;
float y;
}cordiantePoint;

cordiantePoint xy1, xy2;
float r;

void drawBitmapText(char *string, float x, float y, float z)
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void circle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float differenceX = xy2.x - xy1.x;
	float differenceY = xy2.y - xy1.y;
	float d = sqrt(pow(differenceX, 2) + pow(differenceY, 2));
	printf("radius of the circle is %f\n", d);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(xy1.x, xy1.y);
	glVertex2i(xy2.x, xy2.y);
	glEnd();
	float xmid = xy1.x;
	float ymid =xy1.y;
	printf("Center of the circle (%f ,%f)", xmid, ymid);
	glColor3f(0.0f, 1.0f, 0.0f);
	float x = d, y = 0;
	glBegin(GL_POINTS);
	int P = 1 - r;
	while (x > y)
	   {  
	       y++;
	       if (P <= 0)
	           P = P + 2*y + 1;
	       else
	       {
	           x--;
	           P = P + 2*y - 2*x + 1;
	       }  
	       glVertex2f(x + xmid, y + ymid);
	       glVertex2f(-x + xmid, y + ymid);
	       glVertex2f(x + xmid, -y + ymid);
	       glVertex2f(-x + xmid, -y + ymid);      
           glVertex2f(y + xmid, x + ymid);
           glVertex2f(-y + xmid, x + ymid);
           glVertex2f(y + xmid, -x + ymid);
           glVertex2f(-y + xmid, -x + ymid);
	}
	glEnd();
	char buffer[10];
	gcvt(d, 3, buffer);
	drawBitmapText(buffer, 600, 0, 0);
	drawBitmapText("Divyanshu Singh Chahuhan", 0, 20, 0);
	drawBitmapText("500060640", 0, 5, 0);
	glFlush();
}

void specialkey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			{
				xy2.x = xy2.x + 1;
				xy2.y = xy2.y + 1;
				circle();
				break;
			}
		case GLUT_KEY_DOWN:
			{
				xy2.x = xy2.x - 1;
				xy2.y = xy2.y - 1;
				circle();
				break;
			}
		case GLUT_KEY_RIGHT:
			{
				xy1.x = xy1.x + 1;
				xy1.y = xy1.y + 1;
				xy2.x = xy2.x + 1;
				xy2.y = xy2.y + 1;
				circle();
				break;
			}
		case GLUT_KEY_LEFT:
			{
				xy1.x = xy1.x - 1;
				xy1.y = xy1.y - 1;
				xy2.x = xy2.x - 1;
				xy2.y = xy2.y - 1;
				circle();
				break;
			}
			
	}
}
void myMouseFunc(int button, int state, int x, int y)
{

if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
xy1.x = x;
xy1.y = 480 - y;
}
else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
	glClear(GL_COLOR_BUFFER_BIT);
	xy2.x = x;
	xy2.y = 480 - y;
	circle();
} 
	glutPostRedisplay();
}

void init()
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(1.0f);
gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display()
{  
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200, 200);
glutInitWindowSize(640, 480);
glutCreateWindow("Mid Point Circle");
glutDisplayFunc(display);
glutMouseFunc(myMouseFunc);
glutSpecialFunc(specialkey);
init();
glutMainLoop();
return 0;
}


