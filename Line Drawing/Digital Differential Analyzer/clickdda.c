#include <gl/glut.h>
#include <math.h>

typedef struct cordiantePoint{
	float x;
	float y;
}cordiantePoint;

cordiantePoint xy1, xy2;
float m;

void drawBitmapText(char *string, float x, float y, float z) 
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
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
		
		m = (xy2.y - xy1.y) / (xy2.x - xy1.x);
		printf("%f \n", m);
		printf("Xinitial %f  Yinitial %f \n", xy1.x, xy1.y);
		printf("Xfinal %f  Yfinal %f \n", xy2.x, xy2.y);
		char buffer[20];  
		char buffer2[4];

		
		float absX, absY;
		float xinitial = xy1.x;
		float yinitial = xy1.y;
	
		float step = 0;
		if((xy2.x - xy1.x) > 0)
		{
			absX = xy2.x - xy1.x;
			step = absX;
		}
		else
		{
			absX = -1 * (xy2.x - xy1.x);
			step = absX;	
		}
		if((xy2.y - xy1.y) > 0)
		{
			absY = xy2.y - xy1.y;
			step = absY;
		}
		else
		{
			absY = -1 * (xy2.y - xy1.y);
			step = absY;	
		}
		
		float incX = (xy2.x - xy1.x)/step;
		float incY = (xy2.y - xy1.y)/step;
		int j; 
		float theta;
		
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex2i(xy1.x, xy1.y);
			glVertex2i(xy2.x, xy2.y);
		glEnd();
		glFlush();
		
		glColor3f(0.0f, 1.0f, 0.0f);
		
		float i;
		for(i = 1; i <= step; i++) 
		{
			glBegin(GL_POINTS);
			glVertex2i( xinitial,  yinitial);
			glEnd();
			xinitial+= incX;
			yinitial += incY;
		}
		
		
		gcvt(m, 3, buffer); 
    	drawBitmapText(buffer, 600, 0, 0);
    	drawBitmapText("Divyanshu Singh Chauhan", 0, 20, 0);
    	drawBitmapText("500060640", 0, 5, 0);
		glFlush();
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
	//glClear(GL_COLOR_BUFFER_BIT);

	int j;
	glBegin(GL_LINES);
	glColor3f(1.00, 1.00, 0.00);
	for(j = 0; j <= 480; j = j + 10)
	{
        glVertex2i(0, j); 
		glVertex2i(640, j);  
	}
	for(j = 0; j <= 640; j = j + 10)
	{
        glVertex2i(j, 0); 
		glVertex2i(j, 480);  
	}
	glEnd();
    glFlush();
    
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
	init();
	glutMainLoop();
	return 0;
}

