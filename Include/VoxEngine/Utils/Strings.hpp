// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_UTILS_STRINGS_HPP
#define VOX_UTILS_STRINGS_HPP

#include <VoxEngine/vxpch.hpp>

namespace Vox {
    /**
     * @brief Replaces all occurrences of a substring with another substring.
     */
    inline std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);

    /**
     * @brief Removes all occurrences of a set of characters from the end of a string.
     */
    inline std::string TrimRight(const std::string& str, const std::string& chars = "\t\n\v\f\r\b ");

    /**
     * @brief Removes all occurrences of a set of characters from the beginning of a string.
     */
    inline std::string TrimLeft(const std::string& str, const std::string& chars = "\t\n\v\f\r\b ");
}

#include <VoxEngine/Utils/Strings.inl>

#endif // VOX_UTILS_STRINGS_HPP
