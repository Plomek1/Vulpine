workspace "Vulpine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Vulpine/vendor/GLFW/include"

include "Vulpine/vendor/GLFW"

project "Vulpine"
	location "Vulpine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vppch.h"
	pchsource "%{prj.name}/src/vppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"VP_PLATFORM_WINDOWS",
			"VP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "VP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"	
		defines "VP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"		
		defines "VP_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vulpine/vendor/spdlog/include",
		"Vulpine/src"
	}

	links
	{
		"Vulpine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"VP_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "VP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"	
		defines "VP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"	
		defines "VP_DIST"
		optimize "On"