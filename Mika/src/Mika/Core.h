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

#define BIT(x) (1 << x)