#include <iostream>
#include <fstream>
#include <string>

// using namespace std;

class Human
{

private:
    std::string name;
    int age;

public:
    explicit Human(const std::string &name)
        : name(name), age(-1)
    {
    }

    Human(int age)
        : name("None"), age(age)
    {
    }
};

class FileHandler
{

public:
private:
};

int main()
{
    // Human a(10);
    // Human a = 10; // compiler will type cast 10 to the Human class using the constructure (implicit conversion) (does not work with explicit)
    // Human b("Miclem");
    // Human b = "Hummingbird"; // This does not work because the compiler hase to convert from char pointer to string and then to Human class, but the compiler is only allowed to convert once when doing an implicite conversion
    // to fix this we must declare this as a string upfront to avoid double conversion
    // Human b = std::string("Hummingbird"); // the compiler only has to typecast now from string to Human Class (does not work with explicit)

    /*

        ClassName obj = value; using this way to create objects will always lead to implicit conversions by the compiler where possible, to avoid this
        we need to use the explicit keyword in the constructor class which forces the programmer to use the format className obj(values....);

        when we have a constructor with one keyword, then using explicit keyword is always the best idea
    */

    return 0;
}