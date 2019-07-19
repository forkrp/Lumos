#pragma once

#include "LM.h"
#include "App/Window.h"

namespace Lumos
{

	class LUMOS_EXPORT GLFMWindow : public Window
	{
	public:
		GLFMWindow(const WindowProperties& properties);
		~GLFMWindow();

		void ToggleVSync() override;
		void SetWindowTitle(const String& title) override;
		void SetBorderlessWindow(bool borderless) override;
		void OnUpdate() override;

		bool Init(const WindowProperties& properties, const String& title);

		inline void* GetHandle() override { return (void*)nullptr; }//m_Handle; }

		inline uint GetWidth()  const override { return 500; }
		inline uint GetHeight() const override { return 500; }
        
        bool GetExit() const override { return false; }
        void SetExit(bool exit) override { }
        
        void SetVSync(bool set) override { }
        float GetScreenRatio() const override { return 1.0f; }
        
        void SetEventCallback(const EventCallbackFn& callback) override { };
        
        String GetTitle() const override { return "Mobile"; }

	protected:

		uint m_Handle;
	};
}
