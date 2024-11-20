#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define PIE 3.1415
using namespace std;

int n;
float xt,yt;

void init()
{
	glClearColor(0,0,0,0);
	gluOrtho2D(-320,320,-240,240);
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

void koch(float x1,float y1,float x4,float y4,int n)
{
	float x2,x3,y2,y3,midx,midy;
	
	x2=(2*x1+x4)/3;
	x3=(2*x4+x1)/3;
	
	y2=(2*y1+y4)/3;
	y3=(2*y4+y1)/3;
	
	double angle=(-60*PIE)/180;
	midx=x2+ ((x3-x2)*cos(angle)) + ((y3-y2)*sin(angle));
	midy=y2- ((x3-x2)*sin(angle)) + ((y3-y2)*cos(angle));
	
	if(n>0)
	{
		koch(x1,y1,x2,y2,n-1);
		koch(x2,y2,midx,midy,n-1);
		koch(midx,midy,x3,y3,n-1);
		koch(x3,y3,x4,y4,n-1);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(midx,midy);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();
	}
}

void bezier()																	
{
	cout<<"Enter the four Coordinates: "<<endl;
	double xx1,yy1,xx2,yy2,xx3,yy3,xx4,yy4;
	cin>>xx1>>yy1>>xx2>>yy2>>xx3>>yy3>>xx4>>yy4;
	
	for(double u=0.0;u<1.0;u+=0.005)
	{
		xt=(xx4*pow(u,3))+(3*xx3*pow(u,2)*(1-u))+(3*xx2*u*pow(1-u,2))+(xx1*pow(1-u,3));
		yt=(yy4*pow(u,3))+(3*yy3*pow(u,2)*(1-u))+(3*yy2*u*pow(1-u,2))+(yy1*pow(1-u,3));
		
		glBegin(GL_POINTS);
		glVertex2f(xt,yt);
		glEnd();
	}
	glBegin(GL_LINES);
		glVertex2f(xx1,yy1);
		glVertex2f(xx2,yy2);
		glVertex2f(xx3,yy3);
		glVertex2f(xx4,yy4);
	glEnd();
}

 
void reshape(int w, int h) 
{ 
    glViewport(0, 0, w, h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-w/2, w/2, -h/2, h/2); 
    glMatrixMode(GL_MODELVIEW); 
}

void draw()
{
	int ch;
	cout<<"1.Bezier \n2/Koch \nChoose the Option: ";
	cin>>ch;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	switch(ch)
	{
		case 1:
			{
				drawquad();
				bezier();
				break;
			}
		case 2:
			{
				cout<<"Enter the Number of Iterations: ";
				cin>>n;
				float w=glutGet(GLUT_WINDOW_WIDTH);
				float h=glutGet(GLUT_WINDOW_HEIGHT);
				koch(-400,0,400,0,n);
				break;
			}
	}
	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);	
	glutCreateWindow("Curves");
	
	init();
	 
	glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}








