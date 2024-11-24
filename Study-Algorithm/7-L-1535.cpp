#include <bits/stdc++.h>
using namespace std;

/*
    N명, 1~N
    i번 사람에게 인사 -> 체력을 L[i]만큼 잃는다
    J[i]만큼 기쁨을 얻는다
    각각 한번만 말할 수 있다.

    주어진 체력 내에서 최대한 기쁨을 느끼는 것
    체력 100 기쁨 0
    체력이 <=0이면 죽는다. 기쁨 없어짐
    최대 기쁨을 출력하라
*/

int n;
int L[24], J[24];
int dp[104]; // 현재 체력에 얻을 수 있는 최대 기쁨

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> L[i];
    for (int i = 0; i < n; i++)
        cin >> J[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 100; j > L[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    cout << dp[100] << '\n';

    return 0;
}