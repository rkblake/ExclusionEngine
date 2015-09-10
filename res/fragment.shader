#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;

// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform sampler2D texture_sampler;

void main() {

	color = vec4(UV.x, UV.y, 0.0, 1.0);

	//color = vec4(1.0, 0.5, 0.25, 1.0);
	//color = texture(texture_sampler, UV);
}
