
//code for face

#include <iostream>
#include <GL/glut.h>
using namespace std;

int x,y,d1,s,s1,limit;
int m,n,m1,n1,m2,n2;
int r,r1,r2;

void init()
{
	glClearColor(1,1,1,1);
	gluOrtho2D(-320,320,-240,240);
}

void drawquad()
{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2i(-320,0);
		glVertex2i(320,0);
		glVertex2i(0,-240);
		glVertex2i(0,240);
	glEnd();
	glFlush();
}

void mh(int &x,int &y, int &d1)
{
	x=x+1;
	d1=d1+2*x+1;
}

void md(int &x,int &y, int &d1)
{
	x=x+1;
	y=y-1;
	d1=d1+2*x-2*y+2;
}

void mv(int &x,int &y, int &d1)
{
	y=y-1;
	d1=d1-2*y+1;
}

void nose()
{
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2i(m,n-5);
		glVertex2i(m,n-40);
	glEnd();
	glFlush();
}

void mouth()
{
	glColor3f(0,1,0);
	glBegin(GL_LINES);
		glVertex2i(m-40,n-60);
		glVertex2i(m+40,n-60);
	glEnd();
	glFlush();
}

void bresnham()
{
	x=0;
	y=r;
	d1=2*(1-r);
	limit=0;

	while(y>=limit)
	{
		glColor3f(0,0,1);	
		glBegin(GL_POINTS);
			glVertex2i(x+m,y+n);
			glVertex2i(-x+m,y+n);
			glVertex2i(x+m,-y+n);
			glVertex2i(-x+m,-y+n);
		glEnd();
		
		if(d1<0)
		{
			s=2*d1+2*y-1;
			if(s<=0)
			{		
				mh(x,y,d1);
			}
			else
			{
				md(x,y,d1);
			}
		}
		else if(d1>0)
		{
			s1=2*d1-2*x-1;
			if(s1<=0)
			{
				md(x,y,d1);
			}
			else
			{
				mv(x,y,d1);
			}
		}
		else if(d1==0)
		{
			md(x,y,d1);
		}
	}
	nose();
	mouth();
}

void bresnham1()
{
	x=0;
	y=r1;
	d1=2*(1-r1);
	limit=0;

	while(y>=limit)
	{
		glColor3f(1,0,1);
		glBegin(GL_POINTS);
			glVertex2i(x+m1,y+n1);
			glVertex2i(-x+m1,y+n1);
			glVertex2i(x+m1,-y+n1);
			glVertex2i(-x+m1,-y+n1);
		glEnd();
		
		if(d1<0)
		{
			s=2*d1+2*y-1;
			if(s<=0)
			{		
				mh(x,y,d1);
			}
			else
			{
				md(x,y,d1);
			}
		}
		else if(d1>0)
		{
			s1=2*d1-2*x-1;
			if(s1<=0)
			{
				md(x,y,d1);
			}
			else
			{
				mv(x,y,d1);
			}
		}
		else if(d1==0)
		{
			md(x,y,d1);
		}
	}
}

void bresnham2()
{
	x=0;
	y=r2;
	d1=2*(1-r2);
	limit=0;

	while(y>=limit)
	{
		glColor3f(0,1,1);
		glBegin(GL_POINTS);
			glVertex2i(x+m2,y+n2);
			glVertex2i(-x+m2,y+n2);
			glVertex2i(x+m2,-y+n2);
			glVertex2i(-x+m2,-y+n2);
		glEnd();
		
		if(d1<0)
		{
			s=2*d1+2*y-1;
			if(s<=0)
			{		
				mh(x,y,d1);
			}
			else
			{
				md(x,y,d1);
			}
		}
		else if(d1>0)
		{
			s1=2*d1-2*x-1;
			if(s1<=0)
			{
				md(x,y,d1);
			}
			else
			{
				mv(x,y,d1);
			}
		}
		else if(d1==0)
		{
			md(x,y,d1);
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		drawquad();
		bresnham();
		bresnham1();
		bresnham2();
	glFlush();
}

int main(int argc,char ** argv)
{
	cout<<"Enter The Coordinates of Big Circle: ";
	cin>>m>>n;
	cout<<"Enter the Radius of Big circle: ";
	cin>>r;

	cout<<"Enter the Coordinates of Eye 1: ";
	cin>>m1>>n1;
	cout<<"Enter the Radius of Eye 1: ";
	cin>>r1;
	
	cout<<"Enter the Coordinates of Eye 2: ";
	cin>>m2>>n2;
	cout<<"Enter the Radius of Eye 2: ";
	cin>>r2;

	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Face");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}




/*
//Man 

#include <iostream>
#include <GL/glut.h>
using namespace std;

int r,m,n;

void init()
{
	glClearColor(1,1,1,1);
	gluOrtho2D(-320,320,-240,240);
	
}

void draw()
{
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2i(-320,0);
		glVertex2i(320,0);
		glVertex2i(0,-240);
		glVertex2i(0,240);
	glEnd();	
}

void mh(int	&x1,int	&Y1,int	&d1)
{
	x1=x1+1;
	d1=d1+2*x1+1;
}

void md(int	&x1,int	&Y1,int	&d1)
{
	x1=x1+1;
	Y1=Y1-1;
	d1=d1+2*x1-2*Y1+2;
}

void mv(int	&x1,int	&Y1,int	&d1)
{
	Y1=Y1-1;
	d1=d1-2*Y1+1;
}

void bresnham()
{
	int x1=0;
	int Y1=r;
	int d1=2*(1-r);
	int limit=0;
	
	while(Y1>=limit)
	{
		glColor3f(1,0,0);
		glBegin(GL_POINTS);
			glVertex2i(x1+m,Y1+n);
			glVertex2i(-x1+m,Y1+n);
			glVertex2i(x1+m,-Y1+n);
			glVertex2i(-x1+m,-Y1+n);
		glEnd();
		
		if(d1<0)
		{
			int s1=(2*d1)+(2*Y1)-1;
			
			if(s1<=0)
			{
				mh(x1,Y1,d1);
			}
			else
			{
				md(x1,Y1,d1);
			}
		}
		else if(d1>0)
		{
			int s2=(2*d1)-(2*x1)-1;
			
			if(s2<=0)
			{
				md(x1,Y1,d1);
			}
			else
			{
				mv(x1,Y1,d1);
			}
		}
		else if(d1==0)
		{
			md(x1,Y1,d1);
		}
	}
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		draw();
		bresnham();
		
		glColor3f(0,1,0);
		glBegin(GL_LINES);
			glVertex2i(m,n-r);
			glVertex2i(m,10);
		glEnd();
		
		glColor3f(0,0,1);
		glBegin(GL_LINES);
			glVertex2i(m,n-(r+10));
			glVertex2i(m-10,n-(r+20));
		glEnd();

		glColor3f(1,0,1);
		glBegin(GL_LINES);
			glVertex2i(m,n-(r+10));
			glVertex2i(m+10,n-(r+20));
		glEnd();
	
		glColor3f(0,1,1);
		glBegin(GL_LINES);
			glVertex2i(m,n-(r+40));
			glVertex2i(m-10,n-(r+48));
		glEnd();
	
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2i(m,n-(r+40));
			glVertex2i(m+10,n-(r+48));
		glEnd();
		
	glFlush();
}

int main(int argc,char **argv)
{
	cout<<"Enter Center: ";
	cin>>m>>n;
	cout<<"Enter Radius: ";
	cin>>r;
	
	glutInit(&argc,argv);
	glutInitWindowSize(640,280);
	glutInitWindowPosition(100,100);
	glutCreateWindow("CG03");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

*/