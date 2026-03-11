/*
Problem 1 — RAII File Resource Wrapper
Scenario:
You need a small C++ class that manages a C-style file handle.
The file should automatically close when the object goes out of scope.

Requirements:

    1.Create a class:
        class File

    2.Features:
        open file using fopen
        close file automatically
        write(string)
        readLine()
        prevent resource leaks
        handle failure of fopen
        Constraints

The user of the class should never call fclose manually
File must always close even during exceptions


Approach -1:
choose :
    uique_ptr<FILE*> which is huge bug. --> T become FILE** but we need to manage FILE* using unique_ptr so use unique_ptr<FILE>
*/
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <memory>
#include <ios>
using namespace std;

class File {
private:
    class functor {
    public:
        void operator()(FILE fp) const{
            fclose(fp);
        }
    };

    unique_ptr<FILE*, functor> file;
public:
    enum class Operation {
        READ,
        WRITE,
        APPEND
    };

    File(char* filename , Operation& op) {
        switch(op) {
            case Operation::READ:
                file = std::make_unique<FILE*>(std::fopen(filename , "r"));
                break;
            case Operation::WRITE:
                file = make_unique<FILE*>(std::fopen(filename , "w"));
                break;
            case Operation::APPEND:
                file = make_unique<FILE*>(std::fopen(filename , "a"));
                break;
            default:
                throw invalid_argument("unable to process this arguments\n");
        }
    }

    void write(const string& str) {
        try {
            fwrite(str.c_str() , sizeof(str) , 1 , *file);
        } catch(exception exp) {
            cout <<"File::write  : some exception ocured while writing to this file\n";
            throw exp; 
        }
    }

    void read() {
        try {
            char* str;
            fread(str , 1, 5 , *file);
            cout << "File::read : " << str <<"\n";
        }catch(exception exp) {
            cout <<"File::read  : some exception ocured while reading the file\n";
            throw exp;
        }
    }
};

int main() {
    char* str = "abc.txt";
    File file( str ,File::Operation::WRITE);

    file.write("abcdefghijklmnopqrstuvwxyz\n");
    file.read();
    return 0;
}