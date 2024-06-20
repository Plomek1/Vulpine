#pragma once

#include "Core.h"
#include "Window.h"

namespace Vulpine
{
	class VUPLINE_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		bool _running = true;
		std::unique_ptr<Window> _window;
	};

	Application* CreateApplication();
}


