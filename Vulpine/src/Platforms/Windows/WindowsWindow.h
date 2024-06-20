#pragma once

#include "Vulpine/Window.h"

#include <GLFW/glfw3.h>

namespace Vulpine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props = WindowProperties());
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() override { return _data.width; }
		inline unsigned int GetHeight() override { return _data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { _data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool VSyncEnabled() const override;

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Close();


		GLFWwindow* _window;

		struct WindowData
		{
			std::string title;

			unsigned int width;
			unsigned int height;
			bool vSyncEnabled;

			EventCallbackFn eventCallback;
		};

		WindowData _data;

	};
}

