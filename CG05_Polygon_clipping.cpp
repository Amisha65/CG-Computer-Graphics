#include <GL/glut.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int xmax, xmin, ymax, ymin;
float x[15], y[15], m[30], xx[25], yy[25];
int i, n;

void init()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
}

void getdata()
{
    cout << "Enter the Co-ordinates of Window:-" << " ";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "Enter the Number of vertices:" << " ";
    cin >> n;

    if (n < 3)
    {
        cout << "Enter the No. of vertices greater than 2";
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        cout << "Enter the Vertex:" << i + 1 << " ";
        cin >> x[i] >> y[i];
    }

    x[i] = x[0];
    y[i] = y[0];
}

void display1()
{
    	glColor3f(1.0, 0.0, 0.0);

    	glBegin(GL_POLYGON);
    	for (i = 0; i < n; i++)
    	{
       		glVertex2i(x[i], y[i]);
    	}
    	glEnd();

    	glColor3f(1.0, 1.0, 1.0);
    	glBegin(GL_LINE_LOOP);
    		glVertex2i(xmin, ymin);
   		glVertex2i(xmax, ymin);
    		glVertex2i(xmax, ymax);
    		glVertex2i(xmin, ymax);
    	glEnd();
    	glFlush();
}

void clearScreen()
{
    	sleep(2);
    	glClearColor(0.0, 0.0, 0.0, 1.0);
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void slope()
{
    	for (i = 0; i < n; i++)
    	{
        	if ((x[i + 1] - x[i]) == 0)
            		m[i] = 0;
        	else
            		m[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    }
}

void lclip()
{
    int k = 0;
    slope();
    for (i = 0; i < n; i++)
    {
        if (xmin < x[i] && xmin < x[i + 1])
        {
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
        else if (x[i] > xmin && x[i + 1] < xmin)
        {
            xx[k] = xmin;
            yy[k] = y[i] + m[i] * (xmin - x[i]);
            k++;
        }
        else if (x[i] < xmin && x[i + 1] > xmin)
        {
            xx[k] = xmin;
            yy[k] = y[i] + m[i] * (xmin - x[i]);
            k++;
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
    }
    n = k;
    for (i = 0; i < n; i++)
    {
        x[i] = xx[i];
        y[i] = yy[i];
    }
    x[i] = x[0];
    y[i] = y[0];
}

void rclip()
{
    int k = 0;
    slope();
    for (i = 0; i < n; i++)
    {
        if (x[i] < xmax && x[i + 1] < xmax)
        {
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
        else if (x[i] < xmax && x[i + 1] > xmax)
        {
            xx[k] = xmax;
            yy[k] = (m[i] * (xmax - x[i])) + y[i];
            k++;
        }
        else if (x[i] > xmax && x[i + 1] < xmax)
        {
            xx[k] = xmax;
            yy[k] = (m[i] * (xmax - x[i])) + y[i];
            k++;
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
    }
    n = k;
    for (i = 0; i < n; i++)
    {
        x[i] = xx[i];
        y[i] = yy[i];
    }
    x[i] = x[0];
    y[i] = y[0];
}

void tclip()
{
    int k = 0;
    slope();
    for (i = 0; i < n; i++)
    {
        if (y[i] < ymax && y[i + 1] < ymax)
        {
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
        else if (y[i] < ymax && y[i + 1] > ymax)
        {
            yy[k] = ymax;
            xx[k] = x[i] + (ymax - y[i]) / m[i];
            k++;
        }
        else if (y[i] > ymax && y[i + 1] < ymax)
        {
            yy[k] = ymax;
            xx[k] = x[i] + (ymax - y[i]) / m[i];
            k++;
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
    }
    n = k;
    for (i = 0; i < n; i++)
    {
        x[i] = xx[i];
        y[i] = yy[i];
    }
    x[i] = x[0];
    y[i] = y[0];
}

void bclip()
{
    int k = 0;
    slope();
    for (i = 0; i < n; i++)
    {
        if (y[i] > ymin && y[i + 1] > ymin)
        {
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
        else if (y[i] > ymin && y[i + 1] < ymin)
        {
            yy[k] = ymin;
            xx[k] = x[i] + (ymin - y[i]) / m[i];
            k++;
        }
        else if (y[i] < ymin && y[i + 1] > ymin)
        {
            yy[k] = ymin;
            xx[k] = x[i] + (ymin - y[i]) / m[i];
            k++;
            xx[k] = x[i + 1];
            yy[k] = y[i + 1];
            k++;
        }
    }
    n = k;
    for (i = 0; i < n; i++)
    {
        x[i] = xx[i];
        y[i] = yy[i];
    }
    x[i] = x[0];
    y[i] = y[0];
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    	display1();
    clearScreen();
    	lclip();
    	display1();
    clearScreen();
    	rclip();
    	display1();
    clearScreen();
    	tclip();
    	display1();
    clearScreen();
    	bclip();
    	display1();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    getdata();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

 //(40 140 ),(150,240),(250,150),(170,80)