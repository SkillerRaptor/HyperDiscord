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
IncludeDir["httplib"] = "%{wks.location}/vendor/httplib"
IncludeDir["json"] = "%{wks.location}/vendor/json"
IncludeDir["openssl"] = "%{wks.location}/vendor/openssl/include"

group "Dependencies"
	include "vendor/premake"
	--include "vendor/httplib"
	--include "vendor/json"
	--include "vendor/openssl"
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
		"%{IncludeDir.httplib}",
		"%{IncludeDir.json}",
		"%{IncludeDir.openssl}",
	}

	links
	{
		"%{wks.location}/vendor/openssl/lib/libcrypto.lib",
		"%{wks.location}/vendor/openssl/lib/libssl.lib"
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
