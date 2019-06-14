#ifndef OS_EXCEPTION_H
#define OS_EXCEPTION_H

#include <cerrno>
#include <cstring>
#include <exception>
#include <string>
#include <sstream>

class OSException : public std::exception {
private:
    std::string error_message;

public:
    OSException() {
        std::stringstream ss;
        ss << "OSError: " << strerror(errno) << " [errno: " << errno << "]";
        error_message = ss.str();
    }

    const char *what() const throw() {
        return error_message.c_str();
    }    
};

#endif