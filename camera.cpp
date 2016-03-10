#include <gl/glut.h>
#include <stdio.h>
void mydisplay();
void init();

void processKeys(unsigned char key, int x,int y);
float xdegree=0;
float ydegree=0;
float ytrans=0;
float xtrans=0;
float ztrans =0;
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("simple");
	init();
	glutKeyboardFunc(processKeys);
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
void init()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 10.0);
	//gluPerspective(1.0f,1.0f,0.1f,1.0f);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glFlush();
}
void processKeys(unsigned char key, int x,int y){

	switch(key){
	case 27:exit(0);break;
	case 'a' :xdegree+=0.1f; break;
	case 'd' :xdegree-=0.1f; break;
	case 'w' :ydegree-=0.1f; break;
	case 's' :ydegree+=0.1f; break;

	case 'i' :ytrans+=10;break;
	case 'k' :ytrans-=10;break;
	case 'j' :xtrans+=10;break;
	case 'l' :xtrans-=10;break;

	case 'm':ztrans+=60;break;
	case ',':ztrans-=10;break;
	}
	glutPostRedisplay();
}
void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f+xdegree, 0.0f+ydegree, 0.0f,
		-0.5f, -0.5f, -0.5f,
		0.0f,1.0f, 0.0f);

	glRotatef(ytrans,0,1,0);
	glRotatef(xtrans,1,0,0);
	glRotatef(ztrans,0,0,1);
	
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25f,0.25f,-0.75f);
	glVertex3f(-0.25f,0.25f,-0.75f);
	glVertex3f(-0.25f,0.25f,-0.25f);
	glVertex3f(0.25f,0.25f,-0.25f);
	glEnd();

	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25f,0.25f,-0.25f);
	glVertex3f(-0.25f,0.25f,-0.25f);
	glVertex3f(-0.25f,-0.25f,-0.25f);
	glVertex3f(0.25f,-0.25f,-0.25f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25f,0.25f,-0.75f);
	glVertex3f(0.25f,0.25f,-0.25f);
	glVertex3f(0.25f,-0.25f,-0.25f);
	glVertex3f(0.25f,-0.25f,-0.75f);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25f,-0.25f,-0.75f);
	glVertex3f(-0.25f,-0.25f,-0.75f);
	glVertex3f(-0.25f,-0.25f,-0.25f);
	glVertex3f(0.25f,-0.25f,-0.25f);
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.25f,0.25f,-0.75f);
	glVertex3f(-0.25f,0.25f,-0.75f);
	glVertex3f(-0.25f,-0.25f,-0.75f);
	glVertex3f(0.25f,-0.25f,-0.75f);
	glEnd();


	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.25f,0.25f,-0.75f);
	glVertex3f(-0.25f,0.25f,-0.25f);
	glVertex3f(-0.25f,-0.25f,-0.25f);
	glVertex3f(-0.25f,-0.25f,-0.75f);
	glEnd();
	glFlush();



}