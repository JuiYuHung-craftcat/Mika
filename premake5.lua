workspace "Mika"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Mika/vendor/GLFW/include"
IncludeDir["Glad"] = "Mika/vendor/Glad/include"
IncludeDir["ImGui"] = "Mika/vendor/imgui"
IncludeDir["glm"] = "Mika/vendor/glm"

include "Mika/vendor/GLFW"
include "Mika/vendor/Glad"
include "Mika/vendor/imgui"

project "Mika"
	location "Mika"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mkpch.h"
	pchsource "Mika/src/mkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	    "%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MK_PLATFORM_WINDOWS",
			"MK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions 
		{
			"/source-charset:utf-8"
		}

	filter "configurations:Debug"
		defines "MIKA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MIKA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MIKA_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Mika/vendor/spdlog/include",
		"Mika/src",
		"Mika/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Mika"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MK_PLATFORM_WINDOWS"
		}
		
		buildoptions 
		{
			"/source-charset:utf-8"
		}

	filter "configurations:Debug"
		defines "MIKA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MIKA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MIKA_DIST"
		runtime "Release"
		optimize "on"