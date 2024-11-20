/*
#include <GL/glut.h>
 #include<iostream>
 using namespace std;
 
 int first=0;
 int x1,y1,x2,y2;
 int x3,y3,x4,y4;
 int pt=0;
 
  void init()
 {
 	glClearColor(0,0,0,0);
 	gluOrtho2D(-320,320,-240,240);
 }
 
 void drawQuadrants()//for display 4 quadrants
 {
 	glBegin(GL_LINES);
 		glVertex2i(-320,0);
 		glVertex2i(320,0);
 		glVertex2i(0,-240);
 		glVertex2i(0,240);
 	glEnd();
 }
 
 void drawLine(int x1,int y1,int x2,int y2)
 {
 	glBegin(GL_LINES);
 		glVertex2i(x1,y1);
 		glVertex2i(x2,y2);
 	glEnd();
 }
 
 void dda()
 {
 	float length;
 	if(abs(x4-x3) > abs(y4-y3))
	{
 		length = abs(x4-x3);
 	}
 	else
	{
		length = abs(y4-y3);
 	}
 
 	float dx = (x4-x3)/length;
 	float dy = (y4-y3)/length;
 	
 	float x = x3 + 0.5;
 	float y = y3 + 0.5;
 	
	int i =1;
 	int flag = 1;
 	while( i<= length)
	{
 		if( i%4 == 0 ) 		 // Check if current iteration is multiple of 4
		{
 			if( flag == 0) 		// If flag is 0, it means we are inside a dash
			{
 				flag = 1;  		// Set flag to 1, indicating we are outside a dash
 			}
			else  			// If flag is 1, it means we are outside a dash
			{
 				glBegin(GL_POINTS);
 				glVertex2i(x,y);  			// Draw a point
 				glEnd();
 				flag = 0;  			// Set flag to 0, indicating we are inside a dash
 			}
 		}
 		else  				// If current iteration is not a multiple of 4
		{
			if( flag == 1)   		// If flag is 1, it means we are outside a dash
			{
 				glBegin(GL_POINTS);
 				glVertex2i(x,y);  			// Draw a point
 				glEnd();
 			}
 		}
 
 		x =x+dx; 		  // Increment x by dx
 		y =y+dy;  		 // Increment y by dy
 		i = i + 1;   		// Increment iteration counter
 	}
 	
 }
 
 void display()
 {
 	glClear(GL_COLOR_BUFFER_BIT);
 	drawQuadrants();
 	dda();
 	glFlush();
 }
 
void mouse(int btn,int state,int x,int y)
{
 	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
 	{
 		if(pt==0)
 		{
 			x1=x-320;
 			y1=240-y;
 			pt=1;
 		}
 		else
 		{
 			x2=x-320;
 			y2=240-y;
 			drawLine(x1,y1,x2,y2);
 			pt=0;
 		}
 	}
 	glFlush();
 }
 
 int main(int argc,char** argv)
 {
 	cout<<"Enter the value of x3,y3,x4,y4"<<endl;
 	cin>>x3;
 	cin>>y3;
 	cin>>x4;
 	cin>>y4;
 	
 	glutInit(&argc,argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 	glutInitWindowSize(640,480);
 	glutCreateWindow("Draw Line With Mouse Click");
 	init();
 	glutDisplayFunc(display);
	glutMouseFunc(mouse);
 	glutMainLoop();
	return 0;
}
*/


 #include <GL/glut.h>
 #include<iostream>
 using namespace std;
 
 int first=0;
 int x1,y1,x2,y2;
 int x3,y3,x4,y4;
 int pt=0;
 
  
 void init()
 {
 	glClearColor(0,0,0,0);
 	gluOrtho2D(-320,320,-240,240);
 }
 
 void drawQuadrants()//for display 4 quadrants
 {
 	glBegin(GL_LINES);
 		glVertex2i(-320,0);
 		glVertex2i(320,0);
 		glVertex2i(0,-240);
		glVertex2i(0,240);
 	glEnd();
 }
 
 void drawLine(int x1,int y1,int x2,int y2)
 {
 	glBegin(GL_LINES);
 		glVertex2i(x1,y1);
 		glVertex2i(x2,y2);
 	glEnd();
 }
 
 void bresenham()
{
 	int x = x3;
 	int y = y3;
 	
 	float dx = x4-x3;
 	float dy = y4- y3;
 	
 	float m = dy/dx;
 	float e = m- 0.5;
 	
 	int flag = 1;
 	
	for ( int i =0; i < dx ; i++)
	{
 		if( i%4 == 0 )
		{
 			if( flag == 0)
			{
 				flag = 1;
 			}
			else
			{
 				glBegin(GL_POINTS);
 				glVertex2i(x,y);
 				glEnd();
 				flag = 0;
 			}
 		}
 		else
		{
			if( flag == 1)
			{
 				glBegin(GL_POINTS);
 				glVertex2i(x,y);
 				glEnd();
 			}
 		}
 
 		while ( e>0)
		{
 			y =y+1;
 			e =e-1;
 		}
 		x =x+1;
 		e =e+m;
 	}
 }
 
 void display()
 {
 	glClear(GL_COLOR_BUFFER_BIT);
 	drawQuadrants();
 	//dda();
 	bresenham();
 	//glFlush();
 }
 
 void mouse(int btn,int state,int x,int y)
 {
 	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
 	{
 		if(pt==0)
 		{
 			x1=x-320;
 			y1=240-y;
 			pt=1;
 		}
 		else
 		{
 			x2=x-320;
 			y2=240-y;
 			drawLine(x1,y1,x2,y2);
 			pt=0;
 		}
 	}
 	glFlush();
 }
 
 int main(int argc,char** argv)
 {
 	cout<<"Enter the value of x3,y3,x4,y4"<<endl;
 	cin>>x3;
 	cin>>y3;
 	cin>>x4;
 	cin>>y4;
 	
 	glutInit(&argc,argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 	glutInitWindowSize(640,480);
 	glutCreateWindow("Draw Line With Mouse Click");
 	init();
 	glutDisplayFunc(display);
 	glutMouseFunc(mouse);
 	glutMainLoop();
 	return 0;
 }


/*
When i % 4 == 0, it means we have reached the end of a dash or gap.
If flag is 0, it means we were inside a dash, so we change flag to 1, indicating that we are now outside the dash.
If flag is 1, it means we were outside a dash, so we draw a point (to represent the end of the dash) and change flag to 0, indicating that we are now inside a dash.
When i % 4 is not 0, it means we are inside a dash or gap, and we continue drawing points.
If flag is 1, it means we are outside a dash, so we draw points continuously to represent the gap.
*/
 