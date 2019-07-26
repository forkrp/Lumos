#include "LM.h"
#include "ParticleComponent.h"
#include "Graphics/ParticleEmitter.h"
#include "ECS/Entity.h"
#include "App/Scene.h"
#include "Graphics/ParticleManager.h"
#include "Physics/LumosPhysicsEngine/PhysicsObject3D.h"
#include <imgui/imgui.h>

namespace Lumos
{
    ParticleComponent::ParticleComponent()
    {
        m_Name = "Particle";
        m_BoundingShape = std::unique_ptr<Maths::BoundingBox>();
    }
    
    ParticleComponent::ParticleComponent(std::shared_ptr<ParticleEmitter>& emitter)
            : m_ParticleEmitter(emitter), m_PositionOffset(Maths::Vector3(0.0f,0.0f,0.0f))
    {
		m_Name = "Particle";
		m_BoundingShape = std::unique_ptr<Maths::BoundingBox>(emitter->CalculateBoundingBox());
    }

    void ParticleComponent::Init()
    {
    }

	void ParticleComponent::DebugDraw(uint64 debugFlags)
	{
	}

	void ParticleComponent::OnUpdateComponent(float dt)
    {
    }

	void ParticleComponent::OnIMGUI()
	{
	}
}