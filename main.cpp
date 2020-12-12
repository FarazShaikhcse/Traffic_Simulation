#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

int w,h,sim=0;
int car1[] = {215,5},car2[] = {5,215};

void init()
{

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);
}

void drawText(char* string,int x, int y)
{
    glColor3f(1.0, 1.0, 1.0);
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
    glColor3f(1.0, 0.0, 0.0);
    int len, i;
    glRasterPos2f(x,y);
    len=(int) strlen(string);
    for(i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
}

void road(){
    //Background
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,500);
    glVertex2f(500,500);
    glVertex2f(500,0);
    glEnd();
    
    // Horizontal Road
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0,200);
    glVertex2f(0,300);
    glVertex2f(500,300);
    glVertex2f(500,200);
    glEnd();
    
    // Vertical road
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(200,0);
    glVertex2f(200,500);
    glVertex2f(300,500);
    glVertex2f(300,0);
    glEnd();

    // Horizontal Stripes
    glColor3f(0,0,0);

    for(float x1=0;x1<=500;x1+=0.4){


        glBegin(GL_POLYGON);
        glVertex2f(0.2+x1,252);
        glVertex2f(x1,251);
        glVertex2f(x1,252);
        glVertex2f(0.2+x1,251);
        glEnd();
    }

    //Vertical Stripes
    glColor3f(0,0,0);

    for(float y1=0;y1<=500;y1+=1){
        glBegin(GL_POLYGON);
        glVertex2f(250,y1+0.2);
        glVertex2f(251,y1);
        glVertex2f(250,y1);
        glVertex2f(251,y1+0.2);
        glEnd();
    }
}

void carsv(float x,float y)
{
    //Front Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y + 17);
    glVertex2f(x - 2, y + 28);
    glVertex2f(x + 22, y + 28);
    glVertex2f(x + 22, y + 17);
    glEnd();
    //Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y + 2);
    glVertex2f(x - 2, y + 13);
    glVertex2f(x + 22, y + 13);
    glVertex2f(x + 22, y + 2);
    glEnd();
    //Car Body
    glColor3f(0.678, 1.000, 0.184);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y + 30);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(x + 10, y + 40);
    glVertex2f(x + 20, y + 30);
    glVertex2f(x + 20, y);
    glEnd();
}

void carsh(float x,float y)
{
    //Front Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(x - 17, y - 2);
    glVertex2f(x - 28, y - 2);
    glVertex2f(x - 28, y + 22);
    glVertex2f(x - 17, y + 22);
    glEnd();
    //Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y - 2);
    glVertex2f(x - 13, y - 2);
    glVertex2f(x - 13, y + 22);
    glVertex2f(x - 2, y + 22);
    glEnd();
    //Car Body
    glColor3f(1.0, 0.678, 0.184);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x - 30, y);
    glColor3f(0.545, 0.0, 0.545);
    glVertex2f(x - 40, y + 10);
    glVertex2f(x - 30, y + 20);
    glVertex2f(x, y + 20);
    glEnd();
}

void simulation(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawTitle("Welcome", 250, 250);
    road();
    carsv(car1[0], car1[1]);
    carsh(car2[0],car2[1]);
    glFlush();
}

void welcomeWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawTitle("Traffic Signal Simulation", 210,300);
    drawText("Dhvanith Unadkat         4NM17CS058",200,250);
    drawText("Disha Ganesh Bhat        4NM17CS059",200,200);
    drawText("Dsouza Mark Melvin       4NM17CS060",200,150);
    drawText("Faraz Shabbir Shaikh     4NM17CS058",200,100);
    glColor3f(1.0, 0.0, 0.0);
    drawText("Next",250,50);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(245,40);
    glVertex2i(245,70);
    glVertex2i(270,70);
    glVertex2i(270,40);
    glEnd();
    glFlush();
}
void reshape ( int width, int height ) {

    /* define the viewport transformation */
    w = width;
    h = height;
    glViewport(0,0,width,height);
}

void click(int button,int state,int x,int y)
{
    float x1 = x / (float) w * 500.0;
    float y1 = (h - y) / (float) h * 500.0;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(x1>245 && x1<270 && y1>40 && y1<70){
            sim = 1;
            glutDisplayFunc(simulation);
        }
    }
}

void idle(){
    if(sim == 1){
        car1[1] = car1[1] + 1;
        car1[1] = car1[1] % 500;
        car2[0] = 500 - car1[1];
        glutPostRedisplay();
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Traffic simulation");
    init();
    glutInitWindowPosition(0,0);
    glutReshapeFunc(reshape);
    glutMouseFunc(click);
    glutIdleFunc(idle);
    glutDisplayFunc(welcomeWindow);
    glutMainLoop();
}
