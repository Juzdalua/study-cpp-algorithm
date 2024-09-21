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

int64 Solution(int64 n)
{
    int64 &count = dp[n];

    if (n == 1)
    {
        count = 0;
        return 0;
    }

    if (n % 3 == 0)
        count = min(count, Solution(n / 3) + 1);

    if (n % 2 == 0)
        count = min(count, Solution(n / 2) + 1);

    count = min(count, Solution(n - 1) + 1);

    return count;
}

int main()
{
    cin >> n;
    fill(dp, dp + 1'000'004, 987654321);
    dp[0] = 0;
    cout << Solution(n) << "\n";

    int cnt = -1;
    for (int i = n - 1; i >= 0; i++)
    {
        if (dp[i] == MAX)
            continue;

        if (cnt == 0)
            break;

        if (i == 0 || dp[i] == cnt - 1)
        {
            cnt = dp[i];
            cout << i << " ";
            continue;
        }
    }

    cout << '\n';

    return 0;
}