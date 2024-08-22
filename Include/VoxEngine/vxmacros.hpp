// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#define VOX_PREFIX(a, prefix) prefix ## a
#define VOX_PREFIX_MACRO(a, prefix) VOX_PREFIX(a, prefix)
#define VOX_SUFFIX(a, suffix) a ## suffix
#define VOX_SUFFIX_MACRO(a, suffix) VOX_SUFFIX(a, suffix)
#define VOX_STRINGIFY(s) #s
#define VOX_STRINGIFY_MACRO(s) VOX_STRINGIFY(s)
#define VOX_UNUSED(a) (void) a