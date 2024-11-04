#pragma once

#ifdef MK_PLATFORM_WINDOWS
#if HZ_DYNAMIC_LINK
	#ifdef MK_BUILD_DLL
		#define MIKA_API __declspec(dllexport)
	#else
		#define MIKA_API __declspec(dllimport)
	#endif
#else
	#define MIKA_API
#endif
#else
	#error Mika only supports Windows!
#endif

#ifdef MK_DEBUG
	#define MK_ENABLE_ASSERTS
#endif

#ifdef MK_ENABLE_ASSERTS
	#define MK_ASSERT(x, ...) { if(!(x)) { MIKE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MK_CORE_ASSERT(x, ...) { if(!(x)) { MIKE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MK_ASSERT(x, ...)
	#define MK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)