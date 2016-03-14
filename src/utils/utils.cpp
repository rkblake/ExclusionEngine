#include "utils.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

float DegToRad(float deg)
{
	return deg * degToRadMultiplier;
}

float RadToDeg(float rad)
{
	return rad / degToRadMultiplier;
}

Vec3f RotationToVector(float xRotRads, float yRotRads)
{
	Vec3f dir;
	float cosY = cosf(yRotRads);

	dir.x = sinf(xRotRads) * cosY;
	dir.y = -sinf(yRotRads);
	dir.z = cosf(xRotRads) * cosY;

	return dir;
}

unsigned char* LoadImage(const char* file, int* width, int* height, int* numComponents, int layout) {
	return stbi_load(file, width, height, numComponents, layout);
}

void FreeImage(unsigned char* data) {
	stbi_image_free(data);
}
