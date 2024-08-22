// Copyright (C) 2024 Jean "Pixfri" Letessier 
// This file is part of Vox Engine.
// For conditions of distribution and use, see copyright notice in LICENSE

#include <VoxEngine/Utils/Logger.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/base_sink.h>

namespace Vox {
    std::shared_ptr<spdlog::logger> Logger::m_Logger;

    void Logger::Init() {
        spdlog::set_pattern("%^[%T](%l) %n : %v%$");

        m_Logger = spdlog::stdout_color_mt("VoxEngine");
        m_Logger->set_level(spdlog::level::trace);
    }

    template <typename Mutex>
    class CallbackSink final : public spdlog::sinks::base_sink<Mutex> {
        customLogCallback m_Callback;
        spdlog::pattern_formatter m_Formatter;

    public:
        explicit CallbackSink(customLogCallback callback) : m_Callback{std::move(callback)} {
        }

    protected:
        void sink_it_(const spdlog::details::log_msg& msg) override {
            spdlog::memory_buf_t formatted;
            m_Formatter.format(msg, formatted);
            const auto eolLen = strlen(spdlog::details::os::default_eol);
            const std::string message(formatted.begin(), formatted.end() - eolLen);
            m_Callback(msg.level, message + '\n');
        }

        void flush_() override {
        }
    };

    void Logger::AddCallback(const customLogCallback& callback) {
        m_Logger->sinks().push_back(std::make_shared<CallbackSink<std::mutex>>(callback));
    }

    namespace Log {
        std::string EvaluateErrorCode(const ErrorCode& errorCode) {
            std::stringstream message;
            switch (errorCode.ModuleId) {
            case 0x00:
                message << "[APPLICATION INITIALIZATION]";
                break;
                
            case 0x01:
                message << "[CORE]";
                break;
                
            case 0x02:
                message << "[RENDERER] ";
                break;

            case 0x03:
                message << "[FILESYSTEM] ";

            default:
                message << "[INVALID/UNKNOWN MODULE ID]";
                break;
            }

            return message.str();
        }
    }
}
