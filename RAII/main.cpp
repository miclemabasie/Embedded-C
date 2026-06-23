#include <iostream>
#include <fstream>
#include <string>
#include <fmt/format.h>

// using namespace std;

class FileHandler
{

private:
    std::ofstream file;
    std::string sFileName;

public:
    explicit FileHandler(const std::string &sFileName)
        : sFileName(sFileName)
    {
        file.open(sFileName);
        if (!file.is_open())
        {
            throw std::runtime_error(fmt::format("Failed to open file [{}].", sFileName));
        }

        fmt::print("File opened: {}.\n", sFileName);
    }

    ~FileHandler()
    {
        if (file.is_open())
        {
            file.close();
            fmt::print("File [{}] was successfully closed \n", sFileName);
        }
    }
};


class Resource{
    public:
        Resource() {fmt::print("Resource Acquired.\n");}
        ~Resource() {fmt::print("Resource Released.\n");}
};

void RAIIFileHandlerTest()
{

    try
    {
        FileHandler fHandler("text.txt");
    }
    catch (const std::exception &ex)
    {
        // fmt::report_error(ex.what());
        std::cout << ex.what() << std::endl;
    }
}


void RAIIUsingUniqueResource(){
    auto pResource = std::make_unique<Resource>();
}

int main(void)
{

    RAIIFileHandlerTest();
    return 0;
}