#pragma once
#include "Quad.h"
#include "Texture.h"


class TextureFile : public Quad
{
public:
	
	TextureFile() : m_fileName(" "), Quad() {}
	TextureFile(const char* fileName, glm::vec4 color) :m_fileName(fileName), Quad (color) {}

	void onStart()override;
	void onDraw()override;

private:
    
	const char* m_fileName;
	aie::Texture m_texture;

};

