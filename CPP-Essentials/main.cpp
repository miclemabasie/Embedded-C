#include <iostream>

using namespace std;

int isPrime(int n)
{
    // return 0 if false and 1 if true
    int isPrime = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = 1;
            break;
        };
    }
    return isPrime;
}

int main(void)
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << ((isPrime(n) == 0) ? "Number is not prime" : "Number is Prime") << endl;
    return 0;
}