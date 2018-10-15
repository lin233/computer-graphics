#include "pch.h"
#include "ObjLoader.h"
#include <fstream>
#include <iostream>

using namespace std;

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
	 
}

ObjLoader::ObjLoader(string filename)
{
  
	string line;
	fstream f;
	f.open(filename, ios::in);
	if (!f.is_open()) {
		std::cout << "Something Went Wrong When Opening Objfiles" << endl;
	}

	while (!f.eof()) {
		getline(f, line);//拿到obj文件中一行，作为一个字符串

		vector<string> values;
		SplitString(line, values, " ");
		string material;
		if (values.size() != 0) {
			if (values[0] == "v") {
				vector<GLfloat>Point;
				for (int i = 1; i < 4; i++) {   
					GLfloat xyz = atof(values[i].c_str());
					Point.push_back(xyz);
				}
				vertices.push_back(Point);
			}
			else if (values[0] == "vn") {
				vector<GLfloat>vn;
				for (int i = 1; i < 4; i++) {    
					GLfloat xyz = atof(values[i].c_str());
					vn.push_back(xyz);
				}
				normals.push_back(vn);
			}
			else if (values[0] == "vt") {
				vector<GLfloat>vt;
				for (int i = 1; i < 3; i++) {    
					GLfloat xyz = atof(values[i].c_str());
					vt.push_back(xyz);
				}
				texcoords.push_back(vt);
			}
			else if (values[0] == "usemtl" || values[0] == "usemat") {
				material = values[1];
			}
			else if (values[0] == "f") {
				vector<int>f ;
				vector<int>t ;
				vector<int>n ;
				for (int i = 1; i < values.size(); i++) {
					vector<string> w;
					SplitString(values[i], w, "/");
					f.push_back(atof(w[0].c_str()));

					if (w.size() >= 2 && w[1].length() > 0) {
						t.push_back(atof(w[1].c_str()));
					}
					else {
						t.push_back(0);
					}
					if (w.size() >= 3 && w[2].length() > 0) {
						n.push_back(atof(w[2].c_str()));
					}
					else {
						n.push_back(0);
					}
				}
				Fac fac = {f,n,t,material}; 
				faces.push_back(fac);
			}
		} 
	}
 	cout << "OK";
	f.close();
	 
	int fsize = faces.size();
	int JID = 0; 
	for (int i = 0; i < fsize; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		vector<int>nor = face.norms;
		vector<int>tex = face.texcoords;
		string mat = face.material;
		int vsize = ver.size(); 
		for (int j = 0; j < vsize; j++) {
			int state = 0;
			int nj = nor[j] - 1;
			if (nj >= 0) {
				vector<float> norj = normals[nj];
				JID_table[JID].VN[0] = norj[0];
				JID_table[JID].VN[1] = norj[1];
				JID_table[JID].VN[2] = norj[2];
				state++;
			} 

			int tj = tex[j] - 1;
			if (tj >= 0) {
				vector<float> texj = texcoords[tj];
				JID_table[JID].TX[0] = texj[0];
				JID_table[JID].TX[1] = texj[1];
				state += 2;
			} 
			vector<float> verj = vertices[ver[j] - 1];
			JID_table[JID].VE[0]= verj[0];
			JID_table[JID].VE[1] = verj[1];
			JID_table[JID].VE[2] = verj[2];
			//cout << JID_table[JID].VN[0]<<" ";
			JID_table[JID].state = state;
			JID++;
		}
	} 
	return;
	/*
		int fsize = faces.size();
	int JID = 0;
	vector<GLfloat> VN0;
	VN0.push_back(0);
	VN0.push_back(0);
	VN0.push_back(0);
	 
	vector<GLfloat> TX0;
	TX0.push_back(0);
	TX0.push_back(0);
	
	for (int i = 0; i < fsize; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		vector<int>nor = face.norms;
		vector<int>tex = face.texcoords;
		string mat = face.material;
		int vsize = ver.size();
	
		for (int j = 0; j < vsize; j++) {
			int state = 0;
			int nj = nor[j] - 1;
			if (nj >= 0) {
				vector<GLfloat> VN;
				vector<float> norj = normals[nj];
				VN.push_back(norj[0]);
				VN.push_back(norj[1]);
				VN.push_back(norj[2]);
				VNtable.push_back(VN);
				state++;
			}
			else {
				VNtable.push_back(VN0);
			}
			int tj = tex[j] - 1;
			if (tj >= 0) {
				vector<GLfloat> TX;
				vector<float> texj = texcoords[tj];
				TX.push_back(texj[0]);
				TX.push_back(texj[1]);
				TXtable.push_back(TX);
				state += 2;
			}
			else {
				TXtable.push_back(TX0);
			}
			vector<GLfloat> VE;
			vector<float> verj = vertices[ver[j] - 1];
			VE.push_back(verj[0]);
			VE.push_back(verj[1]);
			VE.push_back(verj[2]);
			VEtable.push_back(VE);
			state_table[JID] = state;
			JID++;
		}
	} 
	*/
	//*/
//	regHex = glGenLists(1);
//	glNewList(regHex, GL_COMPILE);
//	glEnable(GL_TEXTURE_2D);
//	glFrontFace(GL_CCW);
	//cout << "test1"; 
	/*
	int fsize = faces.size();
	for (int i = 0; i < 1000; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		vector<int>nor = face.norms;
		vector<int>tex = face.texcoords;
		string mat = face.material;
		int vsize = ver.size();
		glBegin(GL_POLYGON);
		for (int j = 0; j < vsize; j++) {
			int nj = nor[j] - 1;
			if (nj >= 0) {
				vector<float> norj = normals[nj];
				glNormal3f(norj[0], norj[1], norj[2]);
			}
			int tj = tex[j] - 1;
			if (tj >= 0) {
				vector<float> texj = texcoords[tj];
				glTexCoord2f(texj[0], texj[1]);
			}
			vector<float> verj = vertices[ver[j] - 1];
			glVertex3f(verj[0], verj[1], verj[2]);
		}
		glEnd();
		glEnable(GL_CULL_FACE);
	}
//	cout << "test10";
//	glDisable(GL_TEXTURE_2D);
	glEndList();*/

}

