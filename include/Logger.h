#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

class Logger {

    public:

        static void init(const string& filename){
            log_file.open(filename, ios::app);
            if(!log_file.is_open()){
                //cerr << "Error opening log file." << endl;
            }
        }

        static void log(const string& msg){
            time_t now = time(0);
            tm* timeinfo = localtime(&now);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp),
                "%Y-%m-%d %H:%M:%S", timeinfo);

            ostringstream entry;
            entry << "[" << timestamp << "]: " << msg << endl;

            //cout << entry.str();

            if(log_file.is_open()){
                log_file << entry.str();
                log_file.flush();
            }
        }

        static void shutdown(){
            log_file.close();
        }

    private:
        inline static ofstream log_file;

};

#endif
