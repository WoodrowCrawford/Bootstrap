#include "TextureFile.h"
#include <gl_core_4_4.h>
#include "GLFW//glfw3.h"

void TextureFile::onStart()
{
	Quad::onStart();
}

void TextureFile::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
	{
		printf("Error. No shader was applied.");
	}

	int difuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (difuseTextureUniform >= 0)
	{
		glUniform1i(difuseTextureUniform, 0);
	}
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());
	Quad::onDraw();
}
