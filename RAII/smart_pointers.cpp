#include <iostream>
#include <memory>

using namespace std;

int main(void)
{

    unique_ptr<int> unPtr1 = make_unique<int>(25);
    // cout << *unPtr1 << endl; // Dereferencing the pointer
    
    return 0;
}