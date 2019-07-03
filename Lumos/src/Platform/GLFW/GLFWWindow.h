#pragma once

#include "LM.h"
#include "App/Window.h"

struct GLFWwindow;

namespace Lumos
{
	namespace Graphics
	{
		enum class RenderAPI : int;
	}

	class LUMOS_EXPORT GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowProperties& properties);
		~GLFWWindow();

		void ToggleVSync() override;
		void SetVSync(bool set) override;
		void SetWindowTitle(const String& title) override;
		void SetBorderlessWindow(bool borderless) override;
		void OnUpdate() override;
		void HideMouse(bool hide) override;
		void SetMousePosition(const Maths::Vector2& pos) override;

		bool Init(const WindowProperties& properties);

		inline void* GetHandle() override { return m_Handle; }

		inline String GetTitle() const override { return m_Data.Title; }
		inline u32 GetWidth()  const override { return m_Data.Width; }
		inline u32 GetHeight() const override { return m_Data.Height; }
		inline float GetScreenRatio() const override { return (float)m_Data.Width / (float)m_Data.Height; }
		inline bool GetExit() const override { return m_Data.Exit; }
		inline void SetExit(bool exit) override { m_Data.Exit = exit; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

		void SetIcon(const String& file);

	protected:

		GLFWwindow* m_Handle;

		struct WindowData
		{
			std::string Title;
			u32 Width, Height;
			bool VSync;
			bool Exit;
			Graphics::RenderAPI m_RenderAPI;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}
