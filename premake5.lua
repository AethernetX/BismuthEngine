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
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp" 
    } 

    -- Includes will go here
    --includedirs {
        --""    
    --}

    postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp" 
    } 

    -- Includes will go here
    includedirs {
        "Bismuth/include",    
    }

    links {
        "Bismuth"
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

