#include "bcpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BeastCode {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	bool Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("BEASTCODE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
		if (s_ClientLogger && s_CoreLogger)
		{
			return true;
		}
		return false;

	}

}