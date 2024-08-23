// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_PLATFORM_UNIX_CONTEXT_HPP
#define VOX_PLATFORM_UNIX_CONTEXT_HPP

#include <VoxEngine/vxpch.hpp>

#include <VoxEngine/Platform/Context.hpp>

namespace Vox {
    class UnixPlatformContext final : public PlatformContext {
    public:
        UnixPlatformContext(Int32 argc, char** argv);
        ~UnixPlatformContext() override = default;

        UnixPlatformContext(const UnixPlatformContext&) = delete;
        UnixPlatformContext(UnixPlatformContext&&) = delete;

        UnixPlatformContext& operator=(const UnixPlatformContext&) = delete;
        UnixPlatformContext& operator=(UnixPlatformContext&&) = delete;
    };
}

#endif // VOX_PLATFORM_UNIX_CONTEXT_HPP
