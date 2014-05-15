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
	glPushMatrix(); //matrix삽입
	glRotatef(xRot,1.0f,0.0f,0.0f); //x, y, z에서 x축을 기준으로 rotation 변화
	glRotatef(yRot,0.0f,1.0f,0.0f); //y축을 기준으로 각도만큼 rotation 변화
	glBegin(GL_POINTS); //점 그리기 시작함
	z=-50.0f;

	for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle +=0.1f)  
   // 3.14/0.1 개의 포인트를 뿌린다 총 3바퀴 
	{
		x = 60.0f*sin(angle); //원형의 경로를 만들기 위해, 삼각함수를 통한 x좌표
		y = 60.0f*cos(angle); //경로를 만들기 위해 삼각함수를 위한 y좌표
		glVertex3f(x,y,z);
		z +=0.5f;
	}
	glEnd(); // 점 그리기 끄
	glPopMatrix(); //변환 매트릭스 삭제
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
	glutCreateWindow("SpringVertex");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl); // 키 이벤트 발생시 keyControl이라는 함수를 callback으로 부른다.
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	
}





