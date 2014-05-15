#include <Windows.h>
#include <gl/glut.h>
void RenderScence(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //���� Ŭ���� �۾��� �����Ѵ�.
	glColor3f(1.0f, 0.0f, 0.0f); //�簢���� �׸� ������ ����
	glRectf(0.0f, 0.0f, 50.0f, 30.0f); // solid�� �簢���� (x1, y1)���� (x2, y2)���� �׸���. ä������ �⺻ ������ ���(1.0f, 1.0f, 1.0f)�̴�.
	glFlush(); //queue�� ä���� ��ɾ���� �����Ѵ�.
}

void SetupRC(void) //rendering���� ������ openGL�ʱ�ȭ �۾��̴�. �����츦 clear�ϱ� ���� ������ �����Ѵ�.
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //�����츦 clear�� ������ �����Ѵ�. 
}

void ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0,0,w,h); //openGL�� ������ �׸��� �׸��� �� ����ϴ� ������ �����Ѵ�. ��, viewPort�� �����. 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //openGL�� ����ڰ� �������ǿ� ���õ� ����� �����߰�, �� ����� �ʱ�ȭ�ϱ� ���� ������ķ� �������.
	if(w<=h)
		glOrtho(-100.0f,100.0f,-100.0f, 100.0f,1.0f,-1.0f); //3���� ĵ������ �����. ���� ���� ��ǥ�� �����ϰ�, ����Ʈ ����Ʈ ���� ž �Ͼ� �� ���̴�.
	else
		glOrtho(-100.0f,100.0f, -100.0f, 100.0f, 1.0f, -1.0f);
	//OrthoGrapic �� ����� ����. �ڵ尡 �˾Ƽ� �� ������ ũ�⸦ ������� ��.

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(void)
{
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //�̱� ������ ���۷�, ��� ����� ����� ȭ�鿡 ��Ÿ�� ������󿡼� ����
		glutCreateWindow("Rectangle"); //glutAPI�� ����� ������ â�� �����Ѵ�.
		glutDisplayFunc(RenderScence); //�����츦 �׸� ������ glut�� ����� RenderScence�� �ݹ��Լ��� ȣ���Ѵ�.
		glutReshapeFunc(ChangeSize); //�ݹ��Լ��� �����쿡�� '���࿡ ����ڰ� �����쿡 ������ �� ����� �ٽ� �����ϸ� ���� ���� �� �Լ��� os�� �ҷ�'��� �������ִ� �Լ�
		SetupRC();
		glutMainLoop(); //�޽���, Ű���� �Է� �� �ü���� ������ ��� ������ ���α׷��� ����ɶ����� ó���Ѵ�.

}