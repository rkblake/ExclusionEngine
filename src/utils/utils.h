#ifndef EE_UTILS
#define EE_UTILS

#include <glm/glm.hpp>
#include <bullet/LinearMath/btVector3.h>
#include <math.h>

#include "Vec2f.h"
#include "Vec3f.h"
#include "Timer.h"

const float pif = static_cast<float>(M_PI);
const float pif_times_2 = pif * 2.0f;
const float pif_over_2 = pif / 2.0f;
const float pif_over_4 = pif / 4.0f;
const float degToRadMultiplier = pif / 180.0f;

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

template<class T>
T Wrap(T val, T size) {
    if(val < 0)
        return val + size;
    if(val >= size)
        return val - size;

    return val;
}

template<class T>
T Clamp(T val, T min, T max) {
    if(val > max)
		return max;
	else if(val < min)
		return min;

	return val;
}

#endif
