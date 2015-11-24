#include "Vec2f.h"

Vec2f::Vec2f() : x(0), y(0) {}

Vec2f::Vec2f(float x, float y) : x(x), y(y) {}

Vec2f::Vec2f(glm::vec2 glm_vec) : x(glm_vec.x), y(glm_vec.y) {}

Vec2f Vec2f::operator*(float scale) const {
    return Vec2f(x * scale, y * scale);
}

Vec2f Vec2f::operator/(float scale) const {
    return Vec2f(x / scale, y / scale);
}

Vec2f Vec2f::operator+(const Vec2f& other) const {
    return Vec2f(x + other.x, y + other.y);
}

Vec2f Vec2f::operator-(const Vec2f& other) const {
    return Vec2f(x - other.y, y - other.y);
}

Vec2f Vec2f::operator-() const {
    return Vec2f(-x, -y);
}

const Vec2f& Vec2f::operator-=(const Vec2f& other) {
    x -= other.x;
    y -= other.x;
    return *this;
}

bool Vec2f::operator==(const Vec2f& other) const {
    return x == other.x && y == other.y;
}

bool Vec2f::operator!=(const Vec2f& other) const {
    return x != other.x || y != other.x;
}

float Vec2f::length() const {
    return sqrt(x * x + y * y);
}

float Vec2f::lengthSquared() const {
    return x * x + y * y;
}

void Vec2f::normalize() {
    if(x == 0 || y == 0)
        return;

    x /= length();
    y /= length();
}

float Vec2f::dot(const Vec2f& other) const {
    return x * other.x + y * other.y;
}

Vec2f Vec2f::project(const Vec2f& other) const {
    return (dot(other) / other.lengthSquared() * other);
}

Vec2f operator*(float scale, const Vec2f &v) {
	return v * scale;
}
