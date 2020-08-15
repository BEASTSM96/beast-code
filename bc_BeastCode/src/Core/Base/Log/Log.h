#pragma once


#include "Core/Base/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BeastCode {

	class Log
	{
	public:
		static bool Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define BC_CORE_TRACE(...)    ::BeastCode::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BC_CORE_INFO(...)     ::BeastCode::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BC_CORE_WARN(...)     ::BeastCode::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BC_CORE_ERROR(...)    ::BeastCode::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BC_CORE_FATAL(...)    ::BeastCode::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BC_TRACE(...)	      ::BeastCode::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BC_INFO(...)	      ::BeastCode::Log::GetClientLogger()->info(__VA_ARGS__)
#define BC_WARN(...)	      ::BeastCode::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BC_ERROR(...)	      ::BeastCode::Log::GetClientLogger()->error(__VA_ARGS__)
#define BC_FATAL(...)	      ::BeastCode::Log::GetClientLogger()->critical(__VA_ARGS__) 