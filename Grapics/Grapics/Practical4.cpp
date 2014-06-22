#include <windows.h>
#include <math.h>
#include "bmp.h"
#include <gl/glew.h>
#include <gl/glut.h>

#define GL_PI 3.1415f


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

static GLfloat amb[] = {0.7f, 0.7f, 0.7f, 1.0f};
static GLfloat diff[] = {0.8f, 0.8f, 0.8f, 1.0f};

AUX_RGBImageRec * texRec[3];
GLuint texID[3];
GLUquadricObj * quadric_sphere;

void SetupRC()
{
	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat lightPos[] = {0.0f, 0.0f, -50.0f, 1.0f};

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE); //단위법선 벡터를 구한다.
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	//텍스처를 입히기 위해서 파일들을 로드한다.
	texRec[0] = auxDIBImageLoad("sun.bmp");
	texRec[1] = auxDIBImageLoad("earth.bmp");
	texRec[2] = auxDIBImageLoad("moon.bmp");

	glGenTextures(3, &texID[0]);
	//텍스처에 정보를 입력한다.
	for(int i=0; i<3; i++) {
			glBindTexture(GL_TEXTURE_2D, texID[i]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texRec[i]->sizeX, texRec[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texRec[i]->data);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}
	

	glEnable(GL_TEXTURE_2D);

	//그냥 원을 그리는 함수에는 텍스처가 매핑되지 않으므로, gluNewQuadric이라는 걸 이용한다. 초기화하고 정보를 입력한다.
	quadric_sphere = gluNewQuadric();
	gluQuadricNormals(quadric_sphere, GLU_SMOOTH);
	gluQuadricTexture(quadric_sphere, GL_TRUE);

	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_DEPTH_TEST);	
	glFrontFace(GL_CCW);		
	glEnable(GL_CULL_FACE);		

}

void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}


void RenderScene()
{
	static GLfloat fElect1 = 0.0f; //속도를 나타내는 변수
	static GLfloat fElect2 = 0.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //모델뷰 행렬을 초기화하는 함수(단위행렬로 만듬)

	glTranslatef(0.0f, 0.0f, -100.0f);  // z 축으로 -100만큼 이동

	
	//태양
	glBindTexture(GL_TEXTURE_2D, texID[0]);
	glColor3ub(255, 255,19);
	gluSphere(quadric_sphere,40,16,16); //원을 하나 그림
	glPushMatrix();						// viewing transformation 저장 (1) 
												
	
	
	//지구
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glColor3ub(53,109,245);
	glRotatef(fElect1, 0.0f,1.0f,0.0f); // y축 방향으로 fElect1 각만큼 회전
	glTranslatef(90.0f,0.0f,0.0f);      // 변환된 x축으로 90만큼 이동
	gluSphere(quadric_sphere,15,16,16);        //원을 그린다.
												
	
	
	//달
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID[2]);
	glColor3ub(255,255,255);
	glRotatef(fElect2, 0.0f, 1.0f, 0.0f);// 변환된 z축으로 90만큼 이동
	glTranslatef(20.0f, 0.0f, 0.0f);
	gluSphere(quadric_sphere,7,16,16);
	glPopMatrix();
	

	fElect1 += 10.0f;					// 회전각 증가
	if(fElect1 > 360.0f)
		fElect1 = 0.0f;

	fElect2 += 5.0f;
	if(fElect2 > 360.0f) fElect2 = 0.0f;

	glutSwapBuffers(); 
	
}



void ContorolKey(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	glutPostRedisplay();
}


void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);  //add
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);  //add


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(512,512);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Atom");

	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33,TimerFunc,1 );
	glutSpecialFunc(ContorolKey);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}

