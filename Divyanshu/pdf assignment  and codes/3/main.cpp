#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>
typedef struct
   {
       int x;
       int y;
   }Point;
   Point*O=NULL;
   Point*A=NULL;
   Point*B=NULL;
   int counter=6;
   int a=1;
void display()
    {
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
        glColor3f(0.0,0.0,1.0);
        gluOrtho2D(0.0f, 700.0f, 0.0f, 500.0f);
    }
    void reshape(int w,int h)
       {
           glViewport(0,0,w,h);
       }
    void drawEllipse(int x,int y,int a,int b)
       {
           printf("\n  %d %d %d %d",x,y,a,b);
            int p=4*b*b+a*a-4*a*a*b;
           int x0=0,y0=b;
            while(a*a*y0>=b*b*x0)
            {
                if(p>0)
                {
                p=p+8*a*a+8*b*b+2*x0*b*b-2*a*a*y0;
                x0=x0+1;
                y0=y0-1;
                glVertex2i(x+x0,y+y0);
                glVertex2i(x-x0,y-y0);
                glVertex2i(x+x0,y-y0);
                glVertex2i(x-x0,y+y0);

                }
                else
                {
                    p=p+2*x*b*b+3*b*b;
                    x0=x0+1;
                    glVertex2i(x+x0,y+y0);
                 glVertex2i(x-x0,y-y0);
                  glVertex2i(x+x0,y-y0);
                   glVertex2i(x-x0,y+y0);
                }
            }
            while(b*b*x0>=a*a*y0)
            {
                p=4*b*b*x0*x0+1+4*b*b*x0+4*a*a*y0*y0+4-8*a*a*y0-4*a*a*b*b;
                if(p>0)
                {
                    p=p+4*(3*a*a+p-2*y0*a*a);
                    y0=y0-1;
                  glVertex2i(x+x0,y+y0);
                 glVertex2i(x-x0,y-y0);
                  glVertex2i(x+x0,y-y0);
                   glVertex2i(x-x0,y+y0);

                }
                else
                {
                    p=p+4*(2*b*b+3*a*a+2*x0*b*b-2*y0*a*a);
                    x0=x0+1;
                    y0=y0-1;
                    glVertex2i(x+x0,y+y0);
                    glVertex2i(x-x0,y-y0);
                    glVertex2i(x+x0,y-y0);
                    glVertex2i(x-x0,y+y0);
                }
            }
       }
    void myMouse(int button, int state,int x,int y)
       {
           int actualHeight;
           actualHeight=glutGet(GLUT_WINDOW_HEIGHT)-y;
            glBegin(GL_POINTS);
           if(button==GLUT_LEFT_BUTTON)
           {
               printf("\n counter is %d",counter);
            if(counter>4)
            {
                if(O==NULL)
                {
                O=(Point*)malloc(sizeof(Point));
              O->x=x;
              O->y=actualHeight;
              glVertex2i(x,actualHeight);
              printf("daba");
                }
                counter--;
            }
            else if(counter>2)
            {
                if(A==NULL)
                {
              glVertex2i(x,actualHeight);
              A=(Point*)malloc(sizeof(Point));
              A->x=x;
              A->y=actualHeight;
              printf("\n AAA");
                }
                counter--;
            }
            else if(counter>0)
            {
                if(B==NULL)
                {
              glVertex2i(x,actualHeight);
              B=(Point*)malloc(sizeof(Point));
              B->x=x;
              B->y=actualHeight;
              printf("\n BBB");
              int a=round(sqrt(pow((O->x)-(A->x),2)+pow((O->y)-(A->y),2)));
             int b=round(sqrt(pow((O->x)-(B->x),2)+pow((O->y)-(B->y),2)));
              drawEllipse(O->x,O->y,a,b);
                }
            }

         }
          glEnd();
        glFlush();

       }

int main(int argc,char**argv)
   {
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowSize(700,500);
      glutInitWindowPosition(300,100);
      glutCreateWindow("Draw Ellipse Randomly");
      init();
      glutDisplayFunc(display);
      glutMouseFunc(myMouse);
      glutIdleFunc(display);
      glutReshapeFunc(reshape);
      glutMainLoop();
       return 0;
   }
