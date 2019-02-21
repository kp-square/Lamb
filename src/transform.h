#pragma once
#include<iostream>
#include<cstdio>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<cmath>
//#include "camera.h"

class Transform
{
public:
	Transform();
	float* rotateX(float anglee);
	float* rotateY(float anglee);
	float* rotateZ(float anglee);
	float* getPerspectiveMatrix(float vertical_field_of_view, float aspect_ratio, float zNear, float zFar);
	//vertical_field_of_view is an angle made by far plane at the eye.
	//aspect_ratio = far_plane_width/far_place_height
	//zNear: +ve value        zFar: +ve value
	float* lookATmat(float ex, float ey, float ez, float cx, float cy, float cz, float ux, float uy, float uz);


	float* translate(float tx=0, float ty=0, float tz=0);
	float* scale(float xs=1, float ys=1, float zs=1);
	~Transform();


	
};