#include<stdio.h>
#include<windows.h>
#include <GL/glut.h>


void mousePressFunc(int button,int state,int x,int y)
    {
        printf("\nczkjvzjvzjfkhfikhidfkdhfikfzkdffz;dsfjosdf");
      switch(button)
        {
          case GLUT_RIGHT_BUTTON:
             {
                 printf("\n coordinates are %d %d",x,y);
                  break;
              }
           default:
             {

                 break;
              }
         }
     }

void init (void)
{

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*int main(int argc, char**argv)
   {
     glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
       glClear (GL_COLOR_BUFFER_BIT);
        glColor3f (1.0, 1.0, 1.0);
          glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
        glutMouseFunc(mousePressFunc);
    glEnd();
    glFlush ();

    glutMainLoop();
          return 0;
    }
*/
