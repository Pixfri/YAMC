// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_CORE_STDFILESYSTEM_HPP
#define VOX_CORE_STDFILESYSTEM_HPP

#include <VoxEngine/vxpch.hpp>

namespace Vox {
    class StdFilesystem {
    public:
        StdFilesystem() = default;
        ~StdFilesystem() = default;

        StdFilesystem(const StdFilesystem&) = delete;
        StdFilesystem(StdFilesystem&&) = delete;

        StdFilesystem& operator=(const StdFilesystem&) = delete;
        StdFilesystem& operator=(StdFilesystem&&) = delete;

    private:
    };
}

#include <VoxEngine/Core/StdFilesystem.inl>

#endif // YAMC_CORE_STDFILESYSTEM_HPP
