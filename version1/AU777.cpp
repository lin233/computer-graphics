#include "pch.h"
#include "ObjLoader.h"
#include "WRJ.h"
using namespace std;
//模型路径

string MITswing =
"E:\\大三上\\图形学\\无人机obj\\WuRenJi_A.obj";
//"E:\\大三上\\图形学\\CG2018\\人物模型\\MITcrane\\mesh\\mesh_0000.obj";

ObjLoader objModel = ObjLoader(MITswing);


//实现移动鼠标观察模型所需变量
WRJ wurenji;

int mode = 0;

static float c = 3.1415926 / 180.0f;
static float r = 1.0f;
static int degree = 90;
static int oldPosY = -1;
static int oldPosX = -1;

int operation_opt = 0;

float moveX = 0;
float moveY = 0;
float moveZ = 0;

float vX = 0;
float vY = 0;
float vZ = 0;

float aX = 0;
float aY = 0;
float aZ = 0;

float targetX = 100;
float targetY = 30;
float targetZ = 100;

//
GLfloat spinX = 0;
GLfloat spinY = 0;
GLfloat spinZ = 0;
float des = 0;
//
float stepA = 0.1;
//////
float get_aX(WRJ wrj) {
	float leanX = wrj.get_leanX();
	float leanZ = wrj.get_leanZ();
	float quality = wrj.getQuality();
	float power = wrj.getPower();
	float ForceX = power * sin(leanX)*cos(leanZ);
	float aX = ForceX / quality;
	return aX;
}

float get_aY(WRJ wrj) {
	float leanX = wrj.get_leanX();
	float leanZ = wrj.get_leanZ();
	float power = wrj.getPower();
	float quality = wrj.getQuality();
	float ForceY = power * cos(leanX)*cos(leanZ) - quality * 9.8;
	float aY = ForceY / quality;
	return aY;
}

float get_aZ(WRJ wrj) {
	float leanX = wrj.get_leanX();
	float leanZ = wrj.get_leanZ();
	float power = wrj.getPower();
	float quality = wrj.getQuality();
	float ForceX = power * sin(leanZ)*cos(leanX);
	float aZ = ForceX / quality;
	return aZ;
}

/////
float speedUp(float& speed) {
	speed += stepA;
	return speed + stepA / 2;
}

float speedKeep(float speed ) {
	return speed;
}

float speedDown(float& speed ) {
	speed -= stepA;
	return speed - stepA / 2;
}

//////
//几个动作
void
take_off_1() {
	moveY += speedUp(vY);
	glutPostRedisplay();
}
void
take_off_2() {
	moveY += speedKeep(vY);
	glutPostRedisplay();
}
void
take_off_3() {
	moveY += speedDown(vY);
	glutPostRedisplay();
}
void
take_off(int opt) {
//	cout << "already to take off" << endl;
	if (opt < 10) {
		//cout << "already to speed up" << endl;
		take_off_1();
	}
	else if (opt < 20) {
		//cout << "already to keep" << endl;
		take_off_2();
	}
	else if (opt < 30) {
		//cout << "already to speed down" << endl;
		take_off_3();
	}
}
 
void hover() {
	if (vY < 0) {
		speedUp(vY);
	}
	if (vY > 0)speedDown(vY);

	glutPostRedisplay();
}

void touch_down_1() {
	moveY += speedDown(vY);
	glutPostRedisplay();
}
void touch_down_2() {
	moveY += speedKeep(vY);
	glutPostRedisplay();
}
void touch_down_3() {
	moveY += speedUp(vY);
	glutPostRedisplay();
}
void
touch_down(int opt) {
	//cout << "already to take off" << endl;
	if (opt < 10) {
		touch_down_1();
	}
	else if (opt < 20) {
		touch_down_2();
	}
	else if (opt < 30) {
		touch_down_3();
	}

}

void go_left_1() {
	spinX--;
	moveX += speedDown(vX);
	glutPostRedisplay();
}
void go_left_2() {
	moveX += speedKeep(vX);
	glutPostRedisplay();
}
void go_left_3() {
	spinX++;
	moveX += speedUp(vX);
	glutPostRedisplay();
}
void
go_left(int opt) {
	//cout << "already to take off" << endl;
	if (opt < 10) {
		go_left_1();
	}
	else if (opt < 20) {
		go_left_2();
	}
	else if (opt < 30) {
		go_left_3();
	}

}

