#include <bits/stdc++.h>
using namespace std;

/*
    N마리 소가 방문
    도착시간, 검문시간은 소마다 다르거나 같다
    하나의 소만 검문
    모든 소가 농장에 입장하는데 걸리는 시간
*/

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> cowVec;
    for(int i=0; i<n; i++)
    {
        int arrive, check;
        cin >> arrive >> check;
        cowVec.push_back(make_pair(arrive, check));
    }

    sort(cowVec.begin(), cowVec.end());
    // for(auto& a : cowVec)
    //     cout << a.first << ":" << a.second << endl;

    int time = 0;
    for(auto& a : cowVec)
    {
        if(time < a.first)
            time = a.first;
        time += a.second;
    }

    cout << time << '\n';

    return 0;
}