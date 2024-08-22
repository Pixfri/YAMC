// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#include <functional>

namespace Vox {
    inline void HashCombine(USize &seed, USize hash) {
        hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash;
    }
    
    template <class T>
    void HashCombine(USize &seed, const T& v) {
        std::hash<T> hasher;

        HashCombine(seed, hasher(v));
    }
}
