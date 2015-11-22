#ifndef EE_VEC3F
#define EE_VEC3F

#include <glm/glm.hpp>
#include <bullet/LinearMath/btVector3.h>

class Vec3f {
public:
    float x, y, z;

    Vec3f();
    Vec3f(float x, float y, float z);
    Vec3f(glm::vec3 glm_vec);
    Vec3f(btVector3 btVec);

    Vec3f operator*(float scale) const;
    Vec3f operator/(float scale) const;
    Vec3f operator+(const Vec3f& other) const;
    Vec3f operator-(const Vec3f& other) const;
    Vec3f operator-() const;
    const Vec3f& operator-=(const Vec3f& other);

    bool operator==(const Vec3f& other) const;
    bool operator!=(const Vec3f& other) const;

    float length() const;
    float lengthSquared() const;
    void normalize();
    float dot(const Vec3f& other) const;
    Vec3f cross(const Vec3f& other) const;
    Vec3f project(const Vec3f& other) const;

    btVector3 toBt() const;

};

Vec3f operator*(float scale, const Vec3f &v);

#endif
