#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>


namespace Log{
    class Error : public std::stringstream{
        template <class T> 
        friend std::stringstream& operator<<(Error& error, T const& value);
        friend void flush(Error& error);
        std::stringstream msg_stream;
    };

    template <class T>   
    std::stringstream& operator<<(Error& error, T const& value){
        error.msg_stream << value;
        return error.msg_stream;
    }

    void flush(Error& error) 
    {
        if (error.msg_stream.str().size() > 0 ){
            std::string newMessage = "\x1B[31mError: " + error.msg_stream.str() + "\x1B[0m\r\n";
            write(0, newMessage.c_str(), newMessage.length());
            std::stringstream().swap(error.msg_stream);
        }
    }
 
    class Warning : public std::stringstream{
        template <class T> 
        friend std::stringstream& operator<<(Warning& warning, T const& value);
        friend void flush(Warning& warning);
        std::stringstream msg_stream;
    };

    template <class T>   
    std::stringstream& operator<<(Warning& warning, T const& value){
        warning.msg_stream << value;
        return warning.msg_stream;
    }

    void flush(Warning& warning) 
    {
        if (warning.msg_stream.str().size() > 0 ){
            std::string newMessage = "\x1B[33mWarning: " + warning.msg_stream.str() + "\x1B[0m\r\n";
            write(0, newMessage.c_str(), newMessage.length());
            std::stringstream().swap(warning.msg_stream);
        }
    }

    class Info : public std::stringstream{
        template <class T> 
        friend std::stringstream& operator<<(Info& info, T const& value);
        friend void flush(Info& info);
        std::stringstream msg_stream;
    };

    template <class T>   
    std::stringstream& operator<<(Info& info, T const& value){
        info.msg_stream << value;
        return info.msg_stream;
    }

    void flush(Info& info) 
    {
        if (info.msg_stream.str().size() > 0 ){
            std::string newMessage = "\x1B[32mInfo: " + info.msg_stream.str() + "\x1B[0m\r\n";
            write(0, newMessage.c_str(), newMessage.length());
            std::stringstream().swap(info.msg_stream);
        }     
    }

    Log::Error error;
    Log::Warning warning;
    Log::Info info;
    #define endl "";\
                Log::flush(Log::error);\
                Log::flush(Log::info);\
                Log::flush(Log::warning);
}
