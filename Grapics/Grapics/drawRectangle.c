#include <Windows.h>
#include <gl/glut.h>
void RenderScence(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //실제 클리어 작업을 수행한다.
	glColor3f(1.0f, 0.0f, 0.0f); //사각형을 그릴 색상을 지정
	glRectf(0.0f, 0.0f, 50.0f, 30.0f); // solid한 사각형을 (x1, y1)에서 (x2, y2)까지 그린다. 채워지는 기본 색상은 흰색(1.0f, 1.0f, 1.0f)이다.
	glFlush(); //queue에 채워진 명령어들을 실행한다.
}

void SetupRC(void) //rendering전에 수행할 openGL초기화 작업이다. 윈도우를 clear하기 위한 색상을 지정한다.
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //윈도우를 clear할 색상을 지정한다. 
}

void ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0,0,w,h); //openGL이 실제로 그림을 그리는 데 사용하는 영역을 지정한다. 즉, viewPort를 만든다. 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //openGL이 사용자가 프로젝션에 관련된 행렬을 선언했고, 그 행렬을 초기화하기 위해 단위행렬로 만들었다.
	if(w<=h)
		glOrtho(-100.0f,100.0f,-100.0f, 100.0f,1.0f,-1.0f); //3차원 캔버스를 만든다. 여섯 개의 좌표가 존재하고, 래프트 라이트 바텀 탑 니어 파 순이다.
	else
		glOrtho(-100.0f,100.0f, -100.0f, 100.0f, 1.0f, -1.0f);
	//OrthoGrapic 을 만드는 내용. 코드가 알아서 뷰 볼륨의 크기를 변경시켜 줌.

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(void)
{
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //싱글 프레임 버퍼로, 모든 드로잉 명령을 화면에 나타난 윈도우상에서 수행
		glutCreateWindow("Rectangle"); //glutAPI를 사용한 윈도우 창을 생성한다.
		glutDisplayFunc(RenderScence); //윈도우를 그릴 때마다 glut는 명시한 RenderScence을 콜백함수로 호출한다.
		glutReshapeFunc(ChangeSize); //콜백함수로 윈도우에게 '만약에 사용자가 윈도우에 사이즈 쉘 모양을 다시 설정하면 내가 만든 이 함수를 os야 불러'라고 선언해주는 함수
		SetupRC();
		glutMainLoop(); //메시지, 키보드 입력 등 운영체제에 관련한 모든 사항을 프로그램이 종료될때까지 처리한다.

}