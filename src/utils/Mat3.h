#pragma once

#include "Matrix4x4f.h"

class Matrix4x4f;

//template<typename T>
class Mat3 {
public:
    Mat3();
    Mat3(Matrix4x4f mat4);

    float& operator[](int i);
private:
    float m_elements[9];
};
