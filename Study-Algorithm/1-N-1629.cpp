#include <bits/stdc++.h>
using namespace std;

/*
    자연수 A를 B번 곱한 수 -> A^B
    A ^ B % C
*/
using int64 = long long;
int64 Multiple(int a, int b, int c)
{
    if (b == 1)
    {
        return a % c;
    }

    int64 data = Multiple(a, b / 2, c);
    data = (data * data) % c;

    if (b % 2)
        data = (data * a) % c;

    return data;
}

void Solution(int64 a, int64 b, int64 c)
{
    cout << Multiple(a, b, c) << '\n';
}

int main()
{
    int64 a, b, c;
    cin >> a >> b >> c;

    Solution(a, b, c);

    return 0;
}