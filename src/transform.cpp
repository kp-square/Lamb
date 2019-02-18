#include "transform.h"
#define pi 3.14159


Transform::Transform()
{
	
}

float* Transform::rotateX(float anglee) {
	float* vect = new float[16]{
		1,			0,				0,           0,
		0,			cos(anglee),   -sin(anglee), 0,
		0,			sin(anglee),	cos(anglee), 0,
		0,			0,				0,			 1
	};
	return vect;
}

float* Transform::rotateY(float anglee) {
	float* vect = new float[16]{
		cos(anglee),	0,		sin(anglee),   0,
		0,				1,		0,			   0,
		-sin(anglee),	0,		cos(anglee),   0,
		0,				0,		0,			   1
	};
	return vect;
}

float* Transform::rotateZ(float anglee) {
	float* vect = new float[16]{
		cos(anglee),	-sin(anglee),	0,		0,
		sin(anglee),	cos(anglee),	0,		0,
		0,				 0,				1,		0,
		0,				 0,				0,		1
	};
	return vect;
}





Transform::~Transform()
{
	
}
