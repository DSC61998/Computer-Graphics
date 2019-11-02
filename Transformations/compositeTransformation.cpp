#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include <cmath>

using namespace std;

int flag=0;

float cal_sin(float n) 
{     
    float accuracy = 0.0001, denominator, sinx, sinval; 
      
    // Converting degrees to radian 
    n = n * (3.142 / 180.0);  
  
    float x1 = n; 
      
    // maps the sum along the series 
    sinx = n;          
      
    // holds the actual value of sin(n) 
    sinval = sin(n);     
    int i = 1; 
    do
    { 
        denominator = 2 * i * (2 * i + 1); 
        x1 = -x1 * n * n / denominator; 
        sinx = sinx + x1; 
        i = i + 1; 
    } while (accuracy <= fabs(sinval - sinx)); 
    return sinx;
} 

float cal_cos(float n) 
{ 
    float accuracy = 0.0001, x1, denominator, cosx, cosval; 
      
    // Converting degrees to radian 
    n = n * (3.142 / 180.0); 
      
    x1 = 1; 
      
    // maps the sum along the series 
    cosx = x1;          
      
    // holds the actual value of sin(n) 
    cosval = cos(n); 
    int i = 1; 
    do
    { 
        denominator = 2 * i * (2 * i - 1); 
        x1 = -x1 * n * n / denominator; 
        cosx = cosx + x1; 
        i = i + 1; 
    } while (accuracy <= fabs(cosval - cosx)); 
    return cosx; 
} 
 

float matrix[3][3]={{-100, 50, 1},{100, 50, 1},{0, 100, 1}};
void logics(int flag);

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}

void display()
{
			//drawing axes
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(0,500);
	glVertex2i(0,-500);
	glVertex2i(-500,0);
	glVertex2i(500,0);
	glEnd();
	glFlush();				
}

void ScanMenu(int id)
{
	if (id == 1)
	flag = 1;
	if (id == 2)
	flag = 2;
	if (id == 3)
	flag = 3;
	if (id == 4)
	flag = 4;
	if (id == 5)
	flag = 5;
	logics(flag);
	glutPostRedisplay();
}

void logics(int flag)
{
	if(flag==1)
	{
		//triangle
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		glColor3f(1.0 ,1.0 ,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
		
		
		int tx,ty,xt1,yt1,xt2,yt2,xt3,yt3;
		cout << "Enter the value of tx ";
		cin >> tx;
		cout <<"Enter the value of ty ";
		cin >> ty;
		
		float a[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
		float ans[3][3];
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[i][j]=0;
		 		for(int k=0;k<3;k++)
		 		{
		  			ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
		 		}	
			}
		}
		
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	}
		
	if(flag==2)
	{
	//triangle
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
			
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
		float theta;
		cout<<"Enter the value of theta if rotating clockwise plzz put -sign  ";
		cin>>theta;
		cout<<"sin(theta): "<<cal_sin(theta)<<endl<<"cos(theta) :"<<cal_cos(theta)<<endl; 
		
		float sinx;
		float cosx;
		
		if(theta == 0)
		{
			sinx = 0;
			cosx = 1;
		}
		else if(theta == 1)
		{
			sinx = 1;
			cosx = 1;
		}
		else
		{
			sinx = cal_sin(theta);
			cosx = cal_cos(theta);
		}
		float a[3][3]={{cosx, sinx, 0},{(-1) * sinx, cosx, 0},{ 0, 0, 1}};
		
		//converting degree into theta
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		
		float ans[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<3;k++)
				{
				  ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
				}
			}
		}
		
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	}
	
	
	if(flag==3)
	{
	//triangle
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
			
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
		int sx,sy;
		cout<<"Enter Sx :";
		cin>>sx;
		cout<<"Enter Sy :";
		cin>>sy;
		
		float a[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
		float ans[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[i][j]=0;
		 		for(int k=0;k<3;k++)
		 		{
		  			ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
		 		}
			}
		}
		
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	}		
	
	
	if(flag==4)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
			
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
		float m,ic;
		cout<<"Enter the slope ";
		cin>>m;
		cout<<"Enter the intercept ";
		cin>>ic;
		
		float a1=(1-m*m)/(1+m*m);
		float b=2*m/(m*m+1);
		float c=-2*ic*m/(m*m+1);
		float d=2*ic/(m*m+1);
		float a[3][3]={{a1,b,0},{b,-a1,0},{c,d,1}};
		float ans[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[i][j]=0;
		 		for(int k=0;k<3;k++)
		 		{
		  			ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
		 		}
			}
		}
		
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	
	
	}
	
	if(flag==5)
	{
	//triangle
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
			
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	
		float shx,shy;
		cout<<"Enter value of Shx :";
		cin>>shx;
		cout<<"Enter value of Shy :";
		cin>>shy;

		float a[3][3]={{1,shx,0},{shy,1,0},{0,0,1}};
		float ans[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				{
					ans[i][j]=0;
					for(int k=0;k<3;k++)
					{
						ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
					}
				}
		}
	
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
	}		
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Transformation 2D");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(ScanMenu);
	glutAddMenuEntry("translation", 1);
	glutAddMenuEntry("rotation", 2);
	glutAddMenuEntry("scaling", 3);
	glutAddMenuEntry("reflection", 4);
	glutAddMenuEntry("shear", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
