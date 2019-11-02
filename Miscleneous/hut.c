#include<GL/glut.h>
#define pi 3.142857
#include<math.h>

float theta;
void specialkey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			{
				glBegin(GL_QUAD_STRIP);
		glColor3f(0.00, 0.00, 0.00);
		glVertex2f(-100, 100);
		glVertex2f(100, 100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.00, 1.00, 0.00);
		glVertex2f(-100, -100);
		glVertex2f(100, -100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(-75, -15);
		glVertex2f(-25, -15);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-50, 50);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(25, -15);
		glVertex2f(-25, -15);
		glVertex2f(0, 50);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(100, -15);
		glVertex2f(50, -15);
		glVertex2f(75, 50);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.4, 0.3, 0.7);
		glVertex2f(-75, 25);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
		glVertex2f(-100, -50);
		glVertex2f(-50, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-85, -15);
		glVertex2f(-65, -15);
		glVertex2f(-85, -50);
		glVertex2f(-65, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.5, 0.0, 0.0);
		glVertex2f(35, -20);
		glVertex2f(50, -20);
		glVertex2f(35, -75);
		glVertex2f(50, -75);
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		float x, y, i; 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 65+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 20+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 27.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 57.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON); 
		
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 22+(3 * cos(i)); 
			y = 22+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 59+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 36+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 53+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 48+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			glColor3f(1.0, 1.0, 1.0);
			x = -80+(20 * cos(i)); 
			y = 80+(20 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();												
	
	
	//function for stars
	glBegin(GL_POINTS); 
		glVertex2f(-80, 49);
		glVertex2f(30, 60);
		glVertex2f(-40, 57);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
		glVertex2f(-80, 30);
	glEnd();												
	

	glFlush();
	break;
			}
			
					
	case GLUT_KEY_DOWN:
		{
			glBegin(GL_QUAD_STRIP);
		glColor3f(0.00, 0.00, 1.00);
		glVertex2f(-100, 100);
		glVertex2f(100, 100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.00, 1.00, 0.00);
		glVertex2f(-100, -100);
		glVertex2f(100, -100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(-75, -15);
		glVertex2f(-25, -15);
		glVertex2f(-50, 50);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(25, -15);
		glVertex2f(-25, -15);
		glVertex2f(0, 50);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(100, -15);
		glVertex2f(50, -15);
		glVertex2f(75, 50);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-75, 25);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
		glVertex2f(-100, -50);
		glVertex2f(-50, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-85, -15);
		glVertex2f(-65, -15);
		glVertex2f(-85, -50);
		glVertex2f(-65, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.5, 0.0, 0.0);
		glVertex2f(35, -20);
		glVertex2f(50, -20);
		glVertex2f(35, -75);
		glVertex2f(50, -75);
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		float x, y, i; 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 65+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 20+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < 360; i ++) 
		{  
			x = 27.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 57.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON); 
		
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 22+(3 * cos(i)); 
			y = 22+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 59+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 36+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 53+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 48+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			glColor3f(1.0, 1.0, 0.0);
			x = -80+(20 * cos(i)); 
			y = 80+(20 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();

	glFlush();
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //clearing the frame buffer
	gluOrtho2D(-100, 100, -100, 100);
	glBegin(GL_QUAD_STRIP);					//sky
		glColor3f(0.00, 0.00, 1.00);
		glVertex2f(-100, 100);
		glVertex2f(100, 100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_QUAD_STRIP);					//ground
		glColor3f(0.00, 1.00, 0.00);
		glVertex2f(-100, -100);
		glVertex2f(100, -100);
		glVertex2f(-100, -15);
		glVertex2f(100, -15);
	glEnd();
	glBegin(GL_TRIANGLES);					//1st mountain 
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(-75, -15);
		glVertex2f(-25, -15);
		glVertex2f(-50, 50);
	glEnd();
	glBegin(GL_TRIANGLES);					//2nd mountain 
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(25, -15);
		glVertex2f(-25, -15);
		glVertex2f(0, 50);
	glEnd();
	glBegin(GL_TRIANGLES);					//3rd mountain
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(100, -15);
		glVertex2f(50, -15);
		glVertex2f(75, 50);
	glEnd();
	glBegin(GL_POLYGON);					//roof of the hut
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(-75, 25);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
	glEnd();
	glBegin(GL_QUAD_STRIP);					//front face of the hut
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-100, 0);
		glVertex2f(-50, 0);
		glVertex2f(-100, -50);
		glVertex2f(-50, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);					//door of the house
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-85, -15);
		glVertex2f(-65, -15);
		glVertex2f(-85, -50);
		glVertex2f(-65, -50);
	glEnd();
	glBegin(GL_QUAD_STRIP);					
		glColor3f(0.5, 0.0, 0.0);
		glVertex2f(35, -20);
		glVertex2f(50, -20);
		glVertex2f(35, -75);
		glVertex2f(50, -75);
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		float x, y, i; 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 65+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 20+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = -10+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 27.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 57.5+(10 * cos(i)); 
			y = 16+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 35+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.5, 0.0);
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 50+(10 * cos(i)); 
			y = 42+(16 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON); 
		
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 22+(3 * cos(i)); 
			y = 22+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 42+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 59+(3 * cos(i)); 
			y = (3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 36+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 53+(3 * cos(i)); 
			y = 21+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 48+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			x = 29+(3 * cos(i)); 
			y = 37+(3 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();
	
	glBegin(GL_POLYGON); 
		for ( i = 0; i < (2 * pi); i += 0.001) 
		{  
			glColor3f(1.0, 1.0, 0.0);
			x = -80+(20 * cos(i)); 
			y = 80+(20 * sin(i)); 
			glVertex2i(x, y); 
		} 
	glEnd();

	glFlush();
}

int main(int argc , char**argv)		//used to initialize glut library
{
	glutInit(&argc, argv);	//initializing glut library
	glutInitDisplayMode(GLUT_RGB);	//initializing view mode
	
	glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);
	
	glutCreateWindow("Window 1");
	glutDisplayFunc(display);
	glutSpecialFunc(specialkey);
	
	glutMainLoop();
}
