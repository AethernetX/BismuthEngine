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