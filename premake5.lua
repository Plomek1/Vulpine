workspace "Vulpine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
		defines "VP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VP_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VP_DIST"
		optimize "On"