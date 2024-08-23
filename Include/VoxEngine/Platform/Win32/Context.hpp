// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_PLATFORM_WIN32_CONTEXT_HPP
#define VOX_PLATFORM_WIN32_CONTEXT_HPP

#include <VoxEngine/vxpch.hpp>

#include <VoxEngine/Platform/Context.hpp>

#include <Windows.h>
#include <VoxEngine/Libs/AntiWindows.hpp>

namespace Vox {
    /**
     * @brief Windows platform context.
     *
     * @warning Use in extreme circumstances with code guarded by the VOX_PLATFORM_WINDOWS define
     */
    class WindowsPlatformContext final : public PlatformContext {
    public:
        WindowsPlatformContext(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPCTSTR lpCmdLine, int nCmdShow);
        ~WindowsPlatformContext() override = default;

        WindowsPlatformContext(const WindowsPlatformContext&) = delete;
        WindowsPlatformContext(WindowsPlatformContext&&) = delete;

        WindowsPlatformContext& operator=(const WindowsPlatformContext&) = delete;
        WindowsPlatformContext& operator=(WindowsPlatformContext&&) = delete;
    private:
    };
}

#endif // VOX_PLATFORM_WIN32_CONTEXT_HPP
