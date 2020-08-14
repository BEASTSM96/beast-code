workspace "Beast-Code"
	architecture "x64"
	startproject "bcSandox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "bc/Core"
project "bc_BeastCode"
	location "bc_BeastCode"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src"
		
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "CORE_BC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CORE_BC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CORE_BC_DIST"
		runtime "Release"
		optimize "on"
		
group "bc/Base"
project "bcSandox"
	location "bcSandox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
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
		"bc_BeastCode/src"
	}

	links
	{
		"bc_BeastCode"
	}

	filter "system:windows"
		systemversion "latest"
			
	filter "configurations:Debug"
		defines "CORE_BC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CORE_BC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CORE_BC_DIST"
		runtime "Release"
		optimize "on"