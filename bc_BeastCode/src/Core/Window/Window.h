#pragma once

#include "bcpch.h"

#include "Core/Base/Base.h"
#include "Core/Events/Event.h"

namespace BeastCode {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

#ifdef BC_CORE_DEBUG
		WindowProps(const std::string& title = "Beast Code Mode : Debug",
			unsigned int width = 2560,
			unsigned int height = 1440)
			: Title(title), Width(width), Height(height)
		{
		}
#endif // BC_CORE_DEBUG

#ifdef BC_CORE_DIST
		WindowProps(const std::string& title = "Beast Code Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
#endif // BC_CORE_DIST

#ifdef BC_CORE_RELEASE
		WindowProps(const std::string& title = "Beast Code Mode : Release",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
#endif // BC_CORE_RELEASE
	};

	// Interface representing a desktop system based Window
	class BEASTCODE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		std::string title = "Beast Code";

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}