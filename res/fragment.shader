#version 330 core

in vec2 UV;
in vec3 normal;

out vec4 color;

uniform sampler2D texture_sampler;

void main() {

	//color = vec4(UV.x, UV.y, 0.0, 1.0);
	//color = vec4(normal.x, normal.y, normal.z, 1.0);
	color = texture(texture_sampler, UV);
}
