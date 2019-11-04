#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef unsigned int outcode;
enum{TOP=0x1,BOTTOM=0x2,RIGHT=0x4,LEFT=0x8};

void drawBitmapText(char *string, float x, float y, float z)
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}


int ww = 640, wh = 480;  
int xi, yi, xf, yf; 
float xd1,yd1,xd2,yd2;
int xmin,ymin,xmax,ymax;
int first = 0;

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void setPixel(int x, int y) 
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void Bresenham(int x1, int y1, int x2, int y2)
{
	int dx,dy,Po;
	int k=0;
	dx=(x2-x1);
	dy=(y2-y1);
	if(dy<=dx&&dy>0)
	{
		dx=abs(dx);
		dy=abs(dy);
		Po=(2*dy)-dx;
		setPixel(x1,y1);
		int xk=x1;
		int yk=y1;
		for(k=x1;k<x2;k++)
		{ 
			if(Po<0)
			{	
				setPixel(++xk,yk);
				Po=Po+(2*dy);
			}
			else
			{
				setPixel(++xk,++yk);
				Po=Po+(2*dy)-(2*dx);
			}
		}
	}
  	else if(dy>dx&&dy>0)
  	{
 		dx=abs(dx);
 		dy=abs(dy);
 		Po=(2*dx)-dy;
 		setPixel(x1,y1);
 		int xk=x1; 
		int yk=y1;
 		for(k=y1;k<y2;k++)
 		{ 
   			if(Po<0)
			{	
				setPixel(xk,++yk);
				Po=Po+(2*dx);
			}
   			else
			{
				setPixel(++xk,++yk);
				Po=Po+(2*dx)-(2*dy);
			}
 		}	
	}
	
	else if(dy>=-dx)
	{
		dx=abs(dx);
		dy=abs(dy);
		Po=(2*dy)-dx;
		setPixel(x1,y1);
		int xk=x1;
		int yk=y1;
		for(k=x1;k<x2;k++)
		{ 
			if(Po<0)
			{	
				setPixel(++xk,yk);
				Po=Po+(2*dy);
			}
			else
			{
				setPixel(++xk,--yk);
				Po=Po+(2*dy)-(2*dx);
			}
		}
	}
	else if(dy<-dx)
	{
		dx=abs(dx);
		dy=abs(dy);
		Po=(2*dx)-dy;
		setPixel(x1,y1);
		int xk=x1;
		int yk=y1;
		for(k=y1;k>y2;k--)
		{ 
			if(Po<0)
			{	
				setPixel(xk,--yk);
				Po=Po+(2*dx);
			}
			else
			{
				setPixel(++xk,--yk);
				Po=Po+(2*dx)-(2*dy);
			}
		}
	}
	glFlush();
}
	
	
outcode CompOutCode(int x, int y)
{
    outcode code=0;
    if(y>ymax)
        code|=TOP;
    if(y<ymin)
        code|=BOTTOM;
    if(x>xmax)
        code|=RIGHT;
    if(x<xmin)
        code|=LEFT;
    return code;
}	

void cohen_Line()
{
	
	int x0, y0, x1, y1;
	x0 = xi;
	y0 = yi;
	x1 = xf;
	y1 = yf;
    outcode outcode0,outcode1,outcodeout;
    int accept = 0, done = 0;
    outcode0=CompOutCode(xi,yi);
    outcode1=CompOutCode(xf,yf);
    cout<<"outcode0="<<outcode0<<endl;
    cout<<"outcode1="<<outcode1<<endl;
    do
    {
        if(outcode0==0 && outcode1==0)
        {
            accept=1;
            done=1;
        }
        else if(outcode0 & outcode1)
            {
                done=1;
            }
            else
            {
              	int x,y;
                int ocd=outcode0 ? outcode0:outcode1;
                if(ocd & TOP)
                {
                    x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
                    y=ymax;
                }
                else if(ocd & BOTTOM)
                {
                    x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
                    y=ymin;
                }
                else if(ocd & LEFT)
                {
                    y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
                    x=xmin;
                }
                else
                {
                    y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
                    x=xmax;
                }
                if(ocd==outcode0)
                {
                    x0=x;
                    y0=y;
                    outcode0=CompOutCode(x0,y0);
                }
                else
                {
                    x1=x;
                    y1=y;
                    outcode1=CompOutCode(x1,y1);
                }
            }

    }while(done==0);

    if(accept==1)
    {
        	glColor3f(1.0, 1.0, 0.0);
			glFlush();
			Bresenham( x0, y0, x1, y1);
    }
}

void radomWindow()
{
	int flag=0;
	while(flag==0)
	{
		int randomX=(rand()%500)-250;
		int randomY=(rand()%500)-250;
		if(randomX<270&&randomX>-320)
		{
				glClear(GL_COLOR_BUFFER_BIT);
				glColor3f(0.0,0.0,1.0);
				glFlush();
				Bresenham( xi, yi, xf, yf);
				xmin=randomX;
				xmax=randomX+70;
				ymin=randomY;
				ymax=randomY+130;
				glColor3f(1.0 , 0.0, 0.0);
				glBegin(GL_LINE_LOOP);
				glVertex2i(xmin, ymin);
				glVertex2i(xmax, ymin);
				glVertex2i(xmax, ymax);
				glVertex2i(xmin, ymax);
				glEnd();
				glFlush();
				cohen_Line(); 
				delay(1);
		}
	}
}

//when key pressed for Clipping window
void keyboardkey(unsigned char key,int x,int y)
{

    glClear(GL_COLOR_BUFFER_BIT);
    if(key==32)
    {
        radomWindow();
    }
    
}
//Initial display method
void draw(void)
{

  glColor3f(1.0f, 0.0f, 1.0f); 
  drawBitmapText("Divyanshu Singh Chauhan", 20, 10, 0);
  drawBitmapText("500060640", 20, 30, 0);
  Bresenham( 0, 480, 0, 640);
  glutSwapBuffers();
  glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y) 
{

    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    	{ 
	        switch(first)  
	        {  
		        case 0:  
				        xi = x-(ww/2);  
				        yi = (wh/2)-y; 
				        first = 1;  
				        break;  
		        case 1:  
				        xf = x-(ww/2);  
				        yf = (wh/2)-y;
						if(xi>xf)
						{
							 int temp=xi;
							 xi=xf;
							 xf=temp;  
							 temp=yi;
							 yi=yf;
							 yf=temp;  
						} 
						//generateCodeForPoints();
		        first = 2;
		        break;
            }  
    	}  
	glutPostRedisplay();
}  

void init() 
{  
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(ww , wh );
  glutCreateWindow("Viva");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,0.0);
  gluOrtho2D(-(ww/2),(ww/2),-(wh/2),(wh/2)); 
}

void display()
{

}

int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMouseFunc(mouse); 
  glutKeyboardFunc(keyboardkey); 
  glutMainLoop();
  return 0;
}
