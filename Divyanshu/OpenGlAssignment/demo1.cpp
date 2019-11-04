#include<windows.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include<stdio.h>
#include<string.h>
typedef struct
  {
      int x;
       int y;
  }Point;
  Point *first;
  Point *second;
  float m;
  int counter=0;
   void printtext(int x,int y,char* st)
      {
          int l,i;
           glFlush();
              l=strlen( st ); // see how many characters are in text string.
             glRasterPos2i( x, y);
             // location to start printing text
             for( i=0; i < l; i++) // loop until i is greater then l
               {
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]); // Print a character on the screen
                }
      }
void myDisplay() {
               static char arr[50];
        glClear(GL_COLOR_BUFFER_BIT);
    printtext(20,410,"1.Kamal Dua");
      if(counter==1)
              {
                 sprintf(arr,"(%d,%d)",first->x,first->y);
              printtext(first->x,first->y+50,arr);
              sprintf(arr,"m=%f",m);
              printtext(320,50,arr);
              sprintf(arr,"(%d,%d)",second->x,second->y);
              printtext(second->x,second->y+50,arr);
              glFlush();
              }
    glFlush();
}
void assignValues(int *x0,int a,int *y0,int b,int *x1,int c,int *y1,int d)
    {
        *x0=a;*y0=b;*x1=c;*y1=d;
    }
void drawLine(Point *ptr1,Point *ptr2)
    {
       int x0,y0,x1,y1,dy,dx,x,y,p;
       char arr[50];
         m=(float)((ptr2->y)-(ptr1->y))/((ptr2->x)-(ptr1->x));
        printf("\n value of m is %f",m);
        if(m>=0 && m<=1)
        {
            if(ptr2->x>ptr1->x)
            {
                assignValues(&x0,ptr1->x,&y0,ptr1->y,&x1,ptr2->x,&y1,ptr2->y);
            }
            else
            {
                assignValues(&x0,ptr2->x,&y0,ptr2->y,&x1,ptr1->x,&y1,ptr1->y);
            }
            dx=x1-x0;
                dy=y1-y0;
                p=2*dy-dx;
                for(x=x0,y=y0;x<x1-1;x++)
                {
                    if(p>0)
                    {
                        p=2*dy-2*dx+p;
                        glVertex2i(x+1,y+1);

                        y=y+1;
                    }
                    else
                    {
                        p=p+2*dy;
                        glVertex2i(x+1,y);
                    }
                }
        }
        else if(m>1)
        {
            if(ptr2->y>ptr1->y)
            {
                assignValues(&x0,ptr1->x,&y0,ptr1->y,&x1,ptr2->x,&y1,ptr2->y);
            }
            else
            {
                assignValues(&x0,ptr2->x,&y0,ptr2->y,&x1,ptr1->x,&y1,ptr1->y);
            }
            dx=x1-x0;
                dy=y1-y0;
                p=2*dx+dy;
                for(y=y0,x=x0;y<y1-1;y++)
                {
                    if(p>0)
                    {
                        glVertex2i(x+1,y+1);
                        p=2*dx-2*dy+p;
                        x=x+1;
                    }
                    else
                    {
                        glVertex2i(x,y+1);
                        p=p+2*dx;
                    }
                }
        }
        else if(m<=-1)
        {
          if(ptr1->y>ptr2->y)
          {
              assignValues(&x0,ptr2->x,&y0,ptr2->y,&x1,ptr1->x,&y1,ptr1->y);
          }
          else
          {
              assignValues(&x0,ptr1->x,&y0,ptr1->y,&x1,ptr2->x,&y1,ptr2->y);
          }
          dx=x1-x0;
          dy=y1-y0;
          p=2*dx+dy;
          for(y=y0,x=x0;y<y1-1;y++)
          {
              if(p>0)
              {
                  p=p+2*dx;
                  glVertex2i(x,y+1);

              }
              else
              {
                  p=p+2*dx+2*dy;
                  glVertex2i(x-1,y+1);
                  x=x-1;
              }
          }
        }
        else if(m<0 && m>-1)
        {
             if(ptr1->x>ptr2->x)
             {
                 assignValues(&x0,ptr1->x,&y0,ptr1->y,&x1,ptr2->x,&y1,ptr2->y);
             }
             else
             {
                 assignValues(&x0,ptr2->x,&y0,ptr2->y,&x1,ptr1->x,&y1,ptr1->y);
             }
             //printf("\n x0=%d y0=%d x1=%d y1=%d ",x0,y0,x1,y1);
             dx=x1-x0;
             dy=y1-y0;
             p=-2*dy-dx;
             for(x=x0,y=y0;x>x1-1;x--)
             {
                 if(p>0)
                 {
                     glVertex2i(x-1,y);
                     p=p-2*dy;

                 }
                 else
                 {
                     glVertex2i(x-1,y+1);
                     p=p-2*dy-2*dx;
                     y=y+1;
                 }
             }
        }
    }

void myMouse(int button, int state, int x, int y)
{
    int yy;
    char arr[50];
    yy = glutGet(GLUT_WINDOW_HEIGHT);
    y = yy - y;
    if ((button == GLUT_LEFT_BUTTON))
    {
        glBegin(GL_POINTS);
        if(first!=NULL)
        {
            if(second==NULL&&!(first->x==x&&first->y==y))
            {
              second=(Point*)malloc(sizeof(Point));
              second->x=x;
              second->y=y;
              counter=2;
              glVertex2i(x,y);
              glClear(GL_COLOR_BUFFER_BIT);
              glutPostRedisplay();
            }
        }
        else
        {

              first=(Point*)malloc(sizeof(Point));
              first->x=x;
              first->y=y;
              glVertex2i(x,y);
              counter=1;
        }
        if(first!=NULL && second!=NULL)
        {
            if(counter!=0)
            {
            drawLine(first,second);
            counter--;
            }
            else
            {
               free(first);
               free(second);
               first=NULL;
               second=NULL;
            }
        }
    }
     glEnd();
    glFlush();
}
void myInit()
{
    glClearColor(0.0, 0.5, 0.0, 0.0);//white background
    glColor3f(0.0f, 0.0f, 0.0f);//green color writing
    glPointSize(0.5f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}
void reshape(int w,int h)
    {
        glViewport(0,0,w,h);
    }
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Draw Pixl");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
