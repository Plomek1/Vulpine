#include "vppch.h"
#include "WindowsWindow.h"

namespace Vulpine
{
	static bool glfwInitialized = false;

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow() 
	{
		Close();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		VP_CORE_LOG_TRACE("Window created: {0}, {1}, {2}", _data.title, _data.width, _data.height);

		if (!glfwInitialized)
		{
			int success = glfwInit();
			if (!success) VP_CORE_LOG_ERROR("Window initialization failure!");
			glfwInitialized = true;
		}

		_window = glfwCreateWindow(_data.width, _data.height, _data.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);
	}

	void WindowsWindow::Close()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		_data.vSyncEnabled = enabled;
	}

	bool WindowsWindow::VSyncEnabled() const
	{
		return _data.vSyncEnabled;
	}
}