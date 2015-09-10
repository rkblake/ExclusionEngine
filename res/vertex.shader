#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

out vec2 UV;
out vec3 normal;

uniform mat4 MVP;
//uniform mat4 V;
//uniform mat4 M;
//uniform vec3 LightPosition_worldspace;

void main(){
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
	UV = vertexUV;
	normal = vertexNormal_modelspace;
}
