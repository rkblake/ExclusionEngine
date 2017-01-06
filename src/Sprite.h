#ifndef EE_SPRITE

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"

class Sprite : public Component {
public:
	Sprite() {}
	Sprite(const char* path);
	~Sprite();

	void Draw();
private:
	GLuint vao;
	GLuint textureID;
	GLuint vertex_buffer;
	GLuint uv_buffer;
	static const GLfloat vertices[];
	static const GLfloat uv[];
};

#endif // !EE_SPRITE
