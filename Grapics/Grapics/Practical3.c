#include <gl/glut.h>
#include <math.h>

#define GL_PI 3.1415f
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void SetupRC()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f); 
	glColor3f(0.0f,1.0f,0.0f);
} 
void RenderScene(void)
{
	GLfloat length = 50.0f;

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH); // smoothshading을 시작한다.	

	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);


	//rear
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(length, length, -length);
	glColor3ub(0,255,0);
	glVertex3f(-length, length, -length);
	glColor3ub(0,0,255);
	glVertex3f(-length, -length, -length);
	glColor3ub(255,0,0);
	glVertex3f(length, -length, -length);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(length, length, length);	
	glColor3ub(0,255,0);
	glVertex3f(-length, length, length);
	glColor3ub(0,0,255);
	glVertex3f(-length, -length, length);	
	glColor3ub(255,0,0);
	glVertex3f(length, -length, length);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(length, length, length);
	glColor3ub(255,0,0);
	glVertex3f(-length, length, length);
	glColor3ub(0,255,0);
	glVertex3f(-length, length, -length);
	glColor3ub(0,0,255);
	glVertex3f(length, length, -length);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(length, -length, length);	
	glColor3ub(255,0,0);
	glVertex3f(-length, -length, length);	
	glColor3ub(0,255,0);
	glVertex3f(-length, -length, -length);
	glColor3ub(0,0,255);
	glVertex3f(length, -length, -length);
	glEnd();

	//right
	glBegin(GL_QUADS);	
	glColor3ub(255,0,0);
	glVertex3f(length, -length, -length);		
	glColor3ub(0,255,0);
	glVertex3f(length, length, -length);
	glColor3ub(0,255,0);
	glVertex3f(length, length, length);
	glColor3ub(255,0,255);
	glVertex3f(length, -length, length);

	glEnd();

	//left
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(-length, -length, -length);
	glColor3ub(0,255,0);
	glVertex3f(-length, length, -length);
	glColor3ub(0,255,0);
	glVertex3f(-length, length, length);
	glColor3ub(0,0,255);
	glVertex3f(-length, -length, length);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void KeyControl(int key, int x, int y) //윈도우상의 좌표와 key값을 입력하는 함수
{
	if(key == GLUT_KEY_UP) //업키를 받으면
		xRot -=5.0f;
	
	if(key == GLUT_KEY_DOWN) //다운
		xRot +=5.0f;

	if(key == GLUT_KEY_LEFT) //래프트
		yRot -=5.0f;

	if(key == GLUT_KEY_RIGHT) //라이트
		yRot +=5.0f;

	glutPostRedisplay(); //변환된 좌표값으로 다시 그림
	
}

void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w ,h );

	if(w<=h)
		glOrtho(-nRange,nRange,-nRange*h/w,nRange*h/w,-nRange, nRange);
	else
		glOrtho(-nRange*w/h,nRange*w/h,-nRange,nRange,-nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0); // add
	glutInitWindowSize(512,512); // add
	glutCreateWindow("PracticalProblem2_1");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl); // 키 이벤트 발생시 keyControl이라는 함수를 callback으로 부른다.
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	
}





