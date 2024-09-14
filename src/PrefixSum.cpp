#include <bits/stdc++.h>
using namespace std;

/*
    지정된 배열의 요소가 변하지 않는 정적배열에 대해서만 누적합을 사용할 수 있다.
    사용의 편리함을 위해 1번째 순서부터 사용한다.
    누적합을 만들 원본 배열의 0번째 요소는 0으로,
    누적합 배열의 0번째 요소도 0으로 초기화한다.

    아래 요소들을 prefix sum으로 진행하면
    a[11] = [0, 1 2 3 4 5 6 7 8 9 10]
    p[0] = 0
    p[1] = 1 = p[0] + a[1]
    p[2] = 1 + 2 = p[1] + a[2]
    p[3] = 1 + 2 + 3 = p[2] + a[3]
    p[4] = 1 + 2 + 3 + 4 = p[3] + a[4]
    ...
    p[9] = 1 + 2 + 3 + 4 + ... + 9 = p[8] + a[9]
    p[10] = 1 + 2 + 3 + 4 + ... + 10 = p[9] + a[10]

    2~5까지의 합 -> p[5] - p[1]
    4~8까지의 합 -> p[8] - p[4]
*/

int main()
{
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int psum[11] = {0};

    for(int i=1; i<=10; i++)
    {
        psum[i] = psum[i-1] + a[i];
        cout << psum[i] << " ";
    }

    return 0;
}