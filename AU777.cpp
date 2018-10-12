#include "pch.h"
#include "ObjLoader.h"
using namespace std;
//模型路径
string MITjumping = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0000.obj";
string MITjumping1 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0001.obj";
string MITjumping2 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0002.obj";
string MITjumping3 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0003.obj";
string MITjumping4 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0004.obj";
string MITjumping5 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0005.obj";
string MITjumping6 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0006.obj";
string MITjumping7 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0007.obj";
string MITjumping8 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0008.obj";
string MITjumping9 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0009.obj";
string MITjumping10 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0010.obj";
string MITjumping11 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0011.obj";
string MITjumping12 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0012.obj";
string MITjumping13 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0013.obj";
string MITjumping14 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0014.obj";
string MITjumping15 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0015.obj";
string MITjumping16 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0016.obj";
string MITjumping17 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0017.obj";
string MITjumping18 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0018.obj";
string MITjumping19 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0019.obj";
string MITjumping20 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0020.obj";
string MITjumping21 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0021.obj";
string MITjumping22 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0022.obj";
string MITjumping23 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0023.obj";
string MITjumping24 = "E:\\大三上\\图形学\\CG2018\\人物模型\\MITjumping\\mesh\\mesh_0024.obj";


ObjLoader objModel_Jumping = ObjLoader(MITjumping);
ObjLoader objModel_Jumping1 = ObjLoader(MITjumping1);
ObjLoader objModel_Jumping2 = ObjLoader(MITjumping2);
ObjLoader objModel_Jumping3 = ObjLoader(MITjumping3);
ObjLoader objModel_Jumping4 = ObjLoader(MITjumping4);
ObjLoader objModel_Jumping5 = ObjLoader(MITjumping5);
ObjLoader objModel_Jumping6 = ObjLoader(MITjumping6);
ObjLoader objModel_Jumping7 = ObjLoader(MITjumping7);
ObjLoader objModel_Jumping8 = ObjLoader(MITjumping8);
ObjLoader objModel_Jumping9 = ObjLoader(MITjumping9);
ObjLoader objModel_Jumping10 = ObjLoader(MITjumping10);
ObjLoader objModel_Jumping11 = ObjLoader(MITjumping11);
ObjLoader objModel_Jumping12 = ObjLoader(MITjumping12);
ObjLoader objModel_Jumping13 = ObjLoader(MITjumping13);
ObjLoader objModel_Jumping14 = ObjLoader(MITjumping14);
ObjLoader objModel_Jumping15 = ObjLoader(MITjumping15);
ObjLoader objModel_Jumping16 = ObjLoader(MITjumping16);
ObjLoader objModel_Jumping17 = ObjLoader(MITjumping17);
ObjLoader objModel_Jumping18 = ObjLoader(MITjumping18);
ObjLoader objModel_Jumping19 = ObjLoader(MITjumping19);
ObjLoader objModel_Jumping20 = ObjLoader(MITjumping20);
ObjLoader objModel_Jumping21 = ObjLoader(MITjumping21);
ObjLoader objModel_Jumping22 = ObjLoader(MITjumping22);
ObjLoader objModel_Jumping23 = ObjLoader(MITjumping23);
ObjLoader objModel_Jumping24 = ObjLoader(MITjumping24);



//实现移动鼠标观察模型所需变量

static float c = 3.1415926 / 180.0f;
static float r = 1.0f;
static int degree = 90;
static int oldPosY = -1;
static int oldPosX = -1;
int opt = 0;

//安置光源
void setLightRes() {
	GLfloat lightPosition[] = { 0.0f, 0.0f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING); //启用光源
	glEnable(GL_LIGHT0);   //使用指定灯光
}

//初始化
void init() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("ObjLoader");
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	setLightRes();
	glEnable(GL_DEPTH_TEST);
}

void display_jump()
{
	glColor3f(1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	setLightRes();
	glPushMatrix();

	gluLookAt(r*cos(c*degree), 0, r*sin(c*degree), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	opt++;
	switch (opt%25) {
	case 0:
		objModel_Jumping.Draw();//绘制obj模型
		break;
	case 1:
		objModel_Jumping1.Draw();
		break;//绘制obj模型
	case 2:
		objModel_Jumping2.Draw();
		break;//绘制obj模型
	case 3:
		objModel_Jumping3.Draw();
		break;//绘制obj模型
	case 4:
		objModel_Jumping4.Draw();
		break;//绘制obj模型
	case 5:
		objModel_Jumping5.Draw();
		break;//绘制obj模型
	case 6:
		objModel_Jumping6.Draw();
		break;//绘制obj模型
	case 7:
		objModel_Jumping7.Draw();
		break;//绘制obj模型
	case 8:
		objModel_Jumping8.Draw();
		break;
	case 9:
		objModel_Jumping9.Draw();
		break;//绘制obj模型
	case 10:
		objModel_Jumping10.Draw();
		break;//绘制obj模型
	case 11:
		objModel_Jumping11.Draw();
		break;//绘制obj模型
	case 12:
		objModel_Jumping12.Draw();
		break;//绘制obj模型
	case 13:
		objModel_Jumping13.Draw();
		break;
	case 14:
		objModel_Jumping14.Draw();
		break;//绘制obj模型
	case 15:
		objModel_Jumping15.Draw();
		break;//绘制obj模型
	case 16:
		objModel_Jumping16.Draw();
		break;//绘制obj模型
	case 17:
		objModel_Jumping17.Draw();
		break;//绘制obj模型
	case 18:
		objModel_Jumping18.Draw();
		break;
	case 19:
		objModel_Jumping19.Draw();
		break;//绘制obj模型
	case 20:
		objModel_Jumping20.Draw();
		break;//绘制obj模型
	case 21:
		objModel_Jumping21.Draw();
		break;//绘制obj模型
	case 22:
		objModel_Jumping22.Draw();
		break;//绘制obj模型
	case 23:
		objModel_Jumping23.Draw();
		break;
	case 24:
		objModel_Jumping24.Draw();
		break;//绘制obj模型
	}
	glPopMatrix();
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

void myIdle()
{
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display_jump);
	glutReshapeFunc(reshape);
	glutMouseFunc(moseMove);
	glutMotionFunc(changeViewPoint);
	glutIdleFunc(myIdle);
	glutMainLoop();
	return 0;
}

 