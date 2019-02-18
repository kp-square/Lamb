#pragma once
#include<iostream>
#include<cstdio>
#include<cmath>
//#include "camera.h"

class Transform
{
public:
	Transform();
	float* rotateX(float anglee);
	float* rotateY(float anglee);
	float* rotateZ(float anglee);

	float* translate(float xt=0, float yt=0, float zt=0);
	float* scale(float xs=1, float ys=1, float zs=1);
	~Transform();

	
};