#include <bits/stdc++.h>
using namespace std;

/*
    경우의 수는 곱셈이다.
    옷을 입는 경우의 수 
    -> 각 타입마다 옷을 입지 않는 경우의 수를 더한 후 
        마지막에 아무것도 입지 않는 경우의 수 1개를 빼준다.
*/
int main()
{
    int total;
    cin >> total;
    for (int i = 0; i < total; i++)
    {
        map<string, int> clotheMap; // 종류만 알면 됨

        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string name;
            string type;

            cin >> name >> type;
            clotheMap[type]++; // 0으로 초기화된 갯수에 더하기
        }

        int sum = 1;
        for (auto c : clotheMap)
        {
            sum *= (c.second + 1); // 해당 타입의 옷 + 입지 않는 경우
        }
        sum--; // 아무것도 입지 않는 1개의 경우
        cout << sum << "\n";
    }

    return 0;
}
