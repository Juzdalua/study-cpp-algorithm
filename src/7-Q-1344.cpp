#include <bits/stdc++.h>
using namespace std;

/*
    축구 90분
    5분간격으로 분석
    간격마다 A, B팀이 득점할 확률
    간격마다 많아야 1골 득점
    한팀, 혹은 두팀이 소수로 득점할 확률
*/

double a, b;
double dpA[22], dpB[22]; // 넣은 골의 수 -> 해당 골을 넣을 확률
const int n = 18;
const int sosu[7] = {2, 3, 5, 7, 11, 13, 17};

void Solution()
{
    dpA[0] = dpB[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            // j골을 넣은 상황에서 골을 넣지 않을 경우 + j-1골을 넣은 상황에서 골을 넣을 경우
            dpA[j] = dpA[j] * (1 - a) + dpA[j - 1] * a;
            dpB[j] = dpB[j] * (1 - b) + dpB[j - 1] * b;
        }

        // 5분마다 확률 업데이트
        dpA[0] *= (1 - a);
        dpB[0] *= (1 - b);
    }
}

bool isPrime(int score)
{
    // 소수인지 여부를 확인하는 함수
    for (int i = 0; i < 7; i++)
    {
        if (score == sosu[i])
            return true;
    }
    return false;
}

void Print()
{
    // 소수 득점 확률
    // double primeA = 0, primeB = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     if (isPrime(i))
    //     {
    //         primeA += dpA[i];
    //         primeB += dpB[i];
    //     }
    // }

    // 두 팀 모두 소수로 득점하지 않는 경우
    double neitherPrime = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (!isPrime(i) && !isPrime(j))
            {
                neitherPrime += dpA[i] * dpB[j];
            }
        }
    }

    // 적어도 한 팀이 소수 득점할 확률 = 1 - (두 팀 모두 소수가 아닌 경우의 확률)
    double result = 1 - neitherPrime;

    // 결과 출력 (소수점 6자리)
    cout << fixed << setprecision(6) << result << '\n';
}

int main()
{
    cin >> a >> b;
    a /= 100;
    b /= 100;

    Solution();
    Print();

    return 0;
}