#include<windows.h>
#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
#include<stdio.h>
void display()
  {
      glClear(GL_COLOR_BUFFER_BIT);
      glRotatef(0.1,1.0,0.0,0.0);
      glBegin(GL_TRIANGLES);
      glColor3f(0.0,0.1,0.0);
      glVertex3f(-0.5,-0.5,0.0);
      glColor3f(1.0,0.0,0.0);
      glVertex3f(0.5,-0.5,0.0);
      glColor3f(0.0,0.0,1.0);
      glVertex3f(0.0,0.5,0.0);
      glEnd();
      glutSwapBuffers();
  }
  void init()
    {
        glClearColor(0.5,0.0,0.0,1.0);
    }
    void reshape(int w,int h)
      {
          glViewport(0,0,w,h);
      }
int main(int argc,char **argv)
   {
       glutInit(&argc,argv);
       glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
       glutInitWindowSize(500,500);
       glutInitWindowPosition(50,50);
       glutCreateWindow("mera pehla open gl");
       init();
       glutDisplayFunc(display);
       glutIdleFunc(display);
       glutReshapeFunc(reshape);
       glutMainLoop();
   }
