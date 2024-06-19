#pragma once

#include "Vulpine/Core.h"

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
		InputEvent = BIT(2),
		KeyboardEvent = BIT(3),
		MouseEvent = BIT(4),
		MouseButtonEvent = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class VUPLINE_API Event
	{
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

	private:
		friend class EventDispatcher;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : _event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (_event.GetEventType() == T::GetStaticType())
			{
				_event._handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}

	private:
		Event& _event;
	};
}