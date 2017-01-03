#ifndef EE_UTILS_H
#define EE_UTILS_H

#include <glm/glm.hpp>
#include <LinearMath/btVector3.h>
#include <math.h>


#include "Vec2f.h"
#include "Vec3f.h"
#include "Timer.h"

const float pif = static_cast<float>(M_PI);
const float pif_times_2 = pif * 2.0f;
const float pif_over_2 = pif / 2.0f;
const float pif_over_4 = pif / 4.0f;
const float degToRadMultiplier = pif / 180.0f;

float DegToRad(float deg);
float RadToDeg(float rad);
Vec3f RotationToVector(float xRotRads, float yRotRads);

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

template <class T> const T& max(const T& a, const T& b) {
	return (a<b) ? b : a;     // or: return comp(a,b)?b:a; for version (2)
}

unsigned char* LoadImage(const char* file, int* width, int* height, int* numComponents, int layout);
void FreeImage(unsigned char* data);

#endif
