#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <cstdio>
#include <string>
//struct coordinate {
//	float x;
//	float y;
//	float z;
//public:
//	coordinate(float x, float y, float z) :x(x), y(y), z(z) {};
//};
//
//struct face {
//	int facenum;
//	
//	
//	unsigned int v[3],vt[3],vn[3];
//	face(unsigned int t1, unsigned int t2, unsigned int t3,
//		 unsigned int t4, unsigned int t5, unsigned int t6,
//		 unsigned int t7, unsigned int t8, unsigned int t9) {
//		v[0] = t1;
//		vt[0] = t2;
//		vn[0] = t3;
//		v[1] = t4;
//		vt[1] = t5;
//		vn[1] = t6;
//		v[2] = t7;
//		vt[2] = t8;
//		vn[2] = t9;
//	}
//	
//	
//};
//
//
//
//int loadObject(const char* file_path) {
//	std::vector<std::string* > coord;
//	std::vector<coordinate* > vertex;
//	std::vector<face*> faces;
//	std::vector<coordinate* > normals;
//
//	std::ifstream in(file_path);
//	if (!in.is_open) {
//		std::cout << "Not Opened" << std::endl;
//		return -1;
//	}
//
//	char buf[256];
//
//	while (!in.eof()) {
//		in.getline(buf, 256);
//		coord.push_back(new std::string(buf));
//	}
//
//
//	for (int i = 0; i < coord.size(); i++) 
//	{
//		if (coord[i][0] == "#")
//			continue;
//		else if (coord[i][0] == "v" && coord[i][1] == " ") 
//		{
//			
//			float tmpx, tmpy, tmpz;
//			sscanf(coord[i]->c_str, "v %f %f %f", &tmpx, &tmpy, &tmpz);
//			vertex.push_back(new coordinate(tmpx, tmpy, tmpz);
//		}
//		else if (coord[i][0] == "v" && coord[i][1] == "n") {
//			float tmpx, tmpy, tmpz;
//			sscanf(coord[i]->c_str(), "vn %f %f %f", &tmpx, &tmpy, &tmpz);
//			normals.push_back(new coordinate(tmpx, tmpy, tmpz));
//		}
//		else if (coord[i][0] == "f")
//		{
//			unsigned int a, b, c, d, e, f, g, h, p;
//			sscanf(coord[i]->c_str, "f %d/%d/%d %d/%d/%d %d/%d/%d", &a, &b, &c, &d, &e, &f, &g, &h, &p);
//			faces.push_back(new face(a, b, c, d, e, f, g, h, p));
//		}
//	}
//
//
//
//
//	for (int i = 0; i < coord.size(); i++)
//		delete coord[i];
//	for (int i = 0; i < faces.size(); i++)
//		delete faces[i];
//	for (int i = 0; i < normals.size(); i++)
//		delete normals[i];
//	for (int i = 0; i < vertex.size(); i++)
//		delete vertex[i];
//}


















bool loadObj(
	const char * path,
	std::vector < glm::vec3 > & out_vertices,
	std::vector < glm::vec2 > & out_uvs,
	std::vector < glm::vec3 > & out_normals
) {
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	FILE * file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	

	while(1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			vertex.x /= 3;
			vertex.y /= 3;
			vertex.z /= 3;
			temp_vertices.push_back(vertex);
			


		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
			

		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			normal.x /= 4;
			normal.y /= 4;
			normal.z /= 4;
			temp_normals.push_back(normal);
			


		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				continue;
				/*printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				std::cout << matches << std::endl;
				return false;*/
			}
			
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}

		
	}

	// For each vertex of each triangle


	std::cout << vertexIndices.size() << std::endl;
	std::cout << temp_vertices.size() << std::endl;
	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = temp_vertices[vertexIndex-1];
		out_vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < uvIndices.size(); i++) {
		unsigned int uvIndex = uvIndices[i];
		glm::vec2 vertex = temp_uvs[uvIndex - 1];
		out_uvs.push_back(vertex);
	}

	for (unsigned int i = 0; i < normalIndices.size(); i++) {
		unsigned int normalIndex = normalIndices[i];
		glm::vec3 vertex = temp_normals[normalIndex - 1];
		out_normals.push_back(vertex);
	}
}