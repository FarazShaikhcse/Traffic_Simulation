#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<string.h>
#define GLUT_DISABLE_ATEXIT_HACK;
static float firstWindow,secWindow,thirdW;
void init()
{

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);

}
void drawText(char* string,int x, int y)
{
int len, i;
glRasterPos2f(x,y);
len=(int) strlen(string);
for(i = 0; i < len; i++)
{
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}
}
void drawTitle(char* string,int x, int y)
{
int len, i;
glRasterPos2f(x,y);
len=(int) strlen(string);
for(i = 0; i < len; i++)
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
}
}
void nextbutton()
{

    float x1=35.0,y1=7.0,x2=41.0,y2=7.0,x3=35.0,y3=12.0,x4=41.0,y4=12.0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);

	glVertex2f(x4,y4);
	glVertex2f(x3,y3);
	glEnd();

}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    nextbutton();
    glColor3f(0.0,0.0,1.0);
    drawTitle("Traffic Signal Simulation",11,40);
    glColor3f(1.0,0.0,0.0);

    drawText("Dhvanith Unadkat         4NM17CS058",6,19);
    drawText("Disha Ganesh Bhat        4NM17CS059",6,17);
    drawText("Dsouza Mark Melvin       4NM17CS060",6,15);
    drawText("Faraz Shabbir Shaikh     4NM17CS058",6,13);
    drawText("Next",36,9);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2i(16,39);
    glVertex2i(33,39);
    glEnd();
    glFlush();

}
void click(int button,int state,int x,int y)
{


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
//printf("qwert");

x=x/25;
y=y/50;
printf("x=%d-y=%d",x,y);
        if((x>=14 && x<17)&&(y>=7 && y<12))
        {
            //printf("mf");
            createnewwindow();
        }
        glutPostRedisplay();
    }
}
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<100;i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void tree(){

    glColor3ub(68, 83, 2);
    circle(3.5,3,32,12);

    //body
    glColor3ub(68, 43, 2);
    glBegin(GL_QUADS);
        glVertex2d(31,36);
        glVertex2d(33,36);
        glVertex2d(34,11);
        glVertex2d(30,11);
    glEnd();
    //leaves
    glColor3ub(11, 70, 11);
    circle(3,4,27,37);
    circle(3,4,30,39);
    circle(3,4,32,37);
    circle(3,4,35,39);
    circle(3,4,36,35);
    circle(3,4,36,31);
    circle(3,4,32,33);
    circle(3,4,29,32);
    circle(3,4,27,34);

    //fruits
    glColor3ub(255, 165, 0);
    circle(.5,1,25,37);
    circle(.5,1,27,39);
    circle(.5,1,30,41);
    circle(.5,1,33,39);
    circle(.5,1,35,41);
    circle(.5,1,37,39);
    circle(.5,1,38,35);
    circle(.5,1,37,31);
    circle(.5,1,35,35);
    circle(.5,1,32,35);
    circle(.5,1,29,36);
    circle(.5,1,26,33);
    circle(.5,1,28,32);
}
void road(){
    /*//Background
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-6,6);
    glVertex2f(6,6);
    glVertex2f(6,-6);
    glVertex2f(-6,-6);
    glEnd();
*/
    // Horizontal Road
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0,60);
    glVertex2f(100,60);
    glVertex2f(100,45);
    glVertex2f(0,45);
    glEnd();

    // Horizontal Stripes
    glColor3f(0,0,0);

    for(float x1=0;x1<=100;x1+=0.4){


        glBegin(GL_POLYGON);
        glVertex2f(0.2+x1,52);
        glVertex2f(x1,51);
        glVertex2f(x1,52);
        glVertex2f(0.2+x1,51);
        glEnd();
    }

    // Vertical road
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(42,0);
    glVertex2f(57,0);
    glVertex2f(57,100);
    glVertex2f(42,100);
    glEnd();

    //Vertical Stripes
    glColor3f(0,0,0);

    for(float y1=0;y1<=100;y1+=1){
        glBegin(GL_POLYGON);
        glVertex2f(50,y1+0.2);

        glVertex2f(51,y1);
        glVertex2f(50,y1);
        glVertex2f(51,y1+0.2);
        glEnd();
    }
}
void carsv(float lrIndex)
{
     glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 26 - 2, 7);
    glVertex2f(lrIndex + 30 + 2, 7);
    glVertex2f(lrIndex + 30 + 2, 5);
    glEnd();
    //Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 1);
    glVertex2f(lrIndex + 26 - 2, 3);
    glVertex2f(lrIndex + 30 + 2, 3);
    glVertex2f(lrIndex + 30 + 2, 1);
    glEnd();
    //Car Body
    glColor3f(0.678, 1.000, 0.184);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26, 1);
    glVertex2f(lrIndex + 26, 8);
    glColor3f(0.000, 0.545, 0.545);

    glVertex2f(lrIndex + 28, 10);
    glVertex2f(lrIndex + 30, 8);
    glVertex2f(lrIndex + 30, 1);
    glEnd();
}
void simulation()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f,1.0f,1.0f);
tree();
road();
carsv(25);
    glFlush();

}
void createnewwindow()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(750,750);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(firstWindow);
	secWindow=glutCreateWindow("Traffic simulation");
	glutDisplayFunc(simulation);
	initSecondWindow();



}

void initSecondWindow(void)
{

	glClearColor(0.0,0.75,0.0,0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,100,0,100,0,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
/*
void backclick(int button,int state,int x,int y)
{
x=x/10;


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {printf("%d--%d",x,y);
        if((x>=3 && x<=11)&&(y>=45 && y<=72))
        {
            goback();
        }
        glutPostRedisplay();
    }
}
void goback()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200,1200);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(secWindow);
	thirdW=glutCreateWindow("Traffic simulation");
	glutDisplayFunc(display);
	glutMouseFunc(click);
	//glutKeyboardFunc(keySecond);
	init();
}*/
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(10,20);
glutInitWindowSize(500,500);
firstWindow=glutCreateWindow("Traffic simulation");
init();
glutDisplayFunc(display);
glutMouseFunc(click);
glutMainLoop();
}
