#include <iostream>
using namespace std;

int factorialFor(int n)
{
    /*
        f(1) = 1
        f(2) = 1 * 2 = 2
        f(3) = 1 * 2 * 3 = 6
        f(4) = 1 * 2 * 3 * 4 = 24
    */
    int res = 1;
    for(int i=1; i<=n; i++)
    {
        res *= i;
    }
    return res;
}

int factorial(int n)
{
    /*
        f(1) = 1
        f(2) = 1 * 2 = 2 -> f(1) * 2
        f(3) = 1 * 2 * 3 = 6 -> f(2) * 3
        f(4) = 1 * 2 * 3 * 4 = 24 -> f(3) * 4
    */
    if(n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;
}

int fibonacci(int n)
{
    /*
        1 1 2 3 5 8
        f(0) = 0
        f(1) = 1
        f(2) = 1 -> f(0) + f(1)
        f(3) = 1 + 1 = 2 -> f(1) + f(2)
        f(4) = 1 + 2 = 3 -> f(2) + f(3)
        f(5) = 2 + 3 = 5 -> f(3) + f(4)
    */
   if(n == 0 || n == 1)
        return n;

   return fibonacci(n - 1) + fibonacci(n - 2);
}