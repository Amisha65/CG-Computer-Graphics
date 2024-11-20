#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

float A[3][3];
float B[3][3];
float C[3][3];

void init()
{
	glClearColor(0,0,0,0);
	gluOrtho2D(-320,320,-240,240);
}

void drawQuad()
{
	glBegin(GL_LINES);
		glVertex2i(-320,0);
		glVertex2i(320,0);
		glVertex2i(0,-240);
		glVertex2i(0,240);
	glEnd();
	glFlush();
}

void drawpoly(float final[3][3])
{
	glBegin(GL_POLYGON);
		for(int i=0;i<3;i++)
		{
			glVertex2f(final[i][0],final[i][1]);
		}
	glEnd();
}

void input()
{
	cout<<"Enter the values of Cordinates of Polygon: "<<endl;
	for(int  i=0;i<3;i++)
	{
		cin>>A[i][0];
		cin>>A[i][1];
		A[i][2]=1;
	}
}

void multiply()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			C[i][j]=0;
			for(int k=0;k<3;k++)
			{
				C[i][j]+= A[i][k]* B[k][j];
			}

		}
	}
}

void scaling()
{
	float sx,sy;
	cout<<"Enter the values Scaling factors: "<<endl;
	cin>>sx>>sy;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			B[i][j]=0;
		}
	}
	B[0][0]=sx;
	B[1][1]=sy;
	B[2][2]=1;
	multiply();
	
	cout<<"Final Product of Scaling: "<<endl;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}

}

void translation()
{
    float tx, ty;
    cout << "Enter the values Translation factors: " << endl;
    cin >> tx >> ty;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                B[i][j] = 1;
            }
            else
            {
                B[i][j] = 0;
            }
        }
    }

    B[0][2] = tx;
    B[1][2] = ty;

    multiply();

    cout << "Final Product of Transformation: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}



void rotation()
{
	float a;
	cout<<"Enter the Angle of Rotation: "<<endl;
	cin>>a;
	
	float b=(a*3.14)/180;
	B[0][0]=cos(b);
	B[0][1]=-sin(b);
	B[1][0]=sin(b);
	B[1][1]=cos(b);
	B[2][2]=1;
	
	multiply();
	cout<<"Final Product of Rotation: "<<endl;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void reflectionX()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
			{
				B[i][j]=1;
			}
			else
			{
				B[i][j]=0;
			}
		}
	}
	B[1][1]=-1;
	multiply();
	
	cout<<"Final Product of Reflaction about X: "<<endl;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void reflectionY()
{
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			if(i==j)
				B[i][j]=1;
			else
				B[i][j]=0;
		}
	}
	B[0][0]=-1;
	multiply();
	
	cout<<"Final Product of Reflection about Y: "<<endl;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void reflectionXY()
{
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			if(i==j)
				B[i][j]=-1;
			else
				B[i][j]=0;
		}
	}
	B[2][2]=1;
	multiply();
	
	cout<<"Final Product of Reflaction about XY:  "<<endl;
	for(int  i=0;i<3;i++)
	{
		for(int  j=0;j<3;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		drawQuad();
		glColor3f(0,1,0);
		drawpoly(A);
		glColor3f(0,0,1);
		drawpoly(C);
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Translation");
	init();
	
	input();
	int ch;
	cout<<"1.Scaling \n2.Transformation \n3.Rotation \n4.Reflection \n5.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			scaling();
			break;
		case 2:
			translation();
			break;
		case 3:
			rotation();
			break;
		case 4:
			int c;
			cout<<"1.X \n2.Y \n3.XY "<<endl;
			cin>>c;
			switch(c)
			{
				case 1:
					reflectionX();
					break;
				case 2:
					reflectionY();
					break;
				case 3:
					reflectionXY();
					break;
			}
			break;
		case 5:
			exit(0);
	}
	
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
		
		
//(100,100,1),(200,100,1),(150,200,1)		
			

	