#ifndef EE_SPRITE

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <vector>

#include "Component.h"
#include "Texture.h"

class Sprite : public Component {
public:
	Sprite() {}
	Sprite(const char* path);
	~Sprite();

	void Render();
private:
	GLuint vao;
	GLuint textureID;
	Texture tex;
	GLuint vertex_buffer;
	GLuint uv_buffer;
	static const GLfloat vertices[];
	static const GLfloat uv[];
};

#endif // !EE_SPRITE
