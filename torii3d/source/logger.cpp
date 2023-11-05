#include "logger.hpp"

namespace torii
{
    std::string Logger::severity_to_string(Severity severity)
    {
        switch (severity)
        {
        case Severity::TRACE:
            return "TRACE"; 
        case Severity::INFO:
            return "INFO";
        case Severity::WARNING:
            return "WARNING";
        case Severity::ERROR:
            return "ERROR";
        case Severity::CRITICAL:
            return "CRITICAL";
        default:
            return "INFO";
        };
    }

    Logger::Logger()
        : m_stream(std::cout)
    {
    }

    Logger::Logger(std::ostream& stream)
        : m_stream(stream)
    {
    }

    Logger& Logger::log(std::initializer_list<std::string> params, Severity severity, const std::string& category)
    {
        m_stream << "[" << severity_to_string(severity) << "][" << category << "] ";
        for(auto& rParam : params)
        {
            m_stream << rParam;
        }
        m_stream << std::endl;
        return *this;
    }

    Logger& Logger::trace(std::initializer_list<std::string> params, const std::string& category)
    {
        return log(params, Severity::TRACE, category);
    }

    Logger& Logger::info(std::initializer_list<std::string> params, const std::string& category)
    {
        return log(params, Severity::INFO, category);
    }

    Logger& Logger::warning(std::initializer_list<std::string> params, const std::string& category)
    {
        return log(params, Severity::WARNING, category);
    }

    Logger& Logger::error(std::initializer_list<std::string> params, const std::string& category)
    {
        return log(params, Severity::ERROR, category);
    }

    Logger& Logger::critical(std::initializer_list<std::string> params, const std::string& category)
    {
        return log(params, Severity::CRITICAL, category);
    }
    
    Logger default_logger_out(std::cout);
    Logger default_logger_err(std::cerr); 
}