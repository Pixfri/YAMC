// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in Export.hpp

#include <VoxEngine/Platform/Unix/Context.hpp>

namespace Vox {
    UnixPlatformContext::UnixPlatformContext(Int32 argc, char** argv) : PlatformContext{} {
        m_Arguments.reserve(argc);
        for (Int32 i = 1; i < argc; ++i) {
            m_Arguments.emplace_back(argv[i]);
        }

        const char* envTempDir = std::getenv("TMPDIR");
        m_TempDirectory = envTempDir ? std::string(envTempDir) + "/" : "/tmp/";
        m_ExternalStorageDirectory = "";
    }

}
