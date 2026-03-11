#include <iostream>
#include <stdio.h>
#include <memory>
#include <stdexcept>


namespace Logger {
    class Logger {
        class FileClouser {
        public:
            void operator()(FILE* fp) const {
                if(fp != nullptr) {
                    fclose(fp);
                }
            }
        };
    private:
        std::unique_ptr<FILE , FileClouser> uptr_file;
    public:
        /*
            external things should not say where we shuld log. Logger should decide it as per good design
        */
        Logger() {
            uptr_file.reset(fopen("logger.txt","a"));

            if(uptr_file == nullptr) {
                throw std::runtime_error("not able to open file\n");
            }
        }

        // deleting copy constructor as file is unique_ptr that means non-copyiable
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        // move constructor allow as unique_Ptr allows move operation.
        Logger(Logger&& logger) = default;
        Logger& operator=(Logger&& logger) = default;
    
        bool logInfo(const std::string& str) {
            if(uptr_file == nullptr)
                return false;
            fwrite("INFO : " , 1 , 7 , uptr_file.get());
            std::size_t written = fwrite(str.c_str() , 1 , str.length() , uptr_file.get());

            fflush(uptr_file.get());
            fputc('\n',uptr_file.get());
            return written == str.size();
        }

        bool logError(const std::string& str) {
            if(uptr_file == nullptr)
                return false;

            fwrite("ERROR : " , 1 , 8 , uptr_file.get());
            std::size_t written = fwrite(str.c_str() , 1 , str.length() , uptr_file.get());

            fflush(uptr_file.get());
            fputc('\n',uptr_file.get());
            return written == str.size();

        }
    };
}

int main() {
    try {
        Logger::Logger logger;
        logger.logInfo("Assalamu-alikum javeed bhai");
        logger.logError("walikum-assalam bhai");
    } catch(const std::exception& ex) {
        std::cerr<<ex.what() <<"\n";
    }
    return 0;
}