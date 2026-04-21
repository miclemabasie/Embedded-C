#include <iostream>

using namespace std;

void countNumbers(int n)
{
    n < 0 ? n *= -1 : n;
    int nextN = 0;
    cout << "counting" << endl;
    while (n != 0)
    {
        nextN += n % 10;
        cout << n % 10;
        n /= 10;
        if (n == 0 && nextN >= 10)
        {
            cout << "=" << nextN << " → ";
            n = nextN;
            nextN = 0;
        }
        else
        {
            cout << ((n == 0) ? "=" : "+");
        }
    }
    cout << nextN << endl;
}

int main(void)
{
    unsigned int n;
    // cout << "Enter a number: ";
    // cin >> n;
    countNumbers(9875);
    return 0;
}