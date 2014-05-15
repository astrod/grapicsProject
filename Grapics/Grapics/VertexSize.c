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
	GLfloat sizes[2]; //�����Ǵ� �� ũ���� ����
	GLfloat step; // �����Ǵ� �� ũ���� �ܰ�
	GLfloat curSize; //���� �� ũ��
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot,1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes); //size�� ����; �ּ� [0] / �ִ� [1]; openGL���� �����ϴ� point�� �ִ�, �ּ� ũ�⸦ ��ȯ
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); //������ ����(������ ������); point Size�� ������ ��ȯ�Ѵ�. �� �Լ��� ���� �Լ��� �ݵ�� glBegin - glEnd ���̿��� ȣ��Ǹ� �� �ȴ�.
	curSize = sizes[0];
	z=-50.0f;
	for(angle = 0.0f; angle<=(2.0f*GL_PI)*3.0f; angle +=0.1f) {
		x = 60.0f*sin(angle);
		y = 60.0f*cos(angle);
		glPointSize(curSize);
		glBegin(GL_POINTS); //�� �Լ��� glEnd���̿� ���� Ÿ���� �⺻ ��Ҹ� ���� �� �����Ѵ�.
		glVertex3f(x, y, z);
		glEnd(); //�� �Լ��� glBegin���̿� ���� Ÿ���� �⺻ ��Ҹ� ���� �� �����Ѵ�.
		z +=0.5f;
		curSize +=step; 
	}
	
	glPopMatrix(); //��ȯ ��Ʈ���� ����
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





