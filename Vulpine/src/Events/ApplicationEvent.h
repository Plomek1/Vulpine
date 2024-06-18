#pragma once

#include "Event.h"

namespace Vulpine 
{
	class VULPINE_API ApplicationEvent : public Event
	{

	};

	class VULPINE_API WindowClose : public ApplicationEvent
	{

	};

	class VULPINE_API WindowMove : public ApplicationEvent
	{

	};

	class VULPINE_API WindowResizeEvent : public ApplicationEvent
	{

	};

	class VULPINE_API WindowFocus : public ApplicationEvent
	{

	};

	class VULPINE_API WindowUnfocus : public ApplicationEvent
	{

	}; 
}