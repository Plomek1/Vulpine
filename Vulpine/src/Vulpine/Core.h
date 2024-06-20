#pragma once
namespace Vulpine
{
	#ifdef VP_PLATFORM_WINDOWS
		#ifdef VP_BUILD_DLL
			#define VUPLINE_API __declspec(dllexport)
		#else
			#define VUPLINE_API __declspec(dllimport)
		#endif
	#else
		#error Platform unsupported
	#endif
	
	#define BIT(x) (1 << x)
}