void ObjLoader::Draw() { 
	//regHex = glGenLists(1);
	//glNewList(regHex, GL_COMPILE);
	//glEnable(GL_TEXTURE_2D);
	//glFrontFace(GL_CCW);
	//cout << "test1";

	//glCallList(regHex);

	/*
	int fsize = faces.size();
	for (int i = 0; i <fsize; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		vector<int>nor = face.norms;
		vector<int>tex = face.texcoords;
		string mat  = face.material;
		int vsize = ver.size();
		glBegin(GL_POLYGON);
		for (int j = 0; j < vsize; j++) {
			int nj = nor[j] - 1;
			if (nj >= 0) {
				vector<float> norj = normals[nj];
				glNormal3f(norj[0],norj[1],norj[2]);
			}
			int tj = tex[j]-1;
			if (tj >= 0) {
				vector<float> texj = texcoords[tj];
				glTexCoord2f(texj[0],texj[1]);
			}
			vector<float> verj = vertices[ver[j] - 1];
			glVertex3f(verj[0],verj[1],verj[2]);
		}
		glEnd();
		glEnable(GL_CULL_FACE);
	}
	*/
//	cout << "test10";
	//glDisable(GL_TEXTURE_2D);
	//glEndList();
	
	 glEnable(GL_TEXTURE_2D);
	int fsize = faces.size()-1;
	//cout << fsize;
	int JID = 0;
	for (int i = 0; i < 4000 ; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		int vsize = ver.size();
		glBegin(GL_POLYGON);
		for (int j = 0; j < vsize; j++) {
			Sta sta = JID_table[JID];
		 
			int state = sta.state;			
			if (state % 2 ) {
				glNormal3fv(sta.VN);
			}
			if (state >= 2) {
				glTexCoord2fv(sta.TX);
			}
			glVertex3fv(sta.VE);
			JID++;
		}
		glEnd();
		 
	}
	glDisable(GL_TEXTURE_2D);
	 /*
	  
	int fsize = faces.size();
	cout << fsize;
	int JID = 0;
	for (int i = 0; i < 4000; i++) {
		Fac face = faces[i];
		vector<int>ver = face.v_face;
		int vsize = ver.size();
		glBegin(GL_POLYGON);
		for (int j = 0; j < vsize; j++) {
			int state = state_table[JID];
			if (state % 2 ) {
				glNormal3f(VNtable[JID][0], VNtable[JID][1], VNtable[JID][2]);
			}
			
			if (state >= 2) {
				glTexCoord2f(TXtable[JID][0],TXtable[JID][1]);
			}

			glVertex3f(VEtable[JID][0], VEtable[JID][1], VEtable[JID][2]);
			JID++;
		}
		glEnd();
		glEnable(GL_CULL_FACE);
	}
	 
	 */

	return;
}
