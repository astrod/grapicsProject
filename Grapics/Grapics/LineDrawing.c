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
	GLfloat x,y,z,angle;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES); //�����󿡼� ���� �׸��� �Լ�. �⺻ ��ҷ� ���� ������ �Ŀ� glVertex3f�� �� �� ȣ���ؼ� ���� �׸���.
	z = 0.0f;
	for(angle = 0.0f; angle<GL_PI; angle +=(GL_PI/20.0f)) { //20���� ���� �׸��ڴٴ� �ǹ�
		x= 50.0*sin(angle);
		y =50.0*cos(angle);
		glVertex3f(x,y,z);
		x = 50.0f*sin(angle+GL_PI);
		y =50.0f*cos(angle+GL_PI);
		glVertex3f(x,y,z);
	}
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
	glutCreateWindow("SpringVertex");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl); // Ű �̺�Ʈ �߻��� keyControl�̶�� �Լ��� callback���� �θ���.
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	
}





