#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
float sx=1,sy=1;
float sum=0;
int c,d,k;
int i,j;
float T[3][3]={0,0,0,0,0,0,0,0,1};
float P[3][4]={500,500,550,550,400,450,450,400,1,1,1,1};
float trans[3][4]={0,0,0,0,0,0,0,0,0,0,0,0};
typedef struct
   {
       float x;
       float y;
   }Point;

   Point centre={525,425};
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


    void myBoard(GLubyte key,GLint xMouse, GLint yMouse)
        {
            switch(key)
               {
             case 'd':
                 glBegin(GL_POLYGON);
                 glVertex2f(500,400);
                 glVertex2f(500,450);
                 glVertex2f(550,450);
                 glVertex2f(550,400);
                 glEnd();
                 glFlush();
                 break;
             case 's':
                 if(sx>2||sy>2)
                 {
                     return;
                 }
                T[0][0]=sx;T[1][1]=sy;
                T[0][2]=(centre.x)*(1-sx);
                T[1][2]=(centre.y)*(1-sy);
                for (c = 0; c < 3; c++) {
             for (d = 0; d < 4; d++) {
             for (k = 0; k < 3; k++) {
              sum = sum + T[c][k]*P[k][d];
                         }
                  trans[c][d]=sum;
                    sum = 0;
                 }
                }
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        printf("\n T[%d][%d]=%f",i,j,T[i][j]);
                    }
                }
                for(i=0;i<3;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        printf("\n P[%d][%d]=%f",i,j,P[i][j]);
                    }
                }
                for(i=0;i<3;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        printf("\n trans[%d][%d]=%f",i,j,trans[i][j]);
                    }
                }
                glClear(GL_COLOR_BUFFER_BIT);
                glBegin(GL_POLYGON);
                glVertex2f(trans[0][0],trans[1][0]);
                glVertex2f(trans[0][1],trans[1][1]);
                glVertex2f(trans[0][2],trans[1][2]);
                glVertex2f(trans[0][3],trans[1][3]);
                glEnd();
                glFlush();
                //copy trans to point
                for(i=0;i<3;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        P[i][j]=trans[i][j];
                    }
                }

                if(sx<2&&sy<2)
                 {
                     sx=sx+0.2;
                     sy=sy+0.2;
                 }
                 break;
             default:
                break;
               }
        }
    void init()
      {
       glClearColor(0.0,0.0,1.0,1.0);
        glColor3f(1.0,1.0,0.0);
        gluOrtho2D(0.0f, 1000.0f, 0.0f, 700.0f);
      }

int main(int argc,char**argv)
   {
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowSize(1000,700);
      glutInitWindowPosition(300,100);
      glutCreateWindow("scaling algorithm");
      init();
      glutDisplayFunc(display);
      glutIdleFunc(display);
      glutKeyboardFunc(myBoard);
      glutMainLoop();
       return 0;
   }
