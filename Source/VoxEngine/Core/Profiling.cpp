// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in Export.hpp

#include <VoxEngine/Core/Profiling.hpp>

#include <cstdlib>

#ifdef TRACY_ENABLE
void* operator new(size_t count) {
    const auto ptr = malloc(count);
    TracyAlloc(ptr, count);
    return ptr;
}

void operator delete(void* ptr) {
    TracyFree(ptr);
    free(ptr);
}
#endif // TRACY_ENABLE