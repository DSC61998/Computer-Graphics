#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>

typedef struct
   {
       int x;
       int y;
   }Point;
   int counter=2;
   int a=1;
   typedef struct{ GLubyte red, green, blue; } Pixel;
   Pixel oldColor={0.0,0.0,1.0};
   struct Subject
      {
          Point*point;
          struct Subject*next;
      };
     typedef struct Subject Subject;
     Subject*hs=NULL;
     void display()
    {
        if(a==1)
        {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
         a=0;
        }
    }
    void insertSubjectPoint(Subject*head,int x,int y)
       {
           Subject*ptr=(Subject*)malloc(sizeof(Subject));
           ptr->point=(Point*)malloc(sizeof(Point));
               ptr->point->x=x;
               ptr->point->y=y;
               ptr->next=NULL;
               printf("\n kya yaha tak phoncha");
           if(head==NULL)
           {
               printf("\n head was null");
               hs=ptr;
               printf("\n %u",hs);
           }
           else
           {
               printf("\n entering in the else condition");
               Subject*temp=head;
               while(temp->next!=NULL)
               {
                   temp=temp->next;
               }
               temp->next=ptr;
           }
           printf("\n insert subject polyfgonnnnnnnnnnnnnnnnnnnnnn are %d %d",ptr->point->x,ptr->point->y);
       }

void myMouse(int button ,int state,int x,int y)
    {
         int actualHeight;
           actualHeight=glutGet(GLUT_WINDOW_HEIGHT)-y;
            counter--;
            printf("\n value of counter is %d",counter);
           if(button==GLUT_LEFT_BUTTON&&counter==0)
           {
                glBegin(GL_POINTS);
                printf("\n andar aaya");
                glVertex2i(x,actualHeight);
                printf("\n x = %d actual height=%d",x,actualHeight);
                insertSubjectPoint(hs,x,actualHeight);
                counter=2;
                glEnd();
                glFlush();
           }
    }
    applyFloodFill4(int x,int y,Pixel oldColor)
        {
            glColor3f(1.0,0.0,0.0);
            Pixel currentColor;
            glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &currentColor);
            if(currentColor.red==oldColor.red&&currentColor.blue==oldColor.blue&&currentColor.green==oldColor.green)
            {
                glBegin(GL_POINTS);
                glVertex2i(x,y);
                glEnd();
                applyFloodFill4(x+1,y,oldColor);
                applyFloodFill4(x-1,y,oldColor);
                applyFloodFill4(x,y+1,oldColor);
                applyFloodFill4(x,y-1,oldColor);
            }
        }
    void myBoard(GLubyte key,GLint xMouse, GLint yMouse)
        {
            Subject*temp2=hs;
            switch(key)
               {
               case 13:
                   glClear(GL_COLOR_BUFFER_BIT);
                   glFlush();
                   glBegin(GL_LINE_LOOP);

                     while(temp2!=NULL)
                     {
                         glVertex2i(temp2->point->x,temp2->point->y);
                         temp2=temp2->next;
                     }
                   glEnd();
                   glFlush();
                 break;
               case 'c':

                   applyFloodFill4(100,100,oldColor);
                   break;
               default:
                break;
               }
        }
    void init()
      {
       glClearColor(0.5,0.0,0.0,1.0);
        glColor3f(0.0,0.0,1.0);
        gluOrtho2D(0.0f, 700.0f, 0.0f, 500.0f);
      }

int main(int argc,char**argv)
   {
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowSize(700,500);
      glutInitWindowPosition(300,100);
      glutCreateWindow("Flood Fill algorithm");
      init();
      glutDisplayFunc(display);
      glutMouseFunc(myMouse);
      glutIdleFunc(display);
      glutKeyboardFunc(myBoard);
      glutMainLoop();
       return 0;
   }
