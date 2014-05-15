#include <Windows.h>
#include <gl/glut.h>

GLfloat x1 =0.0f;
GLfloat y1 = 0.0f;
GLsizei rsize = 50.0f;
//���簢�� ��ġ�� ũ���� �ʱⰪ ����
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
//x,y�� �������� ������ �Ÿ� ����

GLfloat x2 = -80.0f;
GLfloat y2 = -50.0f;


GLfloat window_width;
GLfloat window_height;
//������ ũ�� ����

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT); //���� ���۸� clear�Ѵ�.
	
	glColor3f(1.0f, 0.0f, 0.0f); //�׸��� �׸� ������ ����
	glRectf(x1, y1, x1+rsize, y1+rsize); //�簢���� �׸���
	glRectf(x2, y2, x2+rsize, y2+rsize); //�� ��° �簢���� �׸�

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
	glColor3f(1.0f, 0.0f, 0.0f); //�׸��� �׸� ������ ����
	glRectf(x1, y1, x1+rsize, y1+rsize); //�簢���� �׸���
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
	glColor3f(1.0f, 0.0f, 0.0f); //�׸��� �׸� ������ ����
	glRectf(x1, y1, x1+rsize, y1+rsize); //�簢���� �׸���
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
	glutSwapBuffers(); //�� ���� �����ӹ��۸� ���� ������ ���۸� ü�������ش�.
}

void TimerFunction(int value) { //�ݹ��Լ��� glutTimerFunc���� ȣ���Ѵ�.
	if(x1>window_width-rsize || x1<-window_width) xstep = -xstep; // x�� ����
	if(y1>window_height -rsize || y1< -window_height) ystep = -ystep; //y�� ����
	if(x1 > window_width-rsize) x1 = window_width-rsize-1;
	if(y1 >window_height-rsize) y1 = window_height-rsize-1;
	//�����찡 ����Ǿ� ��踦 �Ѿ�� ��

	x1 +=xstep;
	y1 +=ystep;

	if(x2>window_width-rsize || x2<-window_width) xstep = -xstep; // x�� ����
	if(y2>window_height -rsize || y2< -window_height) ystep = -ystep; //y�� ����
	if(x2 > window_width-rsize) x2 = window_width-rsize-1;
	if(y2 >window_height-rsize) y2 = window_height-rsize-1;
	//�����찡 ����Ǿ� ��踦 �Ѿ�� ��

	x2 +=xstep;
	y2 +=ystep;


	glutPostRedisplay(); //glut���̺귯���� ������ �����츦 refreah�ϰ� ��. ��, glutDisplayFunc�� ȣ����.
	glutTimerFunc(33,TimerFunction,1);
}



void SetupRC(void) { //������ ���¸� �������ش�.
	glClearColor(1.0f,1.0f,1.0f,1.0f); //Ŭ������ ������ �������ش�.
}
void ChangeSize(GLsizei w, GLsizei h) { //������ ����� �ٲ� ������ �ݹ��Լ��� ȣ���Ҳ���
	glViewport(0,0,w,h); //����Ʈ ũ�� �����ϰ�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h) //����Ʈ ���̿� ����, Ŭ���� ������ �������ִ� �Լ�
	{	window_width = 100.0f;
		window_height = 100.0f*h/w;
		glOrtho (-100.0f, 100.0f, -window_height, window_height, 1.0, -1.0);
	}
	else
	{	window_width = 100.0f*w/h;
		window_height = 100.0f;
		glOrtho (-window_width, window_width, -100.0f, 100.0f, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); }

void main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//framebuffer�� �ΰ� ����Ұǵ�
	glutInitWindowSize(800,600); //�����Ҷ� ������ ������� 800*600�̰�
	glutCreateWindow("BounceRectangle"); //�����츦 �����ϰ�
	glutDisplayFunc(RenderScene);  //���÷��� �ݹ��Լ��� �����ؼ�, ��� ȣ���Ѵ�.
	glutReshapeFunc(ChangeSize);   //������ ũ�Ⱑ ����ɶ����� ȣ���Ѵ�.
	glutTimerFunc(2000,TimerFunction,1);  // �� ó������ 2000ms�Ŀ� TimerFunction�� ���Ѵ�. �� ���Ŀ��� �� �Լ� �ȿ��� 33ms���� ���Ѵ�.
    SetupRC();
	glutMainLoop();  	
}
