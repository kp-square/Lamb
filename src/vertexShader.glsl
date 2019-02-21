#version 330 core

layout(location=0) in vec4 position;

//uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	vec4 temp   = projection * model * position;
	vec3 temp2  = normalize ( temp.xyz );
	gl_Position = vec4 ( temp2, 1 );
};
