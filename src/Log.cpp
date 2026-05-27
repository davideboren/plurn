#include <Log.h>

#include <string>
#include <vector>

void Log::push(std::string msg){
    messages.push_back(msg);
}

std::string Log::pop(){
    if(messages.size() != 0){
        std::string out_str = messages[0];
        messages.erase(messages.begin());
        return out_str;
    } else {
        return "";
    }
}
