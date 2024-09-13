#include <bits/stdc++.h>
using namespace std;

/*
    공식
    nCr -> n개중에 r개를 뽑는 경우의 수
    n! / (n-r)! * r!
*/

int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};

void print(vector<int>& b)
{
    for(int i : b)  
        cout << i << " ";
    cout << '\n';
}

// 암기하기
void combination(int start, vector<int>& v)
{
    if(v.size() == r)
    {
        print(v);
        return;
    }

    for(int i = start + 1; i < n; i++)
    {
        v.push_back(i);
        combination(i, v);
        v.pop_back();
    }
}

int main()
{
    vector<int> vec;
    combination(-1, vec);
    return 0;
}
// --------------

int n = 9;
int r = 7;
vector<int> input;
vector<int> result;

void print()
{
    for (int a : result)
        cout << a << " ";
    cout << endl;
}

void combination(int start)
{
    if (result.size() == r)
    {
        print();
        return;
    }

    for (int i = start + 1; i < n; i++)
    {
        result.push_back(input[i]);
        combination(i);
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

    combination(-1);

    return 0;
}