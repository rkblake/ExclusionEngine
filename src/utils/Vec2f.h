#ifndef EE_VEC2F
#define EE_VEC2F

#include <glm/glm.hpp>
#include <cmath>

class Vec2f {
public:
    float x, y;

    Vec2f();
    Vec2f(float x, float y);
    Vec2f(glm::vec2 glm_vec);

    Vec2f operator*(float scale) const;
    Vec2f operator/(float scale) const;
    Vec2f operator+(const Vec2f& other) const;
    Vec2f operator-(const Vec2f& other) const;
    Vec2f operator-() const;
    const Vec2f& operator-=(const Vec2f& other);


    bool operator==(const Vec2f& other) const;
    bool operator!=(const Vec2f& other) const;

    float length() const;
    float lengthSquared() const;
    void normalize();
    float dot(const Vec2f& other) const;
    Vec2f cross(const Vec2f& other) const;
    Vec2f project(const Vec2f& other) const;

};

Vec2f operator*(float scale, const Vec2f &v);

#endif
