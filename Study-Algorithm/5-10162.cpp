#include <bits/stdc++.h>
using namespace std;

/*
    A: 5분 - 300초, B: 1분 - 60초, C: 10초
    ABC = T초, 1 ≤ T ≤ 10,000
    최소로 누르기
*/

int main()
{
    int t;
    cin >> t;

    int a = 300;
    int b = 60;
    int c = 10;

    int result = -1;

    map<char, int> pushMap;
    pushMap['a'] = 0;
    pushMap['b'] = 0;
    pushMap['c'] = 0;

    if(a <= t)
    {
        pushMap['a'] = t/a;
        t %= a;
    }

    if(b <= t)
    {
        pushMap['b'] = t/b;
        t %= b;
    }

    if(c <= t)
    {
        pushMap['c'] = t/c;
        t %= c;
    }

    if(t != 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        for(auto& p : pushMap)
            cout << p.second << " ";
        cout << '\n';
    }

    return 0;
}