void go_right_1() {
	spinX++;
	moveX += speedUp(vX);
	glutPostRedisplay();
}
void go_right_2() {
	moveX += speedKeep(vX);
	glutPostRedisplay();
}
void go_right_3() {
	spinX--;
	moveX += speedDown(vX);
	glutPostRedisplay();
}
void
go_right(int opt) {
	//cout << "already to take off" << endl;
	if (opt < 10) {
		go_right_1();
	}
	else if (opt < 20) { 
		go_right_2();
	}
	else if (opt < 30) { 
		go_right_3();
	}

}

void go_ahead_1() {
	spinZ++;
	moveZ += speedUp(vZ);
	glutPostRedisplay();
}
void go_ahead_2(){
	moveZ += speedKeep(vZ);
	glutPostRedisplay();
}
void go_ahead_3() {
	spinZ--;
	moveZ += speedDown(vZ);
	glutPostRedisplay();
}
void
go_ahead(int opt) {
	//cout << "already to take off" << endl;
	if (opt < 10) {
		go_ahead_1();
	}
	else if (opt < 20) {
		go_ahead_2();
	}
	else if (opt < 30) {
		go_ahead_3();
	}
}


void go_back_1(){
	spinZ--;
	moveZ += speedDown(vZ);
	glutPostRedisplay();
}
void go_back_2(){
	moveZ += speedKeep(vZ);
	glutPostRedisplay();
}
void go_back_3() {
	spinZ++;
	moveZ += speedUp(vZ);
	glutPostRedisplay();
}
void
go_back(int opt) {
	//cout << "already to take off" << endl;
	if (opt < 10) {
		go_back_1();
	}
	else if (opt < 20) {
		go_back_2();
	}
	else if (opt < 30) {
		go_back_3();
	}

}
//////
void draw_target()
{ 
	glPushMatrix(); 
		glTranslated(100, 0, 30);
		glColor3ub(255, 0, 0);
		glutSolidSphere(3, 20, 20);
	glPopMatrix();
}

void draw_obstacle()
{
	glPushMatrix();
		glTranslated(-40, 0, 30);
		glColor3ub(255, 0, 0);
		glutSolidCube(20);
		 
		glTranslated(80, 0, 0);
		glColor3ub(255, 0, 0);
		glutSolidCube(20);
		  
	glPopMatrix();
}

void go_right_avoid_obstacle(float x, float y, float z,int opt) {
	if (opt < 10) {
		take_off_1(); take_off_2(); go_right_1();
	}
	else if (opt < 20) {
		take_off_2(); go_right_2();
	}
	else if (opt < 30) {
		take_off_3(); go_right_2();
	} 
	else if (opt < 60) {
		  go_right_2();
	}
	else if (opt < 70) {
		touch_down_1(); touch_down_2(); go_right_2();
	}
	else if (opt < 80) {
		touch_down_2(); go_right_2();
	}
	else if (opt < 90) {
		touch_down_3(); go_right_3();
	} 
}

void go_left_avoid_obstacle(float x, float y, float z, int opt) {
	if (opt < 10) {
		take_off_1(); take_off_2(); go_left_1();
	}
	else if (opt < 20) {
		take_off_2(); go_left_2();
	}
	else if (opt < 30) {
		take_off_3(); go_left_2();
	}
	else if (opt < 60) {
		go_left_2();
	}
	else if (opt < 70) {
		touch_down_1(); touch_down_2(); go_left_2();
	}
	else if (opt < 80) {
		touch_down_2(); go_left_2();
	}
	else if (opt < 90) {
		touch_down_3(); go_left_3();
	}
}

void go_ahead_avoid_obstacle(float x, float y, float z, int opt) {
	if (opt < 10) {
		take_off_1(); take_off_2(); go_ahead_1();
	}
	else if (opt < 20) {
		take_off_2(); go_ahead_2();
	}
	else if (opt < 30) {
		take_off_3(); go_ahead_2();
	}
	else if (opt < 60) {
		go_ahead_2();
	}
	else if (opt < 70) {
		touch_down_1(); touch_down_2(); go_ahead_2();
	}
	else if (opt < 80) {
		touch_down_2(); go_ahead_2();
	}
	else if (opt < 90) {
		touch_down_3(); go_ahead_3();
	}
}

void go_back_avoid_obstacle(float x, float y, float z, int opt) {
	if (opt < 10) {
		take_off_1(); take_off_2(); go_back_1();
	}
	else if (opt < 20) {
		take_off_2(); go_back_2();
	}
	else if (opt < 30) {
		take_off_3(); go_back_2();
	}
	else if (opt < 60) {
		go_back_2();
	}
	else if (opt < 70) {
		touch_down_1(); touch_down_2(); go_back_2();
	}
	else if (opt < 80) {
		touch_down_2(); go_back_2();
	}
	else if (opt < 90) {
		touch_down_3(); go_back_3();
	}
}

