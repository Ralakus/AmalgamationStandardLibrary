
Is32bit = false  --If false, it'll be 64 bit


workspace "Amalgamation"
    language "C++"   
    location "build"

    if(Is32bit) then
        architecture "x86_64"
    else
        architecture "x86"
    end

    configurations { "Debug", "Release" }

    filter { "configurations:Debug" }
        symbols "On"
    filter { }

    filter { "configurations:Release" }
        optimize "On"
    filter { }
    
    targetdir ("build/bin/%{prj.name}/%{cfg.longname}")

    objdir ("build/obj/%{prj.name}/%{cfg.longname}")

    
project "Amalgamation"

    kind "ConsoleApp"

    defines { "GLFW_INCLUDE_VULKAN" }

    includedirs "Amalgamation"

    files { "**.hpp", "**.cpp", "**.inl" }

    filter "configurations:Debug"
        defines { "DEBUG" }
    
    filter "configurations:Release"
       defines { "NDEBUG" }