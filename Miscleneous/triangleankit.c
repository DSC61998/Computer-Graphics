#include<GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-10, 10, -10, 10);
	glColor4f(0,1,0,1);
	glBegin(GL_TRIANGLES);
		glVertex2f(1, 0);
		glVertex2f(0, 5);
		glVertex2f(5,0);
	glEnd();
	glFlush();
}
int main(int argc , char**argv)		//used to initialize glut library
{
	glutInit(&argc, argv);	//initializing glut library
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);	//initializing view mode
	
	glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);
	glutCreateWindow("Window 1");
	glutDisplayFunc(display);
	
	glutMainLoop();
}
