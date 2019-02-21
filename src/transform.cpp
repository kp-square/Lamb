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

float* Transform::translate(float tx,float ty,float tz) {
	float* translate = new float[16]{
		1,	 0,		0,		tx,
		0,	 1,		0,		ty,
		0,	 0,		1,		tz,
		0,	 0,		0,		1
	};
	return translate;
}


//vertical_field_of_view is an angle made by far plane at the eye.
//aspect_ratio = far_plane_width/far_place_height
//zNear: +ve value        zFar: +ve value
float* Transform::getPerspectiveMatrix(float vertical_field_of_view, float aspect_ratio, float zNear, float zFar) {
	//maps z coordinate between [0,-1] i.e. [b, -a]
	float a = 100;      
	float b = 0;
	float d = 1 / tan(vertical_field_of_view); //scaling factor
	float A = zFar * (-a - b) / (zFar - zNear) + a;         
	float B = zFar * zNear *(-a - b) / (zFar - zNear);      
	float* perspective = new float[16]{
		d / aspect_ratio,	 0,		0,		0,
		0,					 d,		0,		0,
		0,					 0,		A,		B,
		0,					 0,	   -1,		0
	};
	return perspective;

}

float* Transform::lookATmat(float ex, float ey, float ez, float cx, float cy, float cz, float ux, float uy, float uz) {
	/*glm::vec3 cameraPos = glm::vec3(ex, ey, ez);
	glm::vec3 centerPos = glm::vec3(cx, cy, cz);
	glm::vec3 upPos = glm::vec3(ux, uy, uz);

	glm::vec3 cameraDir = glm::normalize(cameraPos - centerPos);
	glm::vec3 cameraRight = glm::normalize(glm::cross(upPos, cameraDir));
	glm::vec3 cameraUP = glm::normalize(glm::cross(cameraDir, cameraRight));*/
	float* mat = new float[16]{
		1,1
	};
	return mat;


}

Transform::~Transform()
{
	
}
