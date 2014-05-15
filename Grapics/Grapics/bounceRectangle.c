#include <Windows.h>
#include <gl/glut.h>

GLfloat x1 =0.0f;
GLfloat y1 = 0.0f;
GLsizei rsize = 50.0f;
//정사각형 위치와 크기의 초기값 설정
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
//x,y축 방향으로 움직일 거리 설정

GLfloat x2 = -80.0f;
GLfloat y2 = -50.0f;


GLfloat window_width;
GLfloat window_height;
//윈도우 크기 설정

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT); //이전 버퍼를 clear한다.
	
	glColor3f(1.0f, 0.0f, 0.0f); //그림을 그릴 색상을 지정
	glRectf(x1, y1, x1+rsize, y1+rsize); //사각형을 그리고
	glRectf(x2, y2, x2+rsize, y2+rsize); //두 번째 사각형을 그림

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
	glColor3f(1.0f, 0.0f, 0.0f); //그림을 그릴 색상을 지정
	glRectf(x1, y1, x1+rsize, y1+rsize); //사각형을 그리고
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
	glColor3f(1.0f, 0.0f, 0.0f); //그림을 그릴 색상을 지정
	glRectf(x1, y1, x1+rsize, y1+rsize); //사각형을 그리고
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x1+10, y1+10, x1+rsize-10, y1+rsize-10);
	
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

	if(x2>window_width-rsize || x2<-window_width) xstep = -xstep; // x축 범위
	if(y2>window_height -rsize || y2< -window_height) ystep = -ystep; //y축 범위
	if(x2 > window_width-rsize) x2 = window_width-rsize-1;
	if(y2 >window_height-rsize) y2 = window_height-rsize-1;
	//윈도우가 변경되어 경계를 넘어갔을 때

	x2 +=xstep;
	y2 +=ystep;


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
