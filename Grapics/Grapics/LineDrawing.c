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
	glBegin(GL_LINES); //공간상에서 선을 그리는 함수. 기본 요소로 선을 선택한 후에 glVertex3f를 두 번 호출해서 선을 그린다.
	z = 0.0f;
	for(angle = 0.0f; angle<GL_PI; angle +=(GL_PI/20.0f)) { //20개의 선을 그리겠다는 의미
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





