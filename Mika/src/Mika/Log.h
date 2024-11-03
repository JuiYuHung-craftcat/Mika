#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Mika {

	class MIKA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define MK_CORE_TRACE(...)    ::Mika::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MK_CORE_INFO(...)     ::Mika::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MK_CORE_WARN(...)     ::Mika::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MK_CORE_ERROR(...)    ::Mika::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MK_CORE_CRITICAL(...) ::Mika::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MK_TRACE(...)         ::Mika::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MK_INFO(...)          ::Mika::Log::GetClientLogger()->info(__VA_ARGS__)
#define MK_WARN(...)          ::Mika::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MK_ERROR(...)         ::Mika::Log::GetClientLogger()->error(__VA_ARGS__)
#define MK_CRITICAL(...)      ::Mika::Log::GetClientLogger()->critical(__VA_ARGS__)