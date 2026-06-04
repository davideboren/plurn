#ifndef FEED_H
#define FEED_H

#include <string>
#include <vector>

class Feed {
    public:
        void push(std::string msg);
        std::string pop();

    private:
        std::vector<std::string> messages;
};

#endif
