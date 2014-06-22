#include <gl/glut.h>
#include <windows.h>
#include <math.h>
#include "GLTools.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zDistance = 0.0f;		///ADD


static GLfloat amb[] = {0.3f,0.3f,0.3f, 1.0f};
static GLfloat diff[] = {0.5f,0.5f,0.5f, 1.0f};

void SetupRC()
{
	/*
	GLfloat amb[] = { 0.3f, 0.3f, 0.3f }; 


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);  // ���� ������ ���� off (backface culling)
	glFrontFace(GL_CCW);

	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	*/
	

	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
	GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f}; 


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);  // ���� ������ ���� off (backface culling)
	glFrontFace(GL_CCW);

	glEnable(GL_LIGHTING); //����ȿ���� �����ϰڽ��ϴ�.

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb); //�����Ʈ �𵨿� ���ڰ��� �ο��ϰڽ��ϴ�. amb�� ��Ÿ�� �ֺ����� ����մϴ�.
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb); //������ �Ӽ��� ��ġ�� ������
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff); //������ �Ӽ��� ��ġ�� ������
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular); //���ݻ� ����
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL); //������ �Ӽ��� �����ϰ� �Ѵ�.
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref); //������ ���ݻ�. ��ü�� � ���������� �������ִ� �Լ�
	glMateriali(GL_FRONT, GL_SHININESS, 128); //������ ���ݻ� ����.

	glClearColor(0.0f, 0.5f, 0.4f, 1.0f);

}

void DrawJet()
{
	GLTVector3 vNormal;	// Storeage for calculated surface normal

	(128, 128, 128);

	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);

	//front bottom
	glNormal3f(0.0f, -1.0f, 0.0f);

	//		glVertex3f(0.0f, 0.0f, 60.0f);
	//		glVertex3f(-15.0f, 0.0f, 30.0f);
	//		glVertex3f(15.0f,0.0f,30.0f);
	//		//�ּ�ó�� ����   

	//Right Winng
	GLTVector3 vPoints[3] = { { 15.0f, 0.0f, 30.0f },
	{ 0.0f, 15.0f, 30.0f },
	{ 0.0f, 0.0f, 60.0f } };

	// Calculate the normal for the plane
	gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);

	glNormal3fv(vNormal);
	//glColor3ub(255,0,0);
	glVertex3fv(vPoints[0]);
	glVertex3fv(vPoints[1]);
	//glColor3ub(127,123,234);
	glVertex3fv(vPoints[2]);

	{
		GLTVector3 vPoints[3] = { { 0.0f, 0.0f, 60.0f },
		{ 0.0f, 15.0f, 30.0f },
		{ -15.0f, 0.0f, 30.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);

		//glColor3ub(0,255,0);

		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		
		//glColor3ub(0,0,255);

		glVertex3fv(vPoints[2]);
	}


	// Body of the Plane ////////////////////////
	{
		GLTVector3 vPoints[3] = { { -15.0f, 0.0f, 30.0f },
		{ 0.0f, 15.0f, 30.0f },
		{ 0.0f, 0.0f, -56.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		
		//glColor3ub(0,0,255);

		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 0.0f, 0.0f, -56.0f },
		{ 0.0f, 15.0f, 30.0f },
		{ 15.0f, 0.0f, 30.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);

		//glColor3ub(0,255,255);

		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(15.0f, 0.0f, 30.0f);
	glVertex3f(-15.0f, 0.0f, 30.0f);
	glVertex3f(0.0f, 0.0f, -56.0f);

	///////////////////////////////////////////////
	// Left wing
	// Large triangle for bottom of wing
	{
		GLTVector3 vPoints[3] = { { 0.0f, 2.0f, 27.0f },
		{ -60.0f, 2.0f, -8.0f },
		{ 60.0f, 2.0f, -8.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	{
		GLTVector3 vPoints[3] = { { 60.0f, 2.0f, -8.0f },
		{ 0.0f, 7.0f, -8.0f },
		{ 0.0f, 2.0f, 27.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 60.0f, 2.0f, -8.0f },
		{ -60.0f, 2.0f, -8.0f },
		{ 0.0f, 7.0f, -8.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 0.0f, 2.0f, 27.0f },
		{ 0.0f, 7.0f, -8.0f },
		{ -60.0f, 2.0f, -8.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	// Tail section///////////////////////////////
	// Bottom of back fin
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-30.0f, -0.50f, -57.0f);
	glVertex3f(30.0f, -0.50f, -57.0f);
	glVertex3f(0.0f, -0.50f, -40.0f);

	{
		GLTVector3 vPoints[3] = { { 0.0f, -0.5f, -40.0f },
		{ 30.0f, -0.5f, -57.0f },
		{ 0.0f, 4.0f, -57.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	{
		GLTVector3 vPoints[3] = { { 0.0f, 4.0f, -57.0f },
		{ -30.0f, -0.5f, -57.0f },
		{ 0.0f, -0.5f, -40.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	{
		GLTVector3 vPoints[3] = { { 30.0f, -0.5f, -57.0f },
		{ -30.0f, -0.5f, -57.0f },
		{ 0.0f, 4.0f, -57.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 0.0f, 0.5f, -40.0f },
		{ 3.0f, 0.5f, -57.0f },
		{ 0.0f, 25.0f, -65.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 0.0f, 25.0f, -65.0f },
		{ -3.0f, 0.5f, -57.0f },
		{ 0.0f, 0.5f, -40.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}

	{
		GLTVector3 vPoints[3] = { { 3.0f, 0.5f, -57.0f },
		{ -3.0f, 0.5f, -57.0f },
		{ 0.0f, 25.0f, -65.0f } };

		gltGetNormalVector(vPoints[0], vPoints[1], vPoints[2], vNormal);
		glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
	}


	glEnd();
}


// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, zDistance);

	DrawJet();

	glPopMatrix();
	glutSwapBuffers();

}


/////////////////////////////////////////////////////
// Handle arrow keys
void ContorolKey(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;

	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key == GLUT_KEY_HOME) //add
		zDistance += 5.0f;

	if (key == GLUT_KEY_END) //add
		zDistance -= 5.0f;

	glutPostRedisplay();
}

void Keypressed(unsigned char key, int y, int z) {

	if(key == 'q') { //�����Ʈ �� ��̰� ����
		amb[0] += 0.1f;
		amb[1] += 0.1f;
		amb[2] += 0.1f;
	}

	if(key == 'w') { //��ǻ�� �� ��̰� ����
		diff[0] += 0.1f;		
		diff[1] += 0.1f;			
		diff[2] += 0.1f;

	}

	SetupRC();

}


void ChangeSize(int w, int h)
{
	GLfloat fAspect;
	GLfloat lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };

	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w / (GLfloat)h; // Window�� ��Ⱦ�� ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, fAspect, 1.0f, 255.0f); //(FOV,��Ⱦ��,near,far)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0.0f, 0.0f, -150.0f);


}


void main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Jet");

	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(ContorolKey);
	glutKeyboardFunc(Keypressed);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}
