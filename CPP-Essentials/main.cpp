#include <iostream>

using namespace std;

int main(void)
{

    int n;
    int rev = 0;
    int lastDigit;
    cout << "Enter a number: ";
    cin >> n;

    while (n != 0)
    {
        // get the last number from n
        lastDigit = n % 10;
        // get current reverse increase by 10 and add the last digit
        rev = rev * 10 + lastDigit;
        n = n / 10;
    };

    cout << "The Reverse of " << n << "is: " << rev << endl;

    return 0;
}