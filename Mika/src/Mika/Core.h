#pragma once

#ifdef MK_PLATFORM_WINDOWS
	#ifdef MK_BUILD_DLL
		#define MIKA_API __declspec(dllexport)
	#else
		#define MIKA_API __declspec(dllimport)
	#endif
#else
	#error Mika only supports Windows!
#endif

#ifdef MK_ENABLE_ASSERTS
	#define MIKA_ASSERT(x, ...) { if(!(x)) { MIKE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MIKA_CORE_ASSERT(x, ...) { if(!(x)) { MIKE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MIKA_ASSERT(x, ...)
	#define MIKA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)