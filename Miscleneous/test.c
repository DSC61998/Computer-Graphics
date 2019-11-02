#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void init(void)
{

    glClearColor(0.0,0,0,0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //tree top
    double i;
    for( i=0; i<300; i+=0.1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.3,1,0,1);
        glBegin(GL_TRIANGLES);
        glVertex2f(70.0+i,170.0);//b
        glVertex2f(110.0+i,250.0);//a
        glVertex2f(150.0+i,170.0);//c
    glEnd();
    glFlush();
    }
    
}

void move(unsigned char key, int x, int y) {

switch(key){
case 27: glutDestroyWindow(1); break;
case 32: display(); break;
}

}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("MyWindow");
    glutDisplayFunc(display);
    glutKeyboardFunc(move);
    init();
    glutMainLoop();
    return 0;
}
