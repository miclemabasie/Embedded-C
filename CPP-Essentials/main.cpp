#include <iostream>

using namespace std;

int countDigit(int n)
{

    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    };
    return count;
}

int reverseANumber(int n)
{
    int rev = 0;
    int lastDigit;

    while (n != 0)
    {
        // get the last number from n
        lastDigit = n % 10;
        // get current reverse increase by 10 and add the last digit
        rev = rev * 10 + lastDigit;
        n = n / 10;
    };

    // cout << "The Reverse of " << n << "is: " << rev << endl;

    return rev;
}

int main(void)
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // cout << ((reverseANumber(n) == n) ? "Yes" : "No") << endl;

    cout << "Total digits are: " << countDigit(n) << endl;

    return 0;
}