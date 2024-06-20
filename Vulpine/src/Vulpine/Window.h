#pragma once

#include "vppch.h"

#include "Vulpine/Core.h"

namespace Vulpine
{
	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& title = "Vulpine", unsigned int width = 1280, unsigned int height = 720) : title(title), width(width), height(height) {}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool VSyncEnabled() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
		virtual ~Window() {}
	};
}
