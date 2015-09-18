#version 330 core

layout(location = 0) in vec3 VertexPosition;
layout(location = 1) in vec2 VertexUV;
layout(location = 2) in vec3 VertexNormal;

out vec3 lightIntensity;
out vec2 UV;

uniform Light {
    vec4 Position;
    vec3 La;
    vec3 Ld;
    vec3 Ls;
};
//uniform LightInfo Light;

uniform Material {
    vec3 Ka;
    vec3 Kd;
    vec3 Ks;
    float Shininess;
};
//uniform MaterialInfo Material;

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 MVP;

void main() {
    vec3 tnorm = normalize(NormalMatrix * VertexNormal);
    vec4 eyeCoords = ModelViewMatrix * vec4(VertexPosition, 1.0);
    vec3 s = normalize(vec3(Position - eyeCoords));
    vec3 v = normalize(-eyeCoords.xyz);
    vec3 r = reflect(-s, tnorm);
    vec3 ambient = La * Ka;
    float sDotN = max(dot(s, tnorm), 0.0);
    vec3 diffuse = Ld * Kd * sDotN;
    vec3 spec = vec3(0.0);
    if(sDotN > 0.0)
        spec = Ls * Ks * pow(max(dot(r, v), 0.0), Shininess);
    lightIntensity = ambient + diffuse + spec;
    gl_Position = MVP * vec4(VertexPosition, 1.0);
    UV = VertexUV;
}
