#pragma once

#include "Event.h"

namespace Vulpine
{
	class VULPINE_API MouseEvent
	{

	};

	class VULPINE_API MouseButtonEvent : public MouseEvent
	{

	};

	class VULPINE_API MouseMoveEvent : public MouseEvent
	{

	};

	class VULPINE_API MouseScrollEvent : public MouseEvent
	{

	};

	class VULPINE_API MouseButtonPressEvent : public MouseButtonEvent
	{

	};

	class VULPINE_API MouseButtonReleaseEvent : public MouseButtonEvent
	{

	};
}