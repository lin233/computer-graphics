#pragma once
#include <gl/glut.h>
#include <gl/glu.h>
#include <vector>
#include <string>
using namespace std;
class ObjLoader {
public:
	ObjLoader(string filename);//���캯��
	void Draw();//���ƺ���
private:
	vector<vector<GLfloat>>vSets;//��Ŷ���(x,y,z)����
	vector<vector<GLint>>fSets;//������������������
};

 