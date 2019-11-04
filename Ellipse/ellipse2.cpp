#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

int xc,yc,x1,y11,x2,y2;
int a,b;
int flag=0;
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
void drawDot(int x, int y, float r, float g, float b)
{
	glColor3f(r,g,b);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void symmetricPixels(int x,int y,float r,float g, float b)
{
	drawDot(xc+x,yc+y,r,g,b);
	drawDot(xc-x,yc+y,r,g,b);
	drawDot(xc+x,yc-y,r,g,b);
	drawDot(xc-x,yc-y,r,g,b);	
}
void Ellipse(float r,float g, float b1)
{
	
	//drawing axes
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(0,250);
	glVertex2i(500,250);
	glVertex2i(250,0);
    glVertex2i(250,500);
	glEnd();

	//plot origin
	glColor3f(0.1,1.0,0.1);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(250,250);
	glEnd();
	glColor3f(1.0,0.0,0.0);

	int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
	aSq=a*a;
	bSq=b*b;
	twoASq=2*aSq;
	twoBSq=2*bSq;
	d=bSq-b*aSq+aSq/4;
	dx=0;
	dy=twoASq*b;
	x=0;
	y=b;
	symmetricPixels(x,y,r,g,b1);
	while(dx<dy)
	{
		x++;
		dx+=twoBSq;
		if(d>=0)
		{
			y--;
			dy-=twoASq;			
		}
		if(d<0)
			d+=bSq+dx;
		else
			d+=bSq+dx-dy;
		symmetricPixels(x,y,r,g,b1);
	}
	d=(int)(bSq*(x+0.5)*(x+0.5)+aSq*(y-1)*(y-1)-aSq*bSq);
	while(y>0)
	{
		y--;
		dy-=twoASq;
		if(d<=0)
		{
			x++;
			dx+=twoBSq;
		}
		if(d>0)
			d+=aSq-dy;
		else
		d+=aSq-dy+dx;
		symmetricPixels(x,y,r,g,b1);
	}
	glFlush();
}

void ellipsey()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
void func(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		 if(flag==0)
		{
			x1=x;
			y11=500-y;
			flag++;
		}
		else if(flag==1)
		{
			x2=x;
			y2=500-y;
			xc=x1;;
			yc=y2;
			flag=0;
			
			//drawing axes
		/*	glColor3f(1.0,0.0,0.0);
			glBegin(GL_LINES);
			glVertex2i(0,yc);
			glVertex2i(500,yc);
			glVertex2i(xc,500);
    		glVertex2i(xc,0);
			glEnd(); */
			
			//drawing point
			glColor3f(0.1,1.0,0.1);
			glPointSize(5);
			glBegin(GL_POINTS);
			glVertex2i(xc,yc);
			glEnd();
			glColor3f(1.0,0.0,0.0);
			
			
			printf("%d%d\n",xc,yc);
			printf("%d%d\n",x1,y11);
			printf("%d%d\n",x2,y2);
			int distance2x=(x2-xc)*(x2-xc);
			int distance2y=(y2-yc)*(y2-yc);
			a=int(sqrt(distance2x+distance2y));
			int distance1x=(x1-xc)*(x1-xc);
			int distance1y=(y11-yc)*(y11-yc);
			b=int(sqrt(distance1x+distance1y));
			printf("%d%d\n",a,b);
			Ellipse(0,1,1);			
		}
	}
}
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(500,500);
	glutCreateWindow("ellipse");
	init();
	glutMouseFunc(func);
	glutDisplayFunc(ellipsey);	
	glutMainLoop();
	return 0;
}
