#include "vppch.h"
#include "Application.h"

namespace Vulpine
{
	Application::Application() : _running(true)
	{
		_window = (std::unique_ptr<Window>)Window::Create();
	}

	Application::~Application() {}

	void Application::Run()
	{



		while (_running)
		{
			_window->OnUpdate();
		}
	}
}