#pragma once

#include "Event.h"

namespace Vulpine
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(KeyboardEvent | InputEvent)

	protected:
		KeyEvent(int keyCode) : _keyCode(keyCode) {}
		int _keyCode;
	};

	class KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }

		EVENT_CLASS_TYPE(KeyPress)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyPress: " << _keyCode << " (" << _repeatCount << " repeats)";
			return stream.str();
		}

	private:
		int _repeatCount;

	};

	class KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}
		
		EVENT_CLASS_TYPE(KeyRelease)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyRelease: " << _keyCode;
			return stream.str();
		}
	};
}