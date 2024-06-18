#pragma once

#include "Event.h"

namespace Vulpine
{
	class VULPINE_API KeyEvent : public Event
	{

	};

	class VULPINE_API KeyPressEvent : public KeyEvent
	{

	};

	class VULPINE_API KeyReleaseEvent : public KeyEvent
	{

	};
}