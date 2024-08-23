// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#ifndef VOX_CORE_ERRORS_HPP
#define VOX_CORE_ERRORS_HPP

#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
#define __GCC__ __GNUC__
#endif

#if defined(__clang__)
#define VOX_DISABLE_WARNINGS()                                                             \
    _Pragma("clang diagnostic push")                                                       \
        _Pragma("clang diagnostic ignored \"-Wall\"")                                      \
                _Pragma("clang diagnostic ignored \"-Wextra\"")                            \
                    _Pragma("clang diagnostic ignored \"-Wtautological-compare\"")         \
                        _Pragma("clang diagnostic ignored \"-Wnullability-completeness\"")
#define VOX_ENABLE_WARNINGS() \
    _Pragma("clang diagnostic pop")
#elif defined(__GNUC__) || defined(__GNUG__)
#define VOX_DISABLE_WARNINGS()                                               \
    _Pragma("GCC diagnostic push")                                           \
        _Pragma("GCC diagnostic ignored \"-Wall\"")                          \
            _Pragma("GCC diagnostic ignored \"-Wextra\"")                    \
                _Pragma("GCC diagnostic ignored \"-Wtautological-compare\"")

#define VOX_ENABLE_WARNINGS()     \
    _Pragma("GCC diagnostic pop")
#elif defined(_MSC_VER)
// MSVC ENABLE/DISABLE WARNING DEFINITION
#define VOX_DISABLE_WARNINGS() \
    __pragma(warning(push, 0))

#define VOX_ENABLE_WARNINGS() \
    __pragma(warning(pop))
#endif

#endif // VOX_CORE_ERRORS_HPP
