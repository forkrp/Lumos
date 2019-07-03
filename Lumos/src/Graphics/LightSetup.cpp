#include "LM.h"
#include "LightSetUp.h"
#include <imgui/imgui.h>

namespace Lumos
{

    LightSetup::LightSetup()
	{
	}

	LightSetup::~LightSetup()
	{
	};

	void LightSetup::Add(std::shared_ptr<Graphics::Light>& light)
	{
		m_Lights.push_back(light);
	}

	void LightSetup::Remove(std::shared_ptr<Graphics::Light>& light)
	{
		for (u32 i = 0; i < m_Lights.size(); i++)
		{
			if (m_Lights[i] == light)
			{
				m_Lights.erase(m_Lights.begin() + i);
				break;
			}
		}
	}

	void LightSetup::Clear()
	{
		m_Lights.clear();
	}

	void LightSetup::OnImGUI()
	{
		std::string title = "Light Setup : " + StringFormat::ToString(static_cast<int>(m_Lights.size()));
		if (ImGui::TreeNode(title.c_str()))
		{
			for (u32 i = 0; i < m_Lights.size(); i++)
			{
			}

			ImGui::TreePop();
		}
	}
}
