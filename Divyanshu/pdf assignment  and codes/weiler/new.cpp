
#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>
int counter=2;
int a=1;
int keyPressed=0;
int doIntersect=1;
typedef struct
   {
       int x;
       int y;
   }Point;
   struct Subject
      {
          Point*point;
          struct Subject*next;
      };
   struct NewPolygon
      {
        Point*point;
        struct NewPolygon*next;
      };
      typedef struct NewPolygon NewPolygon;
      NewPolygon*nw=NULL;
    typedef struct Subject Subject;
Point*minClip=NULL;
Point*maxClip=NULL;
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
 void init()
    {
        glClearColor(0.5,0.0,0.0,1.0);
        glColor3f(0.0,0.0,1.0);
        //glPointSize(1.5f);
        gluOrtho2D(0.0f, 700.0f, 0.0f, 500.0f);
    }
    void reshape(int w,int h)
       {
           glViewport(0,0,w,h);
       }
void insertNewPolygon(int x,int y)
          {
                NewPolygon*ptr=(NewPolygon*)malloc(sizeof(NewPolygon));
           ptr->point=(Point*)malloc(sizeof(Point));
               ptr->point->x=x;
               ptr->point->y=y;
               ptr->next=NULL;
               printf("\n kya yaha tak phoncha");
           if(nw==NULL)
           {
               printf("\n head was null");
               nw=ptr;
               printf("\n %u",nw);
           }
           else
           {
               printf("\n entering in the else condition");
               NewPolygon*temp=nw;
               while(temp->next!=NULL)
               {
                   temp=temp->next;
               }
               temp->next=ptr;
           }
           printf("\n new NEW polygondbdbsdjkdbvsdvbdvdvbdvjbdvbjdvbjdvb are %d %d",ptr->point->x,ptr->point->y);
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

        void myMouse(int button, int state,int x,int y)
       {
           int actualHeight;
           actualHeight=glutGet(GLUT_WINDOW_HEIGHT)-y;
            counter--;
            printf("\n value of counter is %d",counter);
           if(button==GLUT_LEFT_BUTTON&&counter==0&&keyPressed==0)
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
           else if(keyPressed==1&&counter==0)
           {

                if(minClip==NULL)
                {
                    printf("\n enter in the keypressed if");
                glBegin(GL_POINTS);
                glVertex2i(x,actualHeight);
                 glEnd();
               glFlush();
                    minClip=(Point*)malloc(sizeof(Point));
                    minClip->x=x;
                    minClip->y=actualHeight;
                }
                else if(maxClip==NULL)
                {
                    printf("\n enter in the keypressed if");
                glBegin(GL_POINTS);
                glVertex2i(x,actualHeight);
                 glEnd();
               glFlush();
                    maxClip=(Point*)malloc(sizeof(Point));\
                     maxClip->x=x;
                    maxClip->y=actualHeight;
                    glBegin(GL_LINE_LOOP);
                     glVertex2i(minClip->x,minClip->y);
                     glVertex2i(maxClip->x,minClip->y);
                     glVertex2i(maxClip->x,maxClip->y);
                      glVertex2i(minClip->x,maxClip->y);
                     glEnd();
                     glFlush();
                     printf("\n value of minClipx%d minclipy%d maxclipx%d maxclipy%d",minClip->x,minClip->y,maxClip->x,maxClip->y);
                }
                else{}
              counter=2;
           }
       }
       int code(float x,float y)
          {
            int xmax=maxClip->x;
    int xmin=minClip->x;
    int ymax=maxClip->y;
    int ymin=minClip->y;
              int c=0;
              if(y>ymax)
                c=8;
              if(y<ymin)
                c=4;
              if(x>xmax)
                c=c|2;
              if(x<xmin)
                c=c|1;
              return c;
          }
  void cohen_Line(float x1,float y1,float x2,float y2)
    {
        int xmax=maxClip->x;
    int xmin=minClip->x;
    int ymax=maxClip->y;
    int ymin=minClip->y;
    int A,B,C,D;
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    A=x1;B=y1;C=x2;D=y2;
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
           return;
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           A=x;
           B=y;
           c1=code(A,B);
       }

       if(c==c2)
       {
           C=x;
           D=y;
           c2=code(C,D);
       }
       printf("\n A=%d B=%d C=%d D=%d",A,B,C,D);
}
if(doIntersect==1)
{
 if(A==xmin||A==xmax||B==ymin||B==ymax)
  {
      printf("\n ABCDEFGHIJKLMNOP");
    insertNewPolygon(A,B);
    if(C==xmin||C==xmax||D==ymin||D==ymax)
    {
        insertNewPolygon(C,D);
        doIntersect=1;

    }
    else
    {
        insertNewPolygon(C,D);
        doIntersect=0;
    }
  }
  else if(C==xmin||C==xmax||D==ymin||D==ymax)
  {
      //insertNewPolygon(A,B);
      //above line is added at 255
      insertNewPolygon(C,D);
      doIntersect=0;
  }
  else
  {
      insertNewPolygon(A,B);
      insertNewPolygon(C,D);
  }
}
else if(doIntersect==0)
{
    if(A==xmin||A==xmax||B==ymin||B==ymax)
    {
        insertNewPolygon(A,B);
       // insertNewPolygon(C,D);
        doIntersect=1;
        if(C==xmin||C==xmax||D==ymin||D==ymax)
        {
            insertNewPolygon(C,D);
            doIntersect=0;
        }
    }
    else if(C==xmin||C==xmax||D==ymin||D==ymax)
    {
        insertNewPolygon(C,D);
        doIntersect=1;
    }
    else
    {
        insertNewPolygon(C,D);
        doIntersect=0;
    }
}
}
     void applyWeinerClipping(Subject*head)
         {

             Subject*temp=hs;
             printf("\n value of temp is%u",temp);
            while(temp!=NULL)
            {
                printf("\n value of temp is%u",temp);
                if(temp->next==NULL)
                {
                    Point*p1=temp->point;
                Point*p2=head->point;
                cohen_Line(p1->x,p1->y,p2->x,p2->y);
                break;
                }
                Point*p1=temp->point;
                Point*p2=temp->next->point;
                printf("\n HELOOABACAFA");
                cohen_Line(p1->x,p1->y,p2->x,p2->y);
                temp=temp->next;
            }

            NewPolygon*temp1=nw;

            //glClearColor(1.0f,0.0f,0.0f,1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            glBegin(GL_LINE_LOOP);
                     glVertex2i(minClip->x,minClip->y);
                     glVertex2i(maxClip->x,minClip->y);
                     glVertex2i(maxClip->x,maxClip->y);
                      glVertex2i(minClip->x,maxClip->y);
                     glEnd();
                     glFlush();
                 glBegin(GL_POLYGON);
            while(temp1!=NULL)
            {
                    glVertex2i(temp1->point->x,temp1->point->y);
                     printf("\n x and y of New Polygon are %d %d",temp1->point->x,temp1->point->y);
                 temp1=temp1->next;

            }
                    glEnd();
                    glFlush();
         }
      void myBoard(GLubyte key,GLint xMouse, GLint yMouse)
        {
            Subject*temp2=hs;
            switch(key)
               {
               case 13:
                   glClear(GL_COLOR_BUFFER_BIT);
                   glFlush();
                   glBegin(GL_POLYGON);

                     while(temp2!=NULL)
                     {
                         glVertex2i(temp2->point->x,temp2->point->y);
                         temp2=temp2->next;
                     }
                     keyPressed=1;
                   glEnd();
                   glFlush();
                 break;
               case 'c':
                   applyWeinerClipping(hs);
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
      glutCreateWindow("Weiler implementation code");
      init();
      glutDisplayFunc(display);
      glutMouseFunc(myMouse);
      glutIdleFunc(display);
      glutReshapeFunc(reshape);
      glutKeyboardFunc(myBoard);
      glutMainLoop();
       return 0;
   }
