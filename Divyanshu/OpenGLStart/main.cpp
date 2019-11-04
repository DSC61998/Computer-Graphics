#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
     void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glVertex2i(50,50);
        glVertex2i(100,50);
        glVertex2i(10,10);
        glEnd();
        glBegin(GL_LINES);
        glVertex2i(120,50);
        glVertex2i(10,220);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2i(160,180);
        glVertex2i(190,180);
        glVertex2i(150,28);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2i(200,200);
        glVertex2i(200,400);
        glVertex2i(400,400);
        glVertex2i(400,200);
        glEnd();
        glFlush();
    }
    void init()
      {
          glPointSize(3.0);
          glLineWidth(3.0);
          glClearColor(0.0,0.0,1.0,1.0);
          glColor3f(1.0,1.0,0.0);
          gluOrtho2D(0.0f, 500.0f, 0.0f, 700.0f);
      }
int main(int argc,char**argv)
   {
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(400,400);
      glutInitWindowPosition(300,100);
      glutCreateWindow("Primitive OpenGL");
      init();
      glutDisplayFunc(display);
      glutIdleFunc(display);
      glutMainLoop();
      return 0;
   }
