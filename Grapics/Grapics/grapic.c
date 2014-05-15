/*//#include "stdafx.h"
#include <stdio.h>
#include <gl/glut.h>

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void SetupRC(void) 
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void main(void) 
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);


} */

#include <windows.h>
#include <gl\glut.h>
#include <math.h>
//	glColor3ub();
//키보드를 이용해 회전시키기 위한 변수
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;

void drawFace(){
	glScalef(1.3, 1.01, 1.3);
	glColor3f(0.3215f, 0.247f, 0.247f);
	glutSolidSphere(60.0f, 30, 30); // 반지름, 경도, 위도
}

void drawMouse(){
	glTranslatef(0, -18.0, -40);
	glColor3f(0.96f, 0.96f, 0.86f);
	glutSolidSphere(25.0f, 15, 15);
	glPopMatrix();
}


void drawNose(){
	glTranslatef(0.0, -10.0, -84.5);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(7.0f, 3.5f, 1.0f);
	glVertex3f(-7.0f, 3.5f, 1.0f);
	glVertex3f(0.0f, -3.5f, 0.0f);
	glEnd();

	glRectf(1.0f, -2.5f, -1.0f, -8.0f);
	
	glPushMatrix();
	glTranslatef(-14.0f, -15.8f, 0.0f);
	glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
	glRectf(1.0f, -2.5f, -1.0f, -16.5f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0f, -7.0f, 0.0f);
	glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
	glRectf(1.0f, -2.5f, -1.0f, -13.0f);
	glPopMatrix();
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / (float)num_segments;
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0;

	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex 

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void drawEye(){
	glPushMatrix();
	glScalef(1.0, 1.3, 1.0);
	DrawCircle(5.0f, 8.0f, 6.0f, 30);
	glPopMatrix();
}

void drawEar(){
	glPushMatrix();
	glScalef(1.1, 1.0, 1.0);
	glColor3f(0.3215f, 0.247f, 0.247f);
	DrawCircle(0.0f, 0.0f, 35.0f, 100);
	gluCylinder(gluNewQuadric(), 35.0f, 35.0f, 10.0f, 30, 30);
	glTranslatef(0, 0, 10);
	DrawCircle(0.0f, 0.0f, 35.0f, 100);
	glPopMatrix();
}

void drawBody(){
	glPushMatrix();
	glScalef(1.3, 1.0, 1.0);
	glTranslatef(0, 10.0f, 130.0f);
	glColor3f(0.3215f, 0.247f, 0.247f);
	gluCylinder(gluNewQuadric(), 40.0f, 55.0f, 149.0f, 30, 30);
	glTranslatef(0, 0, 155.0f);
	glutSolidSphere(55.0f, 30, 30);
	glPopMatrix();
}

void drawLeg(){
	glPushMatrix();
	glColor3f(0.3215f, 0.247f, 0.247f);
	gluCylinder(gluNewQuadric(), 20.0f, 20.0f, 60.0f, 30, 30);
	glColor3f(0.96f, 0.96f, 0.86f);
	glTranslatef(0, 0, 53.5f);
	glutSolidSphere(20.0f, 30, 30);
	glPopMatrix();
}

void drawArm(){
	glPushMatrix();
	glColor3f(0.3215f, 0.247f, 0.247f);
	gluCylinder(gluNewQuadric(), 20.0f, 20.0f, 90.0f, 30, 30);
	glTranslatef(0, 0, 90.0f);
	glutSolidSphere(20.0f, 30, 30);
	glTranslatef(0, -3, 0);
	glColor3f(0.96f, 0.96f, 0.86f);
	glutSolidSphere(18.0f, 30, 30);
	glPopMatrix();
}


void OKrendering(void){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f); //angle, x, y, z
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glTranslatef(0, 0, -100.0f);
	glPushMatrix();
	//head
	drawFace();

	//mouse
	drawMouse();

	drawNose();

	//right eye
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(-25.0f, 0.0f, 0.5f, 1.0f);
	glTranslatef(10.0, 5.0, 5.3);
	drawEye();
	glPopMatrix();

	//left eye
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(25.0f, 0.0f, 0.5f, 1.0f);
	glTranslatef(-20.0, 5.0, 5.3);
	drawEye();
	glPopMatrix();
	
	//right ear
	glPushMatrix();
	glRotatef(-15, 1.0, 0.0, 0.0);
	glTranslatef(60, 40, 80);
	drawEar();
	glPopMatrix();

	//left ear
	glPushMatrix();
	glRotatef(-15, 1.0, 0.0, 0.0);
	glTranslatef(-60, 40, 80);
	drawEar();
	glPopMatrix();
	

	drawBody();

	glPushMatrix();
	glTranslatef(30.0f, 10.0f, 320.0f);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0f, 10.0f, 320.0f);
	drawLeg();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(40,0,175);
	glRotatef(140, 0.0, 1.0, 0.0);
	drawArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 0, 175);
	glRotatef(-140, 0.0, 1.0, 0.0);
	drawArm();
	glPopMatrix();

	glutSwapBuffers();
}



void DoYouReallyWanttoChangetheSize(GLsizei w, GLsizei h){ //parameter: window's width & hegiht
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); // I'll make matrix for projection
	glLoadIdentity(); // if you do not this fuction. trash will return

	//	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 1.0f, -1.0f); //parallel projection

	if (w <= h){
		glOrtho(-250.0f, 250.0f, -250.0f*h / w, 250.0f*h / w, 250.0f, -250.0f);
	}
	else{
		glOrtho(-250.0f*w / h, 250.0f*w / h, -250.0f, 250.0f, 250.0f, -250.0f);
	}

	glMatrixMode(GL_MODELVIEW); // I'll make matrix for modeling transformation
	glLoadIdentity();

	//glTranslatef(50.0f, 0.0f, 0.0f); //transport x+50
}

void KeyControl(int key, int x, int y){
	if (key == GLUT_KEY_UP)
		xRot -= 7.0f;
	if (key == GLUT_KEY_DOWN)
		xRot += 7.0f;
	if (key == GLUT_KEY_LEFT)
		yRot -= 7.0f;
	if (key == GLUT_KEY_RIGHT)
		yRot += 7.0f;

	glutPostRedisplay();
}

void SetupRC(void){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //'f' -> max is 1
	glFrontFace(GL_CCW);
//	glEnable(GL_CULL_FACE);
	GLfloat ambientLight[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat diffuseLight[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //입사광선의 반사정도, 1이면모든 입사광선 반사
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	GLfloat lightPos[] = { 100.0f, 100.0f, -100.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL); //color에 반응하는 재질을 선언하겠다
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // 재질의 앞면에 적용시키겠다. 조명 선언하면, 도형을 그릴 때 줬던 vertex 색상은 상수k로 바뀜
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// 완전 거울이네.. 완전 다 반사하니까
	glMateriali(GL_FRONT, GL_SHININESS, 128);
}

void main(void){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Rectangle");
	glutDisplayFunc(OKrendering); // if you have something to draw It'll called
	glutReshapeFunc(DoYouReallyWanttoChangetheSize);
	SetupRC();
	glutSpecialFunc(KeyControl);
	glutMainLoop(); // just wait! do not end program! til close window
}