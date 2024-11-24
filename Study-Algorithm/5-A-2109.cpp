#include <bits/stdc++.h>
using namespace std;

/*
    0 <= n <= 10'000
    한 명의 학자, n개의 대학에서 강의

    1 <= d <= 10'000 / 1 <= p <= 10,000
    d일안에 강의를 해주면 강연료 p 지불
    각 대학마다 d와 p는 다를 수 있다.
    가장 많은 돈을 벌 수 있도록 순회
    하루에 한 강의만 가능

*/

int n;
vector<pair<int, int>> pd;

int main()
{
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int p, d;
        cin >> p >> d;
        pd.push_back(make_pair(d, p));
    }
    sort(pd.begin(), pd.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& pair : pd)
    {
        pq.push(pair.second);
        if(pq.size() > pair.first)
            pq.pop();
    }

    int sum = 0;
    while(!pq.empty())
    {
        int pay = pq.top();
        pq.pop();
        sum += pay;
    }

    cout << sum << '\n';

    return 0;
}