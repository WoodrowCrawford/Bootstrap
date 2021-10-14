#pragma once
#include "Mesh.h"


class Cube : public Mesh
{
public:
	Cube() : Mesh() {}
	~Cube() {}


	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:                          //R    G     B
	glm::vec4 m_color = glm::vec4(0.9f, 0.2f, 0.2f, 1.0f);
	Vertex* generateVertices(unsigned int& vertexCount) override;
	void initializeCorner(Vertex* vertices, int vertexCount, int index, glm::vec3 position);


};

