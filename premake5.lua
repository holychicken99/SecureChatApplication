 workspace " ChatApp"  
configurations { "Debug", "Release" } 

project "ChatApp"  
kind "ConsoleApp"   
language "C++"   

targetdir "build/%{cfg.buildcfg}" 
files { " ./server/**.cpp" } 
includedirs { "./includes/**",  "./asio/include/boost/**"}
buildoptions {"-Wall","-g"}

    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 
    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 