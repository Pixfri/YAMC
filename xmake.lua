set_xmakever("2.9.3")

set_project("VoxEngine")

set_allowedplats("windows", "mingw", "linux")

add_rules("mode.debug", "mode.release")
set_languages("cxx20")
set_optimize("fastest")

if is_mode("debug") then
    add_defines("RT_DEBUG")
    add_defines("TRACY_ENABLE")
end

if is_plat("windows", "mingw") then
    add_defines("VOX_PLATFORM_WINDOWS")
    add_defines("NOMINMAX", "WIN32_LEAN_AND_MEAN")
elseif is_plat("linux") then
    add_defines("VOX_PLATFORM_LINUX")
end

includes("xmake/**.lua") 

add_requires("spdlog v1.9.0", "glfw 3.4", "volk 1.3.290+0", "vulkan-memory-allocator v3.1.0", "vulkan-utility-libraries v1.3.290", "glm 1.0.1", "tracy v0.11.0")
add_requires("imgui v1.91.0", {configs = {glfw = true, vulkan = true, debug = is_mode("debug")}})
             
add_defines("GLFW_INCLUDE_VULKAN", "VK_NO_PROTOTYPES")

local outputdir = "$(mode)-$(os)-$(arch)"

rule("cp-resources")
  after_build(function (target)
    os.cp("Resources", "build/" .. outputdir .. "/" .. target:name() .. "/bin")
  end)

rule("cp-imgui-layout")
  after_build(function(target)
    os.cp("Resources/imgui.ini", "build/" .. outputdir .. "/" .. target:name() .. "/bin")    
  end)

target("VoxEngine")
    set_kind("static")

    set_targetdir("build/" .. outputdir .. "/VoxEngine/bin")
    set_objectdir("build/" .. outputdir .. "/VoxEngine/obj")
    
    add_files("Source/VoxEngine/**.cpp")
    add_includedirs("Include/", {public = true})
    add_headerfiles("Include/VoxEngine/**.hpp", "Include/VoxEngine/**.inl")
    add_includedirs("Source/", {private = true})
    add_headerfiles("Source/VoxEngine/**.hpp", "Source/VoxEngine/**.inl")
    
    if is_plat("windows", "mingw") then
        remove_headerfiles("Include/VoxEngine/Platform/Unix/*.hpp", "Include/VoxEngine/Platform/Unix/*.inl")
        remove_files("Source/VoxEngine/Platform/Unix/*.cpp")
    elseif is_plat("linux") then
        remove_headerfiles("Include/VoxEngine/Platform/Win32/*.hpp", "Include/VoxEngine/Platform/Win32/*.inl")
        remove_files("Source/VoxEngine/Platform/Win32/*.cpp")
    end

    set_pcxxheader("Include/VoxEngine/vxpch.hpp")
    
    add_packages("spdlog", "glfw", "volk", "vk-bootstrap", "vulkan-memory-allocator", "vulkan-utility-libraries", "glm", "imgui", "tracy", {public = true})

includes("VoxApp/xmake.lua")