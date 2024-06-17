workspace("Bismuth")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "thirdparty/GLFW/include"

include("thirdpartyPremake/GLFW")

project("Bismuth")
location("Bismuth")
kind("SharedLib")
language("C++")

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

pchheader("bich.h")
pchsource("Bismuth/src/bich.cpp")

files({
	"%{prj.name}/**.h",
	"%{prj.name}/**.cpp",
})

-- Includes will go here
includedirs({
	"%{prj.name}/src",
	"thirdparty/spdlog/include",
	"%{IncludeDir.GLFW}",
})

-- to do: Make sure to see if a user is using Mingw or not

links({
	"GLFW",
	"gdi32"
})

filter("system:windows")
	cppdialect("C++17")
	staticruntime("On")
	systemversion("latest")

	defines({
		"BI_PLATFORM_WINDOWS",
		"BI_BUILD_DLL",
	})

	prebuildcommands({
		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
	})

	postbuildcommands({
		("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
	})

	--VS2022 settings
	filter{"configurations:Debug", "action:vs2022"}
		defines({ "BI_DEBUG" })
		buildoptions "/MDd"
		symbols("On")

	filter{"configurations:Release", "action:vs2022"}
		defines({ "NDEBUG", "BI_RELEASE" })
		buildoptions "/MD"
		optimize("On")

	filter{"configurations:Dist", "action:vs2022"}
		defines({ "NDEBUG", "BI_DIST" })
		buildoptions "/MD"
		optimize("On")

	
	--Gmake settings
	filter{"configurations:Debug", "action:gmake2"}
		defines({ "BI_DEBUG" })
		symbols("On")

	filter{"configurations:Release", "action:gmake2"}
		defines({ "NDEBUG", "BI_RELEASE" })
		optimize("On")

	filter{"configurations:Dist", "action:gmake2"}
		defines({ "NDEBUG", "BI_DIST" })
		optimize("On")


project("Sandbox")
location("Sandbox")
kind("ConsoleApp")
language("C++")

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files({
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp",
})

-- Includes will go here
includedirs({
	"thirdparty/spdlog/include",
	"Bismuth/src",
})

links({
	"Bismuth",
})

filter("system:windows")
	cppdialect("C++17")
	staticruntime("On")
	systemversion("latest")

	defines({
		"BI_PLATFORM_WINDOWS",
	})

	--VS2022 settings
	filter{"configurations:Debug", "action:vs2022"}
		defines({ "BI_DEBUG" })
		buildoptions "/MDd"
		symbols("On")

	filter{"configurations:Release", "action:vs2022"}
		defines({ "NDEBUG", "BI_RELEASE" })
		buildoptions "/MD"
		optimize("On")

	filter{"configurations:Dist", "action:vs2022"}
		defines({ "NDEBUG", "BI_DIST" })
		buildoptions "/MD"
		optimize("On")

	--Gmake settings
	filter{"configurations:Debug", "action:gmake2"}
		defines({ "BI_DEBUG" })
		symbols("On")

	filter{"configurations:Release", "action:gmake2"}
		defines({ "NDEBUG", "BI_RELEASE" })
		optimize("On")

	filter{"configurations:Dist", "action:gmake2"}
		defines({ "NDEBUG", "BI_DIST" })
		optimize("On")