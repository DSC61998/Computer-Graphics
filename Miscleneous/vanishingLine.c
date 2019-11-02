#include<stdbool.h>
#include<GL/Glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<math.h>

float x= 0.0, y = 0.0;
float r, g, b;
bool check=true;
int X[3] = {0, 0, 0};
int Y[3] = {0, 0, 0};
int counter = 0;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;
        x = mousex;
        y = 480-mousey;
        X[counter] = x;
        Y[counter] = y;
        counter++;
        if(counter == 2)
        {
        	counter = 0;
        }
        r=0;
        g=1;
        b=1;
   }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
		check=false;

        glColor3f(r, g, b);
    }
glutPostRedisplay();
}
          
void display(void)
{  
    //glColor3f(1.0 , 1.0 , 1.0); // sets the current drawing (foreground) color to blue 
    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	if(check)  
	{      
		int i; 
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_LINE_STRIP);
				glVertex2f(X[0], Y[0]);
				glVertex2f(X[1], Y[1]);	
			glEnd();
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
    glFlush(); 
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("DDA Line Drawing");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}

