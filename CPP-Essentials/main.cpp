#include <iostream>

using namespace std;

int fib(unsigned int n)
{
    int a = 0;
    int b = 1;
    int nextTerm;
    for (int i = 1; i < n; i++)
    {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    // return fib(n - 1) + fib(n - 2);
    return b;
}

int main(void)
{

    // finding the greatest common divisor
    cout << fib(10) << endl;
    return 0;
}