 
#pragma once
#include <gl/glut.h>
#include <gl/glu.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>;
using namespace std;

typedef struct face {
	vector<int>v_face;
	vector<int>norms;
	vector<int>texcoords;
	string material;
}Fac;


typedef struct JIDstate {
	int state;
	GLfloat VN[3];
	GLfloat TX[2];
	GLfloat VE[3];
}Sta;

class ObjLoader {
public:
	ObjLoader(string filename);//构造函数
	void Draw();//绘制函数
	GLuint regHex;
private:
	vector<vector<GLfloat>>vertices;
	vector<vector<GLfloat>>normals;
	vector<vector<GLfloat>>texcoords;
	vector<face>faces;

	map<int, int> state_table;
	map<int, Sta> JID_table;
	vector<vector<GLfloat>>VNtable;
	vector<vector<GLfloat>>TXtable;
	vector<vector<GLfloat>>VEtable;

};

