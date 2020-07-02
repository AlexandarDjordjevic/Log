#include "Log.hpp"
#include <unistd.h>


void Log::warning(std::string message){
    std::string newMessage = "\x1B[32mWarning: " + message + "\x1B[0m\r\n";
    write(0, newMessage.c_str(), newMessage.length());
}

void Log::error(std::string message){
    std::string newMessage = "\x1B[31mError: " + message + "\x1B[0m\r\n";;
    write(0, newMessage.c_str(), newMessage.length());
}

void Log::info(std::string message){
    std::string newMessage = "\x1B[33mInfo: " + message + "\x1B[0m\r\n";;
    write(0, newMessage.c_str(), newMessage.length());
}