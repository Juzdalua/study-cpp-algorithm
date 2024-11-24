#include <bits/stdc++.h>
using namespace std;

/*
    n가지 종류의 동전
    가치의 합 k원
    동전의 갯수 최소
    각 동전은 여러개 사용 가능

    1 <= n <= 100
    1 <= k <= 10'000
*/

int n, k;
int coin[104];
int dp[10'004];
int result = -1;
int INF = 987654321;

int main()
{
    fill(dp, dp + 10'004, INF);
    dp[0] = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        coin[i] = input;
        for (int j = input; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - input] + 1);
        }
    }

    if(dp[k] == INF)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
    return 0;
}