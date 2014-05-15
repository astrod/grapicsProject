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
	GLfloat sizes[2]; //지원되는 점 크기의 범위
	GLfloat step; // 지원되는 점 크기의 단계
	GLfloat curSize; //현재 점 크기
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot,1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes); //size의 범위; 최소 [0] / 최대 [1]; openGL에서 지원하는 point의 최대, 최소 크기를 반환
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); //사이즈 간격(간격을 리턴함); point Size의 간격을 반환한다. 이 함수와 위의 함수는 반드시 glBegin - glEnd 사이에서 호출되면 안 된다.
	curSize = sizes[0];
	z=-50.0f;
	for(angle = 0.0f; angle<=(2.0f*GL_PI)*3.0f; angle +=0.1f) {
		x = 60.0f*sin(angle);
		y = 60.0f*cos(angle);
		glPointSize(curSize);
		glBegin(GL_POINTS); //이 함수와 glEnd사이에 같은 타입의 기본 요소를 여러 개 나열한다.
		glVertex3f(x, y, z);
		glEnd(); //이 함수와 glBegin사이에 같은 타입의 기본 요소를 여러 개 나열한다.
		z +=0.5f;
		curSize +=step; 
	}
	
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