void fly_a_circle_1(int opt){
	if (opt < 10) {
		go_right_1(); go_right_2(); take_off_1();
	}
	else if (opt < 20) {
		go_right_2(); take_off_2();
	}
	else if (opt < 30) {
		go_right_3(); take_off_2(); 
	}
	else if (opt < 40) {
		go_left_1();   take_off_2();
	}
	else if (opt < 50) {
		go_left_2(); take_off_2();
	}
	else if (opt < 60) {
		go_left_2(); take_off_3();
	} 
	else if (opt < 70) {
		go_left_2(); touch_down_1();
	}
	else if (opt < 80) {
		go_left_2(); touch_down_2();
	}
	else if (opt < 90) {
		go_left_3();  touch_down_2();
	} 
	else if (opt < 100) {
		go_right_1();  touch_down_2();
	}
	else if (opt < 110) {
		go_right_2(); touch_down_2();
	}
	else if (opt < 120) {
		go_right_3(); go_right_2(); touch_down_3();
	} 
}

///////
/*
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	objModel.Draw();
	glutSwapBuffers();
}

void TimerFunction(int value) {
	if (x1 > windowWidth - rsize || x1 < 0) {
		xstep = xstep;
	}

	if (y1 > windowHeight - rsize || y1 < 0) {
		ystep = -ystep;
	}

	if (x1 > windowWidth - rsize) {
		x1 = windowWidth - rsize - 1;
	}
	if (y1 > windowHeight - rsize) {
		y1 = windowHeight - rsize - 1;
	}

	x1 += xstep;
	y1 += ystep;

	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);

}

void SetupRC(void) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h) {
	if (h == 0)h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

*///////////////////////
//安置光源
void setLightRes() {
	//GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	gluLookAt(30, 40, 200, -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f);
	//定义光源的颜色和位置
	GLfloat ambient[] = { 0.3, 0.3,0.3, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { -80.0, 50.0, 25.0, 1.0 };
	//选择光照模型
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glShadeModel(GL_SMOOTH);

	//设置环境光
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	//设置漫射光
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	//设置光源位置
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	//启动光照
	glEnable(GL_LIGHTING);
	//启用光源
	glEnable(GL_LIGHT0);

	glFrustum(-100.f, 100.0f, -100.f, 100.0f, -100.0f, 100.0f);
	glColor3f(0.3, 1.0, 1.0);
	
	
}

//初始化
void init() {
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );

	glutInitWindowSize(1000, 800);
	glutCreateWindow("ObjLoader1");
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	setLightRes();
	//glEnable(GL_DEPTH_TEST);

}

void drawWRJ() {
	glPushMatrix();
	glTranslated(0, 0, 30);
	glTranslated(moveX, moveY, moveZ);
	glRotatef(spinZ, 1.0f, 0.0f, 0.0f);
	glRotatef(spinX, 0.0f, 0.0f, -1.0f);
	objModel.Draw();
	glPopMatrix();
}

void display_jump()
{
	glColor3f(1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setLightRes();
	//gluLookAt(r*cos(c*degree), 0, r*sin(c*degree), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	 
	glPushMatrix(); 
		drawWRJ();
		draw_target();
		draw_obstacle();
	glPopMatrix();  

	glLoadIdentity();
	glBegin(GL_QUADS);
		glColor3ub(0,0,255);
		glVertex3f(2000.0f, -20.0f, -1000.0f);
		glVertex3f(-2000.0f, -20.0f, -1000.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(-2000.0f, -20.0f, 1000.0f);
		glVertex3f(2000.0f, -20.0f, 1000.0f);
	glEnd();

	glutSwapBuffers();
}


void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLdouble)width / (GLdouble)height, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
}

//移动鼠标360观察模型
void moseMove(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		oldPosX = x; oldPosY = y;
	}
}
void changeViewPoint(int x, int y)
{
	int temp = x - oldPosX;
	degree += temp;
	oldPosX = x;
	oldPosY = y;
}

//键盘事件

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		spinX -=  1;
		moveX--;
		break;
	case 'd':
		spinX +=  1;
		moveX++;
		break;
	case 'w':
		spinZ -= 1;
		moveZ--;
		break;
	case 's':
		spinZ += 1;
		moveZ++;
		break;
	case 'j':  
		moveY++;
		break;
	case 'k': 	 
		moveY--;
		break;
	case'0':
		mode = 0;
		break;
	case'1':
		mode = 1;
		moveX = 0;
		moveY = 0;
		moveZ = 0;
		break;
	} 
	glutPostRedisplay();
}

