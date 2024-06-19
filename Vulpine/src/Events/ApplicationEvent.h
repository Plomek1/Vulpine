#pragma once

#include "Event.h"
#include <sstream>

namespace Vulpine 
{
	class VUPLINE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	};


	class VUPLINE_API WindowResizeEvent : public Event
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

	class VUPLINE_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	};

	class VUPLINE_API WindowUnfocusEvent : public Event
	{
		WindowUnfocusEvent() {}

		EVENT_CLASS_TYPE(WindowUnfocus)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	}; 
}