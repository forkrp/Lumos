#pragma once
#include "Camera.h"

namespace Lumos
{

	class LUMOS_EXPORT ThirdPersonCamera : public Camera
	{
	public:
		ThirdPersonCamera(float FOV, float Near, float Far, float aspect);
		ThirdPersonCamera(float pitch, float yaw, const maths::Vector3& position, float FOV, float Near, float Far, float aspect);
		virtual ~ThirdPersonCamera() override;

		virtual void HandleMouse(float dt, float xpos, float ypos) override;
		virtual void HandleKeyboard(float dt) override;

		bool m_Free;
	};
}

