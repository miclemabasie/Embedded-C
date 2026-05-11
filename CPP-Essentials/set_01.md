Alright, we’re loading your brain like a well-packed toolbox 🧠🔧. No fluff, just clean reps.

---

# 💻 C++ Practice (10 solid problems, ~3 hours total)

### 1. Reverse an Integer

Take an integer input and reverse its digits.
Example: `1234 → 4321`, `-560 → -65`
```C
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
```

---

### 2. Palindrome Number

Check if a number reads the same forward and backward.
Example: `121 → true`, `123 → false`
```c
#include <iostream>

using namespace std;

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

    cout << ((reverseANumber(n) == n) ? "Yes" : "No") << endl;

    return 0;
}
```
---

### 3. Count Digits

Given an integer, count how many digits it has (ignore sign).
```c
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
```
---

### 4. Sum of Digits Until Single Digit

Keep summing digits until one digit remains.
Example: `9875 → 9+8+7+5=29 → 2+9=11 → 1+1=2`
```c
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
```
---

### 5. Prime Number Check

Check if a number is prime efficiently (not brute force to n).
```c
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
```
---

### 6. Find GCD (Greatest Common Divisor)

Input two numbers, output their GCD.
Use Euclidean algorithm.

```c
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    // a has to be greater than b, so we make sure of that
    if (a < b)
    {
        int temp = a;
        b = a;
        a = temp;
    }

    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main(void)
{

    // finding the greatest common divisor

    int x = 9;
    int y = 6;

    cout << gcd(781, 484) << endl;

    return 0;
}
```

---

### 7. Fibonacci (Iterative)

Print first `n` Fibonacci numbers using loop (not recursion).
```c
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
```

---

### 8. Array Max & Min

Take `n` numbers and find both max and min.
```c
#include <iostream>

using namespace std;

int main(void)
{
    int arrSize = 15;
    int arr[15] = {42, 7, 89, 23, 1, 56, 94, 12, 67, 3, 45, 78, 9, 31, 50};

    int min = arr[0];
    int max = arr[arrSize - 1];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    cout << "max is: " << max << " and min is: " << min << endl;

    return 0;
}
```
---

### 9. Count Even & Odd in Array

Input array → count how many are even and how many are odd.
```c
#include <iostream>

using namespace std;

int main(void)
{
    int arrSize = 15;
    int arr[15] = {42, 7, 89, 23, 1, 56, 94, 12, 67, 3, 45, 78, 9, 31, 50};

    int evens = 0;
    int odds = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0) // even case
            evens++;
        else // odds
            odds++;
    }

    cout << "odds are: " << odds << " and evens are: " << evens << endl;

    return 0;
}
```

---

### 10. Simple Sorting (Bubble or Selection)

Sort an array in ascending order manually (no STL sort).
```c
// Using Bubble sort
#include <iostream>

using namespace std;

void swap(int a, int b)
{
    return;
}

int main(void)
{

    int arrSize = 15;
    int arr[15] = {42, 7, 89, 23, 1, 56, 94, 12, 67, 3, 45, 78, 9, 31, 50};
    int temp;

    for (int i = 0; i < arrSize; i++)
    {
        // compare every element to its neighbor
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "[ ";

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " ]" << endl;

    return 0;
}
```

---

