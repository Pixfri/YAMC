// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in Export.hpp

#include <VoxEngine/Platform/Win32/Context.hpp>
#include <VoxEngine/Utils/Logger.hpp>

#include <shellapi.h>

namespace Vox {
    inline std::string GetTempPathFromEnvironment() {
        std::string tempPath = "temp/";

        TCHAR tempBuffer[MAX_PATH];
        if (const DWORD tempPathRet = GetTempPath(MAX_PATH, tempBuffer);
            tempPathRet < MAX_PATH && tempPathRet != 0) {
            tempPath = std::string(tempBuffer) + "/";
        }

        return tempPath;
    }


    /**
     * @brief Converts wstring to string using Windows specific function. 
     * @param wStr Wide string to convert. 
     * @return A converted utf-8 string.
     */
    inline std::string WStrToStr(const std::wstring& wStr) {
        if (wStr.empty()) {
            return {};
        }

        const auto wStrLen = static_cast<Int32>(wStr.length());
        const auto strLen = WideCharToMultiByte(CP_UTF8, 0, wStr.data(), wStrLen, nullptr, 0, nullptr, nullptr);

        std::string str(strLen, 0);
        WideCharToMultiByte(CP_UTF8, 0, wStr.data(), wStrLen, str.data(), strLen, nullptr, nullptr);

        return str;
    }

    inline std::vector<std::string> GetArgs() {
        Int32 argc;
        LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

        // Ignoring the first argument containing the application full path.
        const std::vector<std::wstring> argStrings(argv + 1, argv + argc);
        std::vector<std::string> args;

        args.reserve(argStrings.size());
        for (auto& arg : argStrings) {
            args.push_back(WStrToStr(arg));
        }

        return args;
    }

    WindowsPlatformContext::WindowsPlatformContext(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPCTSTR lpCmdLine,
                                                   int nCmdShow) : PlatformContext{} {
        m_ExternalStorageDirectory = "";
        m_TempDirectory = GetTempPathFromEnvironment();
        m_Arguments = GetArgs();

        // Attempt to attach to the parent process console if it exists.
        if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
            // No parent console allocate a new one for this process
            if (!AllocConsole()) {
                Log::Fatal({0x04, 0x00}, "AllocConsole error.");
            }
        }

        FILE* fp;
        if (!(freopen_s(&fp, "conin$", "r", stdin))   ||
            !(freopen_s(&fp, "conout$", "w", stdout)) ||
            !(freopen_s(&fp, "conout$", "w", stderr))) {
            Log::Fatal({0x04, 0x01}, "Failed to open console streams.");
        }
    }

}
