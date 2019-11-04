#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>
typedef struct
   {
       int x;
       int y;
   }Point;
   Point*centre=NULL;
   int radius=-1;
   int counter=2;
   int a=1;
void display()
    {
        //printf("\n hello printing");
        if(a==1)
        {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        a=0;
        }
    }
 void init()
    {
        glClearColor(0.5,0.0,0.0,1.0);
        glPointSize(1.5f);
        glColor3f(0.0,0.0,1.0);
        gluOrtho2D(0.0f, 700.0f, 0.0f, 500.0f);
    }
    void reshape(int w,int h)
       {
           glViewport(0,0,w,h);
       }
        void drawCircle(int xc,int yc,int r)
        {
             int h=1-r;
              int x0=0,y0=r;
              glVertex2i(x0,y0);
                          glVertex2i(xc+x0, yc+y0);
                         glVertex2i(xc-x0, yc+y0);
                         glVertex2i(xc+x0, yc-y0);
                         glVertex2i(xc-x0, yc-y0);
                         glVertex2i(xc+y0, yc+x0);
                         glVertex2i(xc-y0, yc+x0);
                         glVertex2i(xc+y0, yc-x0);
                         glVertex2i(xc-y0, yc-x0);
              printf("\n value of r is %d",r);
              while(y0>x0)
              {
                  if(h>=0)
                  {
                      h=h+2*x0-2*y0+5;
                       int x=x0+1;
                        int y=y0-1;
                         glVertex2i(xc+x, yc+y);
                         glVertex2i(xc-x, yc+y);
                         glVertex2i(xc+x, yc-y);
                         glVertex2i(xc-x, yc-y);
                         glVertex2i(xc+y, yc+x);
                         glVertex2i(xc-y, yc+x);
                         glVertex2i(xc+y, yc-x);
                         glVertex2i(xc-y, yc-x);
                         y0=y0-1;
                  }
                  else
                  {
                      h=h+2*x0+3;
                         int x=x0+1;
                        int y=y0;
                         glVertex2i(xc+x, yc+y);
                         glVertex2i(xc-x, yc+y);
                         glVertex2i(xc+x, yc-y);
                         glVertex2i(xc-x, yc-y);
                         glVertex2i(xc+y, yc+x);
                         glVertex2i(xc-y, yc+x);
                         glVertex2i(xc+y, yc-x);
                         glVertex2i(xc-y, yc-x);
                  }
                  printf("\n value of x0 is %d and y0 is %d",x0,y0);
                  x0=x0+1;
              }
        }
    void myMouse(int button, int state,int x,int y)
       {
           int actualHeight;
           actualHeight=glutGet(GLUT_WINDOW_HEIGHT)-y;
            glBegin(GL_POINTS);
           if(button==GLUT_LEFT_BUTTON)
           {
            if(!centre)
            {
                centre=(Point*)malloc(sizeof(Point));
              centre->x=x;
              centre->y=actualHeight;
              glVertex2i(x,actualHeight);
              printf("daba");
            }
            else if(counter==0)
            {
              glVertex2i(x,actualHeight);
               radius=round(sqrt(pow((centre->x-x),2)+pow((centre->y-actualHeight),2)));
               drawCircle(centre->x,centre->y,radius);
            }
            counter--;
         }
          glEnd();
        glFlush();
       }
     void myKeyBoard(GLubyte key,GLint xMouse, GLint yMouse)
        {
            switch(key)
               {
               case 'i':
                   glClear(GL_COLOR_BUFFER_BIT);
                   glFlush();
                   glBegin(GL_POINTS);
                   radius=radius+5;
                   drawCircle(centre->x,centre->y,radius);
                   glEnd();
                   glFlush();
                 break;
               case 'j':
                glClear(GL_COLOR_BUFFER_BIT);
                   glFlush();
                   glBegin(GL_POINTS);
                   radius=radius-5;
                   drawCircle(centre->x,centre->y,radius);
                   glEnd();
                   glFlush();
                 break;
               default:
                break;
               }
        }
int main(int argc,char**argv)
   {
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowSize(700,500);
      glutInitWindowPosition(300,100);
      glutCreateWindow("Draw Circle Randomly");
      init();
      glutDisplayFunc(display);
      glutMouseFunc(myMouse);
      glutIdleFunc(display);
      glutReshapeFunc(reshape);
      glutKeyboardFunc(myKeyBoard);
      glutMainLoop();
       return 0;
   }
