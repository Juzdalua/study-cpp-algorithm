#include <bits/stdc++.h>
using namespace std;

/*
    2와 5로 나누어 떨어지지 않는 정수 n
    1 <= n <= 10'000
    각 자릿수가 모두 1인 n의 배수 찾기
    n의 배수중 가장 작은 수의 자리수 출력
*/

using int64 = long long;

int64 Nextint64(int64 input, int64 n, int &returnSize)
{
    returnSize++;
    return (input * 10 + 1) % n;
}

void Solution(int64 n)
{
    int returnSize = 0;
    int64 input = 0;
    while (true)
    {
        input = Nextint64(input, n, returnSize);
        if (input % n == 0)
        {
            cout << returnSize << '\n';
            return;
        }
    }
}

int main()
{
    int64 n;
    while (cin >> n)
    {
        Solution(n);
    }
    return 0;
}