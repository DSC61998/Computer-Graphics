#include<stdbool.h>
#include<GL/Glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<math.h>

float x= 0.0, y = 0.0;
bool check=true;
int X[100];
int Y[100];
int counter = 100;

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
        glClear(GL_COLOR_BUFFER_BIT);
   }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
       check=false;
       int i;
        for(i = 0; i < counter; i++)
        {
        	x = X[counter];
			y = Y[counter]; 
        }
   }
glutPostRedisplay();
}
          
void display(void)
{  
    glColor3f(1.0 , 0.0 , 0.0); // sets the current drawing (foreground) color to blue 
   
    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

	if(check)  
	{      
		int i; 
		float theta;
		glBegin(GL_POINTS); 
		for (i = 0; i < 360 ; i ++) 
		{   
			theta = i*3.142/180;
			glVertex2f(x + 10 * cos(theta), y + 10 * sin(theta)); 
		} 
		glEnd();
	}
	
	else
	{
		
		glBegin(GL_LINE_STRIP);
		glColor3f(0.00, 0.00, 1.00);
		int j;
		for(j = 0; j < counter - 1; j++)
		{

			glClearColor(0, 1, 1, 0);
			glVertex2i(X[j], Y[j]);	
		}
		
	glEnd();
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

