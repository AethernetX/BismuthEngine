#pragma once

#ifdef BI_PLATFORM_WINDOWS
	#ifdef BI_BUILD_DLL
		#define BISMUTH_API __declspec(dllexport)
	#else
		#define BISMUTH_API __declspec(dllimport)
	#endif
#else
	#error Bismuth only supports Windows currently!
#endif

#ifdef BI_ENABLE_ASSERTS
	#define BI_ASSERT(x, ...) { if(!(x)) { BI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BI_CORE_ASSERT(x, ...) { if(!(x)) { BI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BI_ASSERT(x, ...)
	#define BI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)