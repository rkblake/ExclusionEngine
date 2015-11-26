#include "utils.h"

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
