#include <iostream>
#include <GL/glut.h>
using namespace std;

int x1,x2,Y1,y2;
int xx1,xx2,yy1,yy2;
float x,y,dx,dy;
float length;
int pt;

void init()
{
	glClearColor(0,0,0,0);
	gluOrtho2D(-320,320,-240,240);
}

void drawline(int xx1,int yy1,int xx2,int yy2)
{
	glBegin(GL_LINES);
		glVertex2i(xx1,yy1);
		glVertex2i(xx2,yy2);
	glEnd();
	glFlush();
}

void drawquad()
{
	glBegin(GL_LINES);
		glVertex2i(-320,0);
		glVertex2i(320,0);
		glVertex2i(0,-240);
		glVertex2i(0,240);
	glEnd();
}

void DDA()
{
	if(abs(x2-x1)>abs(y2-Y1))
	{
		length=abs(x2-x1);
	}
	else
	{
		length=abs(y2-Y1);
	}
	
	dx=(x2-x1)/length;
	dy=(y2-Y1)/length;
	
	x=x1+0.5;
	y=Y1+0.5;
	
	int i=0;
	int flag=1;
	while(i<=length)
	{
		if(i%4==0)
		{
			if(flag==0)
			{
				flag=1;
			}
			else
			{
				glBegin(GL_POINTS);
					glVertex2i(x,y);
				glEnd();
				flag=0;
			}
		}
		else
		{
			if(flag==1)
			{
				glBegin(GL_POINTS);
					glVertex2i(x,y);
				glEnd();
			}
		}
			
		x=x+dx;
		y=y+dy;
		i=i+1;		
	}
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		drawquad();
		DDA();
	glFlush();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(pt==0)
		{
			xx1=x-320;
			yy1=240-y;
			pt=1;
		}
		else
		{
			xx2=x-320;
			yy2=240-y;
			drawline(xx1,yy1,xx2,yy2);
			pt=0;
		}
	}
	glFlush();
}

int main(int argc, char** argv) 
{
	cout<<"Enter the coordinates of line: ";
	cin>>x1>>Y1>>x2>>y2;
	
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("DDA Line Drawing");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}










