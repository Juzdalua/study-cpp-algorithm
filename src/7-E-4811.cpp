#include <bits/stdc++.h>
using namespace std;

/*
    매일 약 반 알을 먹는다.
    약이 N개 담긴 병
    첫째 날, 약을 하나 꺼내서 반으로 쪼개 먹고 반은 다시 넣는다.
    다음날 약을 하나 꺼낸다. 한개일지 반일지 모른다
    반조각이면 먹고, 하나라면 반으로 쪼개 먹고 다시 반은 넣는다.
    한조각 꺼내면 W, 반조각 꺼내면 H

    2N일이 지나면 2N 길이의 문자열이 만들어진다.
    2N일 후, 서로 다른 문자열의 개수는?
*/
using int64 = long long;
int64 dp[30][30];
vector<int64> result;

int64 Solution(int64 one, int64 half)
{
    //int64 sum = 0;
    int64& sum = dp[one][half];
    if(one == 0 && half == 0)
        return 1;

    if (dp[one][half] != 0)
        return dp[one][half];

    if (one > 0)
        sum += Solution(one - 1, half + 1);

    if (half > 0)
        sum += Solution(one, half - 1);

    return sum;
}

int main()
{
    int64 pills[1004];
    memset(pills, -1, sizeof(pills));

    int64 i = 0;
    while (true)
    {
        int64 input;
        cin >> input;
        if (input == 0)
            break;
        pills[i] = input;
        i++;
    }

    for (int64 i = 0; i < 1004; i++)
    {
        if (pills[i] == -1)
            break;

        int64 go = Solution(pills[i] - 1, 1);
        result.push_back(go);
        dp[pills[i]][0] = go;
        dp[pills[i] - 1][1] = go;
    }

    for (auto &r : result)
        cout << r << '\n';

    return 0;
}