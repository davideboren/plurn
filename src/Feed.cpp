#include <Feed.h>

#include <string>
#include <vector>

void Feed::push(std::string msg){
    messages.push_back(msg);
}

std::string Feed::pop(){
    if(messages.size() != 0){
        std::string out_str = messages[0];
        messages.erase(messages.begin());
        return out_str;
    } else {
        return "";
    }
}
