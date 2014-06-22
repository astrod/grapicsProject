#include <Windows.h>
#include <gl/glut.h>

GLfloat x1 = 40.0f;
GLfloat y1 = 20.0f;
GLsizei rsize = 50.0f;
//정사각형 위치와 크기의 초기값 설정
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
//x,y축 방향으로 움직일 거리 설정

GLfloat x2 = -60.0f;
GLfloat y2 = 20.0f;
GLfloat xstep2 = 1.0f;
GLfloat ystep2 = 1.0f;
//2번째 사각형

GLfloat x3 = -110.0f;
GLfloat y3 = -60.0f;
GLfloat xstep3 = 1.0f;
GLfloat ystep3 = 1.0f;
//3번째 사각형

GLfloat x4 = -10.0f;
GLfloat y4 = -60.0f;
GLfloat xstep4 = 1.0f;
GLfloat ystep4 = 1.0f;
//4번째 사각형


GLfloat window_width;
GLfloat window_height;
//윈도우 크기 설정



void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT); //이전 버퍼를 clear한다.
	
	/* 겉에 큰 사각형을 그리는 과정 */
	glColor3f(1.0f, 0.0f, 0.0f); //그림을 그릴 색상을 지정
	glColor3f(1.0f, 0.2f, 0.3f);
	glRectf(x1, y1, x1+rsize, y1+rsize); //사각형을 그리고
	glColor3f(0.1f, 1.0f, 0.6f);
	glRectf(x2, y2, x2+rsize, y2+rsize); //두 번째 사각형을 그림
	glColor3f(0.9f, 1.0f, 0.3f);
	glRectf(x3, y3, x3+rsize, y3+rsize); //세 번째 사각형을 그리고
	glColor3f(0.1f, 0.2f, 0.9f);
	glRectf(x4, y4, x4+rsize, y4+rsize); //네 번째 사각형을 그림


	/* 큰 사각형 안에 작은 사각형을 그리는 과정 */
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
		
	/* 색 바꿔서 */
	glColor3f(0.0f, 0.25f, 0.3f);
	glRectf(x2+10, y2+10, x2+rsize-10, y2+rsize-10);

	/* 색 바꿔서 */
	glColor3f(0.2f, 0.3f, 0.5f);
	glRectf(x3+10, y3+10, x3+rsize-10, y3+rsize-10);
	

	/* 색 바꿔서 */
	glColor3f(0.5f, 0.1f, 0.1f);
	glRectf(x4+10, y4+10, x4+rsize-10, y4+rsize-10);
	


	glutSwapBuffers(); //두 개의 프레임버퍼를 쓰기 때문에 버퍼를 체인지해준다.
}

void TimerFunction(int value) { //콜백함수로 glutTimerFunc에서 호출한다.
	if(x1>window_width-rsize || x1<-window_width) xstep = -xstep; // x축 범위
	if(y1>window_height -rsize || y1< -window_height) ystep = -ystep; //y축 범위
	if(x1 > window_width-rsize) x1 = window_width-rsize-1;
	if(y1 >window_height-rsize) y1 = window_height-rsize-1;
	//윈도우가 변경되어 경계를 넘어갔을 때

	x1 +=xstep;
	y1 +=ystep;

	/* 두 번째 사각형 이동경로 확인 */

	if(x2>window_width-rsize || x2<-window_width) xstep2 = -xstep2; // x축 범위
	if(y2>window_height -rsize || y2< -window_height) ystep2 = -ystep2; //y축 범위
	if(x2 > window_width-rsize) x2 = window_width-rsize-1;
	if(y2 >window_height-rsize) y2 = window_height-rsize-1;
	
	x2 +=xstep2;
	y2 +=ystep2;

	/* 세 번째 사각형 이동경로 확인 */

	if(x3>window_width-rsize || x3<-window_width) xstep3 = -xstep3; // x축 범위
	if(y3>window_height -rsize || y3< -window_height) ystep3 = -ystep3; //y축 범위
	if(x3 > window_width-rsize) x3 = window_width-rsize-1;
	if(y3 >window_height-rsize) y3 = window_height-rsize-1;
	
	x3 +=xstep3;
	y3 +=ystep3;
	
	/* 네 번째 사각형 이동경로 확인 */

	if(x4>window_width-rsize || x4<-window_width) xstep4 = -xstep4; // x축 범위
	if(y4>window_height -rsize || y4< -window_height) ystep4 = -ystep4; //y축 범위
	if(x4 > window_width-rsize) x4 = window_width-rsize-1;
	if(y4 >window_height-rsize) y4 = window_height-rsize-1;
	
	x4 +=xstep4;
	y4 +=ystep4;

	glutPostRedisplay(); //glut라이브러리에 현재의 윈도우를 refreah하게 함. 즉, glutDisplayFunc를 호출함.
	glutTimerFunc(33,TimerFunction,1);
}



void SetupRC(void) { //렌더링 상태를 설정해준다.
	glClearColor(1.0f,1.0f,1.0f,1.0f); //클리어할 색상을 설정해준다.
}
void ChangeSize(GLsizei w, GLsizei h) { //윈도우 사이즈가 바뀔 때마다 콜백함수로 호출할껀데
	glViewport(0,0,w,h); //뷰포트 크기 설정하고
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h) //뷰포트 넓이에 따라, 클리핑 공간을 변경해주는 함수
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//framebuffer를 두개 사용할건데
	glutInitWindowSize(800,600); //시작할때 윈도우 사이즈는 800*600이고
	glutCreateWindow("BounceRectangle"); //윈도우를 생성하고
	glutDisplayFunc(RenderScene);  //디스플레이 콜백함수를 설정해서, 계속 호출한다.
	glutReshapeFunc(ChangeSize);   //윈도우 크기가 변경될때마다 호출한다.
	glutTimerFunc(2000,TimerFunction,1);  // 맨 처음에는 2000ms후에 TimerFunction을 콜한다. 그 이후에는 이 함수 안에서 33ms마다 콜한다.
    SetupRC();
	glutMainLoop();  	
}
