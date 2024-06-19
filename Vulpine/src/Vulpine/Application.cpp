#include "Application.h"

#include "Log.h"
#include "Events/KeyEvent.h"

namespace Vulpine
{
	void Application::Run()
	{
		KeyPressEvent e = KeyPressEvent(2, 12);

		VP_LOG_TRACE(e.ToString());

		while (true);
	}
}