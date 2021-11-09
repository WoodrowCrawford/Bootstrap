#pragma once
#include "Camera.h"
class PlayerCamera : public Camera
{
public:
	PlayerCamera() : Camera() {}
	PlayerCamera(float fieldOfView, float nearClip, float farClip) : Camera(fieldOfView, nearClip, farClip) {}
	~PlayerCamera() {}

	void onUpdate(float deltaTime) override;

private:
	//The move speed of the WASD keys
	float m_moveSpeed = 1.0;

	//The look speed of the mouse
	float m_lookSpeed = 0.2f;

	double m_currentMouseX = 0.0;
	double m_currentMouseY = 0.0;
	double m_previousMouseX = 0.0;
	double m_previousMouseY = 0.0;
};

