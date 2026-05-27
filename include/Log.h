#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>

class Log {
    public:
        void push(std::string msg);
        std::string pop();

    private:
        std::vector<std::string> messages;

};

#endif
