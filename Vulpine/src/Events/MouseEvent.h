#pragma once

#include "Event.h"

namespace Vulpine
{

	class VUPLINE_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float xPos, float yPos) : _xPos(xPos), _yPos(yPos) {}

		inline float GetXPos() const { return _xPos; }
		inline float GetYPos() const { return _yPos; }

		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CLASS_CATEGORY(MouseEvent | InputEvent)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMove: " << _xPos << ", " << _yPos;
			return stream.str();
		}

	private:
		float _xPos;
		float _yPos;
	};

	class VUPLINE_API MouseScrollEvent : public Event
	{
		MouseScrollEvent(int xOffset, int yOffset) : _xOffset(xOffset), _yOffset(yOffset) {}

		inline int GetXOffset() { return _xOffset; }
		inline int GetYOffset() { return _yOffset; }

		EVENT_CLASS_TYPE(MouseScroll)
		EVENT_CLASS_CATEGORY(MouseEvent | InputEvent)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseScroll: " << _xOffset << ", " << _yOffset;
			return stream.str();
		}

	private:
		int _xOffset;
		int _yOffset;
	};

	class VUPLINE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButtonCode() { return _button; }

		EVENT_CLASS_CATEGORY(EventCategory::MouseButtonEvent | MouseEvent | InputEvent)

	protected:
		MouseButtonEvent(int buttonCode) : _button(buttonCode) {}
		int _button;
	};
	
	class VUPLINE_API MouseButtonPressEvent : public MouseButtonEvent
	{
		MouseButtonPressEvent(float button, float yPos) : MouseButtonEvent(button) {}


		EVENT_CLASS_TYPE(MouseButtonPress)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPress: " << _button;
			return stream.str();
		}
	};

	class VUPLINE_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
		MouseButtonReleaseEvent(float button, float yPos) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonRelease)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonRelease: " << _button;
			return stream.str();
		}
	};
}