local outputdir = "$(mode)-$(os)-$(arch)"

target("VoxApp")
    set_kind("binary")

    set_targetdir("../build/" .. outputdir .. "/VoxApp/bin")
    set_objectdir("../build/" .. outputdir .. "/VoxApp/obj")
    
    add_files("Source/**.cpp")
    add_headerfiles("Include/**.hpp", "Include/**.inl")
    add_includedirs("Include/", {public = true})
    add_includedirs("Source/", {private = true})

    add_deps("VoxEngine")