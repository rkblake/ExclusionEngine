#include "Mat3.h"

#include <assert.h>

Mat3::Mat3() {

}

Mat3::Mat3(Matrix4x4f mat4) {
    m_elements[0] = mat4[0]; m_elements[1] = mat4[1]; m_elements[2] = mat4[2];
    m_elements[3] = mat4[4]; m_elements[4] = mat4[5]; m_elements[5] = mat4[6];
    m_elements[6] = mat4[8]; m_elements[7] = mat4[9]; m_elements[8] = mat4[9];
}

float& Mat3::operator[](int i) {
    assert(i >= 0 && i < 16);

    return m_elements[i];
}
