// No include guard
// ReSharper disable CppMissingIncludeGuard

// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef _WINDOWS_
#error This header should only be included after including Windows.h directly or indirectly in a .cpp
#endif

#undef CreateWindow
#undef GetEnvironmentVariable
#undef MemoryBarrier
#undef RemoveDirectory
#undef CreateDirectory

// ReSharper enable CppMissingIncludeGuard