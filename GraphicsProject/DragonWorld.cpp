#include "DragonWorld.h"


void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);


	//Light #1
	m_light1 = new Light(
		1,                            //The # of the light
		{ 1.4f, 0.0f, 1.0f },        //Direction
		{ 0.0, 0.0f, 1.0f, 1.0f },    //Ambient
		{ 0.6f, 0.2f, 0.0f, 1.0f },   //Diffuse
		{ 0.2f, 1.0f, 0.3f, 1.0f }    //Specular
	);
	add(m_light1);
	


	//Light #2
	m_light2 = new Light(
		2,                            //The # of the light
		{ -1.0f, -0.5f, 0.5f },        //Direction
		{ 0.2, 0.6f, 0.9f, 1.0f },    //Ambient
		{ 0.4f, 0.2f, 0.0f, 1.0f },   //Diffuse
		{ 1.0f, 1.0f, 1.0f, 1.0f }    //Specular
	);
	add(m_light2);


	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f});
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	
	//Cube
	m_cube = new Cube();
	m_cube->getTransform()->setPosition({ 2.0f, 0.0f, 0.0f });
	m_cube->getTransform()->setScale(glm::vec3(5.0f));
	add(m_cube);


	//Gets and adds the texture
	m_texture = new TextureFile("earth_normal.jpg", { 0.3f, 0.3f, 0.3f, 1.0f });
	add(m_texture);
}


void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light1);
	destroy(m_light2);
	destroy(m_dragon);
	destroy(m_texture);
}