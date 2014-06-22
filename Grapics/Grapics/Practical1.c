#include <Windows.h>
#include <gl/glut.h>

GLfloat x1 = 40.0f;
GLfloat y1 = 20.0f;
GLsizei rsize = 50.0f;
//���簢�� ��ġ�� ũ���� �ʱⰪ ����
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
//x,y�� �������� ������ �Ÿ� ����

GLfloat x2 = -60.0f;
GLfloat y2 = 20.0f;
GLfloat xstep2 = 1.0f;
GLfloat ystep2 = 1.0f;
//2��° �簢��

GLfloat x3 = -110.0f;
GLfloat y3 = -60.0f;
GLfloat xstep3 = 1.0f;
GLfloat ystep3 = 1.0f;
//3��° �簢��

GLfloat x4 = -10.0f;
GLfloat y4 = -60.0f;
GLfloat xstep4 = 1.0f;
GLfloat ystep4 = 1.0f;
//4��° �簢��


GLfloat window_width;
GLfloat window_height;
//������ ũ�� ����



void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT); //���� ���۸� clear�Ѵ�.
	
	/* �ѿ� ū �簢���� �׸��� ���� */
	glColor3f(1.0f, 0.0f, 0.0f); //�׸��� �׸� ������ ����
	glColor3f(1.0f, 0.2f, 0.3f);
	glRectf(x1, y1, x1+rsize, y1+rsize); //�簢���� �׸���
	glColor3f(0.1f, 1.0f, 0.6f);
	glRectf(x2, y2, x2+rsize, y2+rsize); //�� ��° �簢���� �׸�
	glColor3f(0.9f, 1.0f, 0.3f);
	glRectf(x3, y3, x3+rsize, y3+rsize); //�� ��° �簢���� �׸���
	glColor3f(0.1f, 0.2f, 0.9f);
	glRectf(x4, y4, x4+rsize, y4+rsize); //�� ��° �簢���� �׸�


	/* ū �簢�� �ȿ� ���� �簢���� �׸��� ���� */
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
		
	/* �� �ٲ㼭 */
	glColor3f(0.0f, 0.25f, 0.3f);
	glRectf(x2+10, y2+10, x2+rsize-10, y2+rsize-10);

	/* �� �ٲ㼭 */
	glColor3f(0.2f, 0.3f, 0.5f);
	glRectf(x3+10, y3+10, x3+rsize-10, y3+rsize-10);
	

	/* �� �ٲ㼭 */
	glColor3f(0.5f, 0.1f, 0.1f);
	glRectf(x4+10, y4+10, x4+rsize-10, y4+rsize-10);
	


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

	/* �� ��° �簢�� �̵���� Ȯ�� */

	if(x2>window_width-rsize || x2<-window_width) xstep2 = -xstep2; // x�� ����
	if(y2>window_height -rsize || y2< -window_height) ystep2 = -ystep2; //y�� ����
	if(x2 > window_width-rsize) x2 = window_width-rsize-1;
	if(y2 >window_height-rsize) y2 = window_height-rsize-1;
	
	x2 +=xstep2;
	y2 +=ystep2;

	/* �� ��° �簢�� �̵���� Ȯ�� */

	if(x3>window_width-rsize || x3<-window_width) xstep3 = -xstep3; // x�� ����
	if(y3>window_height -rsize || y3< -window_height) ystep3 = -ystep3; //y�� ����
	if(x3 > window_width-rsize) x3 = window_width-rsize-1;
	if(y3 >window_height-rsize) y3 = window_height-rsize-1;
	
	x3 +=xstep3;
	y3 +=ystep3;
	
	/* �� ��° �簢�� �̵���� Ȯ�� */

	if(x4>window_width-rsize || x4<-window_width) xstep4 = -xstep4; // x�� ����
	if(y4>window_height -rsize || y4< -window_height) ystep4 = -ystep4; //y�� ����
	if(x4 > window_width-rsize) x4 = window_width-rsize-1;
	if(y4 >window_height-rsize) y4 = window_height-rsize-1;
	
	x4 +=xstep4;
	y4 +=ystep4;

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
