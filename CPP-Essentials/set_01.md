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

---

### 9. Count Even & Odd in Array

Input array → count how many are even and how many are odd.

---

### 10. Simple Sorting (Bubble or Selection)

Sort an array in ascending order manually (no STL sort).

---

# 🔢 Algebra 1 (30 Problems)

## 🔹 Linear Equations (1–10)

1. Solve: `x + 5 = 12`
2. Solve: `2x = 14`
3. Solve: `x - 7 = 3`
4. Solve: `3x + 4 = 19`
5. Solve: `5x - 10 = 0`
6. Solve: `2x + 3 = x + 9`
7. Solve: `4x - 2 = 2x + 6`
8. Solve: `7x + 1 = 3x + 17`
9. Solve: `6x - 5 = 2x + 11`
10. Solve: `9x + 2 = 5x + 18`

---

## 🔹 Inequalities (11–15)

11. Solve: `x + 4 > 10`
12. Solve: `2x < 8`
13. Solve: `x - 3 ≥ 5`
14. Solve: `3x + 2 ≤ 11`
15. Solve: `5x - 1 > 9`

---

## 🔹 Simplify Expressions (16–20)

16. Simplify: `3x + 5x`
17. Simplify: `7x - 2x + 4`
18. Simplify: `4(x + 3)`
19. Simplify: `2(x + 5) + 3x`
20. Simplify: `5(x - 2) - 3x`

---

## 🔹 Word Problems (21–25)

21. A number plus 8 is 20. Find the number.
22. Twice a number is 18. Find it.
23. A number minus 6 equals 10.
24. 3 times a number plus 4 equals 19.
25. A number divided by 2 is 7.

---

## 🔹 Basic Functions & Graph Thinking (26–30)

26. If `f(x) = x + 3`, find `f(2)`
27. If `f(x) = 2x`, find `f(5)`
28. If `f(x) = x²`, find `f(4)`
29. If `f(x) = x - 1`, find `f(10)`
30. If `f(x) = 3x + 2`, find `f(3)`

---

# ⚡ How to run this like a beast

* 1.5–2 hrs → C++ (write + test everything)
* 1–1.5 hrs → Algebra (no calculator, speed + accuracy)

If you want after this, I can hit you with:

* 🔥 harder C++ (strings, pointers, mini DSA)
* ⚡ exam-style mixed questions
* 🧠 quick cheatsheet before you sleep

Go cook.
