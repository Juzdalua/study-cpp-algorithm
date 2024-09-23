#include <bits/stdc++.h>
using namespace std;

/*
    1. 단순구현이라면 구현
    2. 그게 아니라면 문제의 최대/최소 범위 확인
    3. 최대범위 / 시간복잡도 확인 -> 모든 경우의 수로 풀기
    4. 그게 아니라면 다른 알고리즘 생각하기
    5. 반례 생각하기

    문제 범위가 없는 경우
    int64 n;
    while (cin >> n){}
    return 0;

    a:홀수 -> if(a & 1) -> 비트연산 이진수 1 확인
    a:홀수 -> if(a % 2) -> 2로 나눈 나머지 1 확인

    최대값을 구하라 -> 최소값부터
    최소값을 구하라 -> 최대값부터

    시각 -> 이상 미만 (for문)

    경우의 수 -> 예외 생각하고 곱셈

    대칭 문자열 만들기 -> 홀수 2개 이상 불가능

    % 연산
    (a + b) % c = ((a % c) + (b % c)) % c
    (a * b) % c = ((a % c) * (b % c)) % c

    DFS -> 그래프 탐색 (완전탐색)
    BFS -> 최단거리

    n가지 무한히 사용 -> 왼쪽부터 dp를 만든다
    for (int j = input; j <= k; j++)
    {
        dp[j] = min(dp[j], dp[j - input] + 1);
    }
    n가지 1번만 사용 -> 오른쪽부터 dp를 만든다
    for (int j = k; j >= input; j--)
    {
        dp[j] = min(dp[j], dp[j - input] + 1);
    }
*/
int main()
{
    cout << "Hello" << endl;
    return 0;
}