include "./vendor/premake/premake_customization/solution_items.lua"

workspace "HyperDiscord"
	architecture "x86_64"
	startproject "HyperDiscord"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["asio"] = "%{wks.location}/vendor/asio"
IncludeDir["json"] = "%{wks.location}/vendor/json"

group "Dependencies"
	include "vendor/asio"
	include "vendor/json"
	include "vendor/premake"
group ""

project "HyperDiscord"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir)
	objdir ("%{wks.location}/bin-int/" .. outputdir)

	files 
	{ 
		"src/**.cpp",
		"src/**.h"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"src/HyperDiscord",
		"%{IncludeDir.json}"
	}

	links
	{
		"Winhttp.lib",
		"fwpuclnt.lib",
		"ntdsapi.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HP_DIST"
		runtime "Release"
		optimize "on"
