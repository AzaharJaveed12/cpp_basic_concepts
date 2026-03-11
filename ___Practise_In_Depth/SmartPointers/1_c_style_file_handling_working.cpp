#include <cstdio>       // fopen, fclose, fwrite, fgets
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

class File {
private:
    /*
        Earlier mistake:
        ----------------
        You wrote:

            unique_ptr<FILE*, functor> file;

        This is wrong because FILE* is already a pointer type.
        unique_ptr<FILE*> means you are trying to manage a pointer-variable
        (conceptually FILE**) instead of managing the actual FILE resource.

        Correct idea:
        -------------
        We want to directly manage the FILE* returned by fopen().
        So the smart pointer should own FILE, not FILE*.
    */

    struct FileCloser {
        void operator()(FILE* fp) const {
            /*
                Earlier mistake:
                ----------------
                fclose(fp) was called without checking fp.

                If fopen fails, fp can be nullptr.
                Calling fclose(nullptr) is invalid.

                Fix:
                ----
                Check for nullptr before calling fclose.
            */
            if (fp != nullptr) {
                std::fclose(fp);
            }
        }
    };

    // Correct ownership: manage FILE* directly with custom deleter
    std::unique_ptr<FILE, FileCloser> file_;

public:
    enum class Operation {
        READ,
        WRITE,
        APPEND
    };

    /*
        Earlier mistakes:
        -----------------
        1. File(char* filename, Operation& op)
           - filename should not be mutable char*
           - enum should not be passed by non-const reference

        Fix:
        ----
        Use:
            const char* filename
            Operation op

        Since Operation is small, pass by value.
    */
    File(const char* filename, Operation op) {
        const char* mode = nullptr;

        switch (op) {
            case Operation::READ:
                mode = "r";
                break;
            case Operation::WRITE:
                mode = "w";
                break;
            case Operation::APPEND:
                mode = "a";
                break;
            default:
                throw std::invalid_argument("Invalid file operation");
        }

        /*
            Earlier mistake:
            ----------------
            You used make_unique<FILE*>(fopen(...))

            That dynamically allocates a pointer variable, which is not what we want.

            Fix:
            ----
            Directly initialize/reset unique_ptr with the FILE* returned by fopen().
        */
        file_.reset(std::fopen(filename, mode));

        /*
            Earlier mistake:
            ----------------
            fopen failure was not handled.

            Fix:
            ----
            If fopen returns nullptr, throw immediately.
        */
        if (!file_) {
            throw std::runtime_error("Failed to open file");
        }
    }

    /*
        Good API design:
        ----------------
        The wrapper manages the resource. User should never manually close it.
        Destructor is automatically handled by unique_ptr + custom deleter.
    */

    /*
        Optional but good practice:
        ---------------------------
        Copy should be disabled because file ownership is exclusive.
    */
    File(const File&) = delete;
    File& operator=(const File&) = delete;

    /*
        Move can be allowed.
        unique_ptr already supports move safely.
    */
    File(File&&) noexcept = default;
    File& operator=(File&&) noexcept = default;

    void write(const std::string& str) {
        /*
            Earlier mistake:
            ----------------
            You wrote:

                fwrite(str.c_str(), sizeof(str), 1, *file);

            sizeof(str) gives the size of std::string object type,
            NOT the number of characters in the string.

            Fix:
            ----
            Use str.size() for actual byte count.
        */
        if (!file_) {
            throw std::runtime_error("File is not open");
        }

        size_t written = std::fwrite(str.c_str(), 1, str.size(), file_.get());

        /*
            Earlier mistake:
            ----------------
            You used try-catch around fwrite.
            But fwrite does NOT throw C++ exceptions.
            It reports errors using return values.

            Fix:
            ----
            Check return value.
        */
        if (written != str.size()) {
            throw std::runtime_error("Failed to write complete data to file");
        }
    }

    std::string readLine() {
        /*
            Earlier mistakes:
            -----------------
            1. You implemented read(), but requirement asked for readLine()
            2. You used an uninitialized char*:
                   char* str;
                   fread(str, ...)
               This is undefined behavior.
            3. fread data was not null-terminated before printing.

            Fix:
            ----
            Use a proper buffer and fgets(), because fgets() is line-oriented
            and directly matches the readLine() requirement.
        */
        if (!file_) {
            throw std::runtime_error("File is not open");
        }

        char buffer[1024];

        if (std::fgets(buffer, sizeof(buffer), file_.get()) == nullptr) {
            /*
                fgets returns nullptr on EOF or error.
                For simplicity, throw if no line can be read.
            */
            throw std::runtime_error("Failed to read line or reached EOF");
        }

        return std::string(buffer);
    }

    /*
        Helpful utility:
        ----------------
        If file is opened in write mode and later you want to read from it,
        you generally need repositioning/reopen depending on mode.

        This helper lets you move to the beginning of file when appropriate.
    */
    void rewindFile() {
        if (!file_) {
            throw std::runtime_error("File is not open");
        }
        std::rewind(file_.get());
    }
};

int main() {
    try {
        /*
            Earlier mistake:
            ----------------
            You wrote:
                char* str = "abc.txt";

            String literal should not go to mutable char*.
            Correct:
                const char* filename = "abc.txt";
        */
        const char* filename = "abc.txt";

        {
            /*
                Open in WRITE mode and write data.
                Note:
                -----
                A file opened with "w" is write-only.
                You cannot correctly read from it in that same mode.
            */
            File file(filename, File::Operation::WRITE);
            file.write("abcdefghijklmnopqrstuvwxyz\n");
            file.write("second line\n");
        } // file closes automatically here

        {
            /*
                Reopen in READ mode to read lines.
                This is the correct way to test reading after writing.
            */
            File file(filename, File::Operation::READ);

            std::cout << "Line 1: " << file.readLine();
            std::cout << "Line 2: " << file.readLine();
        } // closes automatically here
    }
    catch (const std::exception& ex) {
        /*
            Earlier mistake:
            ----------------
            Exceptions were caught by value in your code:
                catch(exception exp)

            Fix:
            ----
            Catch by const reference to avoid slicing and unnecessary copy.
        */
        std::cerr << "Error: " << ex.what() << '\n';
    }

    return 0;
}