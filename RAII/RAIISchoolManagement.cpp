#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <fmt/format.h>

using namespace std;

class FileHandler
{

private:
    ofstream file;
    string filename;

public:
    FileHandler(const string &filename)
        : filename(filename)
    {

        file.open(filename);
        if (!file.is_open())
        {
            throw runtime_error(fmt::format("Failed to open file [{}]", filename));
        }
    }

    ~FileHandler()
    {
        file.close();
        cout << "Closing the file" << endl;
    }
};

int main()
{

    cout << "We are working well with this stuff and that's a good thing" << endl;

    return 0;
}