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
	glShadeModel(GL_SMOOTH); // smoothshading�� �����Ѵ�.	

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

void KeyControl(int key, int x, int y) //��������� ��ǥ�� key���� �Է��ϴ� �Լ�
{
	if(key == GLUT_KEY_UP) //��Ű�� ������
		xRot -=5.0f;
	
	if(key == GLUT_KEY_DOWN) //�ٿ�
		xRot +=5.0f;

	if(key == GLUT_KEY_LEFT) //����Ʈ
		yRot -=5.0f;

	if(key == GLUT_KEY_RIGHT) //����Ʈ
		yRot +=5.0f;

	glutPostRedisplay(); //��ȯ�� ��ǥ������ �ٽ� �׸�
	
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
	glutSpecialFunc(KeyControl); // Ű �̺�Ʈ �߻��� keyControl�̶�� �Լ��� callback���� �θ���.
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	
}





