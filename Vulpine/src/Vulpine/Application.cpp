#include "vppch.h"
#include "Application.h"

namespace Vulpine
{
	void Application::Run()
	{
		KeyPressEvent e = KeyPressEvent(2, 12);

		VP_LOG_TRACE(e.ToString());

		while (true);
	}
}