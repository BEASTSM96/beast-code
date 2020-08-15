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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "bc_BeastCode/third_party/GLFW/include"
IncludeDir["Glad"] = "bc_BeastCode/third_party/Glad/include"
IncludeDir["ImGui"] = "bc_BeastCode/third_party/imgui"
IncludeDir["bc_FileDialog"] = "bc_FileDialog"

group "bc/Dependencies"
	include "bc_BeastCode/third_party/GLFW"
	include "bc_BeastCode/third_party/Glad"
	include "bc_BeastCode/third_party/imgui"

group "bc/Core"
project "bc_BeastCode"
	location "bc_BeastCode"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "bcpch.h"
	pchsource "bc_BeastCode/src/bcpch.cpp"

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
		"%{prj.name}/src",
		"%{prj.name}/third_party/spdlog/include/",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"bc_FileDialog/src"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"bc_FileDialog"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"BC_PLATFORM_WINDOWS",
			"BC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
	filter "configurations:Debug"
		defines "BC_CORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BC_CORE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BC_CORE_DIST"
		runtime "Release"
		optimize "on"
	
group "bc/Core"
project "bc_FileDialog"
	location "bc_FileDialog"
	kind "StaticLib"
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

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/third_party/dirent/include",
		"%{prj.name}/third_party/imguifiledialog/ImGuiFileDialog",
		"bc_BeastCode/src",
		"bc_BeastCode/third_party/spdlog/include",
		"bc_BeastCode/third_party"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"BC_PLATFORM_WINDOWS",
			"BC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
	filter "configurations:Debug"
		defines "BC_CORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BC_CORE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BC_CORE_DIST"
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
		"bc_BeastCode/src",
		"bc_BeastCode/third_party/spdlog/include",
		"bc_BeastCode/third_party"
	}

	links
	{
		"bc_BeastCode"
	}

	filter "system:windows"
		systemversion "latest"
			
		
		defines
		{
			"BC_PLATFORM_WINDOWS",
			"BC_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "BC_CORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BC_CORE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BC_CORE_DIST"
		runtime "Release"
		optimize "on"