#include <bits/stdc++.h>
using namespace std;

/*
    갑옷 재료는 번호가 있다.
    갑옷은 2개의 재료로 만든다.
    두 갑옷의 번호를 합쳐 M이 되면 갑옷이 된다.

    1 <= M <= 10,000,000
    N개의 재료, 1 <= N <= 15,000
    1 <= 고유번호 <= 100,000

    numbers[a,b,c,...]
    a + b = m
*/

void Solution(int n, int m, vector<int> &numbers)
{
    int sum = 0;

    if (n == 1 || m == 1 || m > 200'000)
    {
        cout << sum << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        auto start = numbers.begin() + 1 + i;

        auto it = find(start, numbers.end(), m - numbers[i]);

        if (it != numbers.end())
            sum++;
    }

    cout << sum << '\n';
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    Solution(n, m, numbers);
    return 0;
}