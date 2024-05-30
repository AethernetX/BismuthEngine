#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace bi {
    class BISMUTH_API Log
    {
    private:
    
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
    };

    // Core log macros
    #define BI_CORE_TRACE(...)    ::bi::Log::getCoreLogger()->trace(__VA_ARGS__)
    #define BI_CORE_INFO(...)     ::bi::Log::getCoreLogger()->info(__VA_ARGS__)
    #define BI_CORE_WARN(...)     ::bi::Log::getCoreLogger()->warn(__VA_ARGS__)
    #define BI_CORE_ERROR(...)    ::bi::Log::getCoreLogger()->error(__VA_ARGS__)
    #define BI_CORE_FATAL(...)    ::bi::Log::getCoreLogger()->fatal(__VA_ARGS__)

    // ClienBIlog macros
    #define BI_TRACE(...)	      ::bi::Log::getClientLogger()->trace(__VA_ARGS__)
    #define BI_INFO(...)	      ::bi::Log::getClientLogger()->info(__VA_ARGS__)
    #define BI_WARN(...)	      ::bi::Log::getClientLogger()->warn(__VA_ARGS__)
    #define BI_ERROR(...)	      ::bi::Log::getClientLogger()->error(__VA_ARGS__)
    #define BI_FATAL(...)	      ::bi::Log::getClientLogger()->fatal(__VA_ARGS__)

} // namespace bi