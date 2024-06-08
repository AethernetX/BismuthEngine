project "GLFW"
    kind "StaticLib"
    language "C"
   
    GLFWdir = "../../thirdparty/GLFW"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- to do: Make sure to see if a user is using Mingw or not
    -- see line 66 for more information

	files
	{ 
        GLFWdir .. "/src/glfw_config.h",
        
        GLFWdir .. "/src/internal.h", 
        GLFWdir .. "/src/platform.h", 
        GLFWdir .. "/src/mappings.h",
        GLFWdir .. "/src/context.c", 
        GLFWdir .. "/src/init.c", 
        GLFWdir .. "/src/input.c", 
        GLFWdir .. "/src/monitor.c", 
        GLFWdir .. "/src/platform.c", 
        GLFWdir .. "/src/vulkan.c", 
        GLFWdir .. "/src/window.c",
        GLFWdir .. "/src/egl_context.c", 
        GLFWdir .. "/src/osmesa_context.c", 
        GLFWdir .. "/src/null_platform.h", 
        GLFWdir .. "/src/null_joystick.h",
        GLFWdir .. "/src/null_init.c", 
        GLFWdir .. "/src/null_monitor.c", 
        GLFWdir .. "/src/null_window.c", 
        GLFWdir .. "/src/null_joystick.c",
        GLFWdir .. "/include/GLFW/glfw3.h",
        GLFWdir .. "/include/GLFW/glfw3native.h",
    }
    
	filter "system:windows"
        buildoptions { "-std=c11", "-lgdi32" }
        systemversion "latest"
        staticruntime "On"
        
        files
        {
            GLFWdir .. "/src/win32_time.h", 
            GLFWdir .. "/src/win32_thread.h", 
            GLFWdir .. "/src/win32_module.c",
            GLFWdir .. "/src/win32_time.c", 
            GLFWdir .. "/src/win32_thread.c",
            GLFWdir .. "/src/win32_platform.h", 
            GLFWdir .. "/src/win32_joystick.h", 
            GLFWdir .. "/src/win32_init.c",
            GLFWdir .. "/src/win32_joystick.c", 
            GLFWdir .. "/src/win32_monitor.c", 
            GLFWdir .. "/src/win32_window.c",
            GLFWdir .. "/src/wgl_context.c",
        }

		defines 
		{ 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
		}

        -- linking gdi32 should not cause any issues when using either vs2022 or mingw
        --filter "action:gmake2"
            --prelinkmessage("using gmake2")

            --files
            --{

            --}

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"