#ifndef FEED_H
#define FEED_H

#include <string>
#include <vector>

class Feed {
    public:
        void push(std::string msg);

        void append_buffer(std::string msg);
        void push_buffer();

        std::string pop();

    private:
        std::string buffer;
        std::vector<std::string> messages;
};

#endif
