// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_UTILS_HASH_HPP
#define VOX_UTILS_HASH_HPP

#include <VoxEngine/vxpch.hpp>

namespace Vox {
    inline void HashCombine(USize &seed, USize hash);

    /**
     * @brief Helper function to combine a given hash
     *        with a generated hash for the input param.
     */
    template <class T>
    void HashCombine(USize &seed, const T& v);
}

#include <VoxEngine/Utils/Hash.inl>

#endif // VOX_UTILS_HASH_HPP
