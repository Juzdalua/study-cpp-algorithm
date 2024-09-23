#include <bits/stdc++.h>
using namespace std;

/*
    5 <= n <= 40
    코드1 실행 횟수, 코드 2 실행 횟수 출력
*/

int N;
int result1, result2;
int f[44];

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        // 코드1
        result1++;
        return 1;
    }
    else
        return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        // 코드 2
        result2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main()
{
    cin >> N;
    fib(N);
    fibonacci(N);
    cout << result1 << " " << result2 << '\n';

    return 0;
}