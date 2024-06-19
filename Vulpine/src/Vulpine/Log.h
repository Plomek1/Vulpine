#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Vulpine
{
	class VUPLINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};


}

#define VP_CORE_LOG_TRACE(...) ::Vulpine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VP_CORE_LOG_INFO(...)  ::Vulpine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VP_CORE_LOG_WARN(...)  ::Vulpine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VP_CORE_LOG_ERROR(...) ::Vulpine::Log::GetCoreLogger()->error(__VA_ARGS__)

#define VP_LOG_TRACE(...) ::Vulpine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VP_LOG_INFO(...)  ::Vulpine::Log::GetClientLogger()->info(__VA_ARGS__)
#define VP_LOG_WARN(...)  ::Vulpine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VP_LOG_ERROR(...) ::Vulpine::Log::GetClientLogger()->error(__VA_ARGS__)