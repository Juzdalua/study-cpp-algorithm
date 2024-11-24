#include <bits/stdc++.h>
using namespace std;

/*
    n가지 종류의 동전
    무제한 사용
    가치의 합이 k원
    순서만 다르면 같은 경우이다.

    1 <= n <= 100
    1 <= k <= 10'000
*/

int n, k;
int dp[10'004] = {0};

int main()
{
    dp[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        for (int j = input; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - input];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}