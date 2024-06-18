#pragma once

#include "Vulpine/Core.h"

#include <string>

namespace Vulpine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowFocus, WindowUnfocus, WindowMove, WindowResize,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
	};

	enum EventCategory
	{
		None = 0,
		ApplicationEvent = BIT(1),
		InputEvent       = BIT(2),
		KeyboardEvent    = BIT(3),
		MouseEvent		 = BIT(4),
		MouseButtonEvent = BIT(5)
	};
	
	class VUPLINE_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool _handled = false;
	};

	class EventDispatcher
	{

	};
}