#include <bits/stdc++.h>
using namespace std;

/*
    정수 X
    X가 3으로 나누어 떨어지면 3으로 나눈다
    X가 2로 나누어 떨어지면 2로 나눈다
    1을 뺀다

    정수 N을 위 세 연산을 사용하여 1을 만드려고 한다.
    연산을 사용하는 최솟값은?

    1 <= N <= 10^6
*/

using int64 = long long;

int64 n;
int64 dp[1'000'004];
const int64 MAX = 987654321;

void Solution(int64 n)
{
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);

        if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);

        dp[i] = min(dp[i - 1] + 1, dp[i]);

        // cout << "i: "<< i << ", dp: "<<  dp[i] << endl;
    }
    cout << dp[n] << '\n';
}

void Print(int64 n)
{
    if (n == 0)
        return;

    cout << n << " ";

    if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
        Print(n / 3);

    else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
        Print(n / 2);

    else if (n - 1 >= 0 && dp[n] == dp[n - 1] + 1)
        Print(n - 1);
}

int main()
{
    cin >> n;
    fill(dp, dp + 1'000'004, 987654321);

   Solution(n);

    Print(n);
    cout << '\n';

    return 0;
}