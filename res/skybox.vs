#version 330 core
layout(location = 0) in vec3 positions;
out vec3 texCoords;

uniform mat4 projection;
uniform mat4 view;

void main() {
    vec4 pos = projection * view * vec4(positions, 1.0);
    gl_Position = pos.xyww;
    texCoords = positions;
}
