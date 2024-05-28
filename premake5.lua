workspace "Bismuth"  
    architecture "x64"

    configurations { 
        "Debug", 
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bismuth"  
    location "Bismuth"    
    kind "SharedLib"   
    language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    } 

    -- Includes will go here
    includedirs {
        "thirdparty/spdlog/include"    
    }

    filter "system:windows"
	       cppdialect "C++17"
		    staticruntime "On"
		    systemversion "latest"

        defines {
		    "BI_PLATFORM_WINDOWS",
		    "BI_BUILD_DLL"
	    }

        prebuildcommands {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox")
	    }

        postbuildcommands {
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	    }

    filter "configurations:Debug"
        defines { "BI_DEBUG" }  
        symbols "On" 

    filter "configurations:Release"  
        defines { "NDEBUG", "BI_RELEASE" }    
        optimize "On"
    filter "configurations:Dist"  
        defines { "NDEBUG", "BI_DIST" }    
        optimize "On"

project "Sandbox"  
    location "Sandbox"    
    kind "ConsoleApp"   
    language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" 
    } 

    -- Includes will go here
    includedirs {
        "thirdparty/spdlog/include",
        "Bismuth",    
    }

    links {
        "Bismuth"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"BI_PLATFORM_WINDOWS"
		}

    filter "configurations:Debug"
        defines { "BI_DEBUG" }  
        symbols "On" 

    filter "configurations:Release"  
        defines { "NDEBUG", "BI_RELEASE" }    
        optimize "On"
    filter "configurations:Dist"  
        defines { "NDEBUG", "BI_DIST" }    
        optimize "On"

