#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks//stdout_color_sinks.h"

namespace Hazel {

	class HAZEL_API Log
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

		static void init();
	};
}

#define HZ_CORE_ERROR(...) ::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define HZ_ERROR(...) ::Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)  ::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)  ::Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_FATAL(...) ::Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)