// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_PLATFORM_ENTRYPOINT_HPP
#define VOX_PLATFORM_ENTRYPOINT_HPP

#include <VoxEngine/vxpch.hpp>
#include <VoxEngine/Platform/Context.hpp>

#if defined(VOX_PLATFORM_WINDOWS)
#include <Windows.h>
#include <VoxEngine/Libs/AntiWindows.hpp>

extern std::unique_ptr<Vox::PlatformContext> CreatePlatformContext(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                                                                   LPSTR lpCmdLine, int nCmdShow);

#define CUSTOM_MAIN(context_name)                                                                     \
    int PlatformMain(const Vox::PlatformContext&);                                                    \
    int APIENTRY WinMain(HINSTANCE hIntance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) { \
        auto context = CreatePlatformContext(hInstance, hPrevInstance, lpCmdLine, nCmdShov);          \
        return PlatformMain(*context);                                                                \
    }                                                                                                 \
    int PlatformMain(const Vox::PlatformContext& (context_name))

#elif defined(VOX_PLATFORM_LINUX)
extern std::unique_ptr<Vox::PlatformContext> CreatePlatformContext(int argc, char** argv);

#define CUSTOM_MAIN(context_name)                     \
    int PlatformMain(const Vox::PlatformContext&);    \
    int main(int argc, char* argv[]) {                \
    auto context = CreatePlatformContext(argc, argv); \
    return PlatformMain(*context);                    \
    }                                                 \
    int PlatformMain(const Vox::PlatformContext& (context_name))

#else
#include <stdexcept>

#define CUSTOM_MAIN(context_name)                            \
    int main(int argc, char* argv[]) {                       \
        throw std::runtime_error("Platform not supported."); \
    }                                                        \
    int unused(const Vox::PlatformContext& (context_name))
#endif

#endif // VOX_PLATFORM_ENTRYPOINT_HPP
