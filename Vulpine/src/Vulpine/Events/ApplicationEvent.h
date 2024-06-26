#pragma once

#include "Event.h"

namespace Vulpine 
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	};


	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int xSize, int ySize) : _xSize(xSize), _ySize(ySize) {}

		inline int GetXSize() { return _xSize; }
		inline int GetYSize() { return _ySize; }

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(ApplicationEvent)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowResize: " << _xSize << ", " << _ySize;
			return stream.str();
		}

	private:
		int _xSize;
		int _ySize
;
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	};

	class WindowUnfocusEvent : public Event
	{
		WindowUnfocusEvent() {}

		EVENT_CLASS_TYPE(WindowUnfocus)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	}; 
}