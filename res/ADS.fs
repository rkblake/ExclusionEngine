#version 330 core

in vec3 lightIntensity;
in vec2 UV;

out vec4 frag_color;

uniform sampler2D texture_sampler;

void main() {
    frag_color = vec4(texture(texture_sampler, UV).rgb + lightIntensity, 1.0);
    //frag_color = vec4(lightIntensity, 1.0);
}
