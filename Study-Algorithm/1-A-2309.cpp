#include <bits/stdc++.h>
using namespace std;

/*
    난쟁이 7명
    9명이 돌아옴
    7명 키의 합 = 100
    9명의 키가 주어지고 7명을 골라라
    nCr -> 9C7 -> n! / r!(n-r)!
*/

int n = 9;
int r = 7;
vector<int> input;
vector<int> result;

void Print()
{
    for (int a : result)
        cout << a << " ";
    cout << endl;
}

void Solution()
{
    int sum = 0;
    for (int a : result)
    {
        sum += a;
    }

    if (sum == 100)
    {
        sort(result.begin(), result.end());
        for(int a : result)
            cout << a << endl;
        exit(0);
    }
}

void Combination(int start)
{
    if (result.size() == r)
    {
        // Print();
        Solution();
        return;
    }

    for (int i = start + 1; i < n; i++)
    {
        result.push_back(input[i]);
        Combination(i);
        result.pop_back();
    }
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }

    Combination(-1);

    return 0;
}