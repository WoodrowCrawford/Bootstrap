#include "DragonWorld.h"


void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	
	//Light
	m_light = new Light(
		{ 6.0f, 1.0f, 1.0f },          //Direction
		{ 0.5f, 0.5f, 1.5f, 1.0f },    //Ambient
		{ 2.0f, 3.0f, 4.0f, 1.0f },    //Diffuse
		{ 6.0f, 1.0f, 1.0f, 2.0f }     //Specular
	);
	add(m_light);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f});
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	
	//Cube
	m_cube = new Cube();
	m_cube->getTransform()->setPosition({ 2.0f, 0.0f, 0.0f });
	m_cube->getTransform()->setScale(glm::vec3(0.3f));
	add(m_cube);


}


void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
}