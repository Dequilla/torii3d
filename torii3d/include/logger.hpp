#ifndef __TORII_LOGGER_H__
#define __TORII_LOGGER_H__

#include <iostream>
#include <ostream>
#include <string>
#include <initializer_list>

namespace torii
{
    class Logger
    {
        std::ostream& m_stream;

    public:
        enum class Severity : uint8_t
        {
            TRACE,
            INFO,
            WARNING,
            ERROR,
            CRITICAL
        };
        static std::string severity_to_string(Severity severity);

        Logger();
        Logger(std::ostream& stream);

        // TODO: Remove Logger& log(Severity severity, const std::string& category, const std::string& message);
        Logger& log(std::initializer_list<std::string> params, Severity severity, const std::string& category); 
        
        Logger& trace(std::initializer_list<std::string> params, const std::string& category = "default");
        Logger& info(std::initializer_list<std::string> params, const std::string& category = "default");
        Logger& warning(std::initializer_list<std::string> params, const std::string& category = "default");
        Logger& error(std::initializer_list<std::string> params, const std::string& category = "default");
        Logger& critical(std::initializer_list<std::string> params, const std::string& category = "default");
    };

    extern Logger default_logger_out;
    extern Logger default_logger_err;
    
    inline Logger& trace(std::initializer_list<std::string> params, const std::string& category = "default") 
    {
        return default_logger_out.trace(params, category);
    }

    inline Logger& info(std::initializer_list<std::string> params, const std::string& category = "default")
    {
        return default_logger_out.info(params, category);
    }

    inline Logger& warning(std::initializer_list<std::string> params, const std::string& category = "default")
    {
        return default_logger_out.warning(params, category);
    }

    inline Logger& error(std::initializer_list<std::string> params, const std::string& category = "default")
    {
        return default_logger_err.error(params, category);
    }

    inline Logger& critical(std::initializer_list<std::string> params, const std::string& category = "default")
    {
        return default_logger_err.critical(params, category);
    }
    
}

#endif