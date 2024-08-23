// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in Export.hpp

#include <VoxEngine/Platform/Unix/Context.hpp>

#include <VoxEngine/Platform/EntryPoint.hpp>

namespace Vox {
    std::unique_ptr<PlatformContext> CreatePlatformContext(int argc, char** argv) {
        return std::make_unique<UnixPlatformContext>(argc, argv);
    }
}
