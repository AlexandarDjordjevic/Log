#pragma once

#include <string>

class Log{
    public:
        Log();
        static void warning(std::string);
        static void error(std::string);
        static void info(std::string);
};