/*

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		wurenji.go_left();
		spinX=wurenji.get_leanX();
		break;
	case 'd':
		wurenji.go_right();
		spinX = wurenji.get_leanX();
		break;
	case 'w':
		wurenji.go_ahead();
		spinZ = wurenji.get_leanZ();
		break;
	case 's':
		wurenji.go_back();
		spinZ = wurenji.get_leanZ();
		break;
	case'j':
		wurenji.upPower();
		break;
	case'k':
		wurenji.downPower();
		break;
	}
	glutPostRedisplay();
	wurenji.hover();
	glutPostRedisplay();
}
*/

void myIdle( )
{
	vX = get_aX(wurenji);
	vY = get_aY(wurenji);
	vZ = get_aZ(wurenji);
	wurenji.hover();
	moveX += vX;
	moveY += vY;
	if (moveY < 0)moveY = 0;
	moveZ = vZ;
	glutPostRedisplay();
}

//行动设计:
//1.从地面起飞到height的高度，最大限速为speed;加速度为step现在是0.1
/*
void
take_off(float height,float max_speed) {
	cout << "already to take off" << endl;
	if (height <= max_speed * (max_speed / stepA)) {
		float speed_up_time = sqrt(height * max_speed / stepA);
		cout << speed_up_time << endl;
		for (int i = 0; i < (speed_up_time + 0.5); i++) {
			cout << "speed up";
			moveY += speedUp(vY);
			glutPostRedisplay();
		}
		for (int i = 0; i < (speed_up_time + 0.5); i++) {
			moveY += speedDown(vY);
			glutPostRedisplay();
		}
	}
	else {
		float speed_up_time = max_speed / stepA;
		cout << speed_up_time << endl;
		for (int i = 0; i < speed_up_time + 0.5; i++) {
			cout << "speed up";
			moveY += speedUp(vY);
			glutPostRedisplay();
		}
		float speed_keep_time = (height - max_speed*max_speed/stepA)/ max_speed;
		for (int i = 0; i < speed_keep_time + 0.5; i++) {
			moveY += speedKeep(vY);
			glutPostRedisplay();
		}
		for (int i = 0; i < (speed_up_time + 0.5); i++) {
			moveY += speedDown(vY);
			glutPostRedisplay();
		}
	}
}
*/


void myIdle1()
{ 
	if (mode == 0)return;

	operation_opt = operation_opt%1110;
	
	if (operation_opt < 30) {
		take_off(operation_opt);		 
	}
	else if (operation_opt < 60) {
		go_left(operation_opt - 30);
	}
	else if (operation_opt < 90) {
		go_right(operation_opt - 60);
	}
	else if (operation_opt < 120) {
		go_right(operation_opt - 90);
	}
	else if (operation_opt < 150) {
		go_left(operation_opt - 120);
	}
	else if (operation_opt < 180) {
		go_ahead(operation_opt - 150);
	}
	else if (operation_opt < 210) {
		go_back(operation_opt - 180);
	}
	else if (operation_opt < 240) {
		touch_down(operation_opt - 210);
	}
	else if (operation_opt < 360) {
		go_right_avoid_obstacle(0, 0, 0, operation_opt - 240);
	}
	else if (operation_opt < 480) {
		go_left_avoid_obstacle(0, 0, 0, operation_opt - 360);
	}
	else if (operation_opt < 600) {
		go_left_avoid_obstacle(0, 0, 0, operation_opt - 480);
	}
	else if (operation_opt < 720) {
		go_right_avoid_obstacle(0, 0, 0, operation_opt - 600);
	}
	else if (operation_opt < 840) {
		go_ahead_avoid_obstacle(0, 0, 0, operation_opt - 720);
	}
	else if (operation_opt < 960) {
		go_back_avoid_obstacle(0, 0, 0, operation_opt - 840);
	}
	/*
	if (operation_opt < 960) {
		operation_opt = 959;
	} */
	else if (operation_opt < 990) {
		take_off(operation_opt-960);
	}
	else if (operation_opt < 1110) {
		fly_a_circle_1(operation_opt-990);
	}
	operation_opt++;

}

int main(int argc, char* argv[])
{
	cout << "有两种模式，一种手动操控，一种自动运动" << endl;
	cout << "按0进入手动模式，按1进入自动模式" << endl;
	cout << "手动模式：a左移，d右移，w前进，s后退，j上升，k下降" << endl;

	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display_jump);
	//glutDisplayFunc(display_target);
	glutReshapeFunc(reshape);
	glutMouseFunc(moseMove);
	glutMotionFunc(changeViewPoint);
	glutIdleFunc(myIdle1);
	//键盘事件
	glutKeyboardFunc(keyPressed);
	//glutTimerFunc(33, myIdle1, 0);

	glutMainLoop();
	return 0;
}

