#ifndef EE_MATRIX4X4F
#define EE_MATRIX4X4F

#include "Vec3f.h"
#include "Vec4f.h"
#include "Mat3.h"
#include "glm/glm.hpp"

//Column-major order

class Mat3;

class Matrix4x4f {
public:
    static const float s_directionMatrixNormalizationTolerance;

    Matrix4x4f();
    Matrix4x4f(glm::mat4 glm_mat);
    Matrix4x4f(Mat3 mat3);

    float& operator[](int i);

    Matrix4x4f operator*(const Matrix4x4f &other) const;
	Matrix4x4f operator*=(const Matrix4x4f &other);

	bool operator==(const Matrix4x4f &other) const;
	bool operator!=(const Matrix4x4f &other) const;

	void Set(int i, int j, float val);
	float Get(int i, int j) const;

	void SetIdentity();
	Matrix4x4f Transpose() const;

	// Returns false if there is no inverse, true if there is one
	// Warning! Expensive function!
	bool Inverse(Matrix4x4f &inverse) const;

	// For use with OpenGL
	//void GL_Load();
	//void GL_Set_Modelview();
	//void GL_Set_Projection();
	//static Matrix4x4f GL_Get_Modelview();
	//static Matrix4x4f GL_Get_Projection();
	//void GL_Mult();

	// Transformation matrix generators
	static Matrix4x4f ScaleMatrix(const Vec3f &scale);
	static Matrix4x4f TranslateMatrix(const Vec3f translation);
	static Matrix4x4f RotateMatrix_X(float angle);
	static Matrix4x4f RotateMatrix_Y(float angle);
	static Matrix4x4f RotateMatrix_Z(float angle);
	static Matrix4x4f RotateMatrix(const Vec3f &eulerAngles);
	static Matrix4x4f DirectionMatrix(const Vec3f &direction, const Vec3f &up);
	static Matrix4x4f DirectionMatrix_AutoUp(const Vec3f &direction); // Chooses up such that it doesn't lock up
	static Matrix4x4f CameraDirectionMatrix(const Vec3f &direction, const Vec3f &up);
	static Matrix4x4f CameraDirectionMatrix_AutoUp(const Vec3f &direction); // Chooses up such that it doesn't lock up
	static Matrix4x4f IdentityMatrix();

	static Matrix4x4f PerspectiveMatrix(float fovY, float aspectRatio, float zNear, float zFar);
	static Matrix4x4f OrthoMatrix(float left, float right, float bottom, float top, float zNear, float zFar);

	Vec4f operator*(const Vec4f &vec) const;
	Vec3f operator*(const Vec3f &vec) const;
private:
    float m_elements[16];
};

#endif
