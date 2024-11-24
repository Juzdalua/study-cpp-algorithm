#include <bits/stdc++.h>
using namespace std;

/*
    N칸의 스크린 / M 칸의 바구니 (N > M)
    처음 바구니는 왼쪽 M칸을 차지
    바구니 좌우 이동 가능. 경계는 넘지 말것

    사과는 N칸 중 한 칸에서 떨어진다
    사과가 바닥에 닿으면 다른 사과가 즉시 떨어진다.
    사과를 모두 담을 때, 바구니 이동거리 최소값
*/

int board[14];
int n, m, j, leftM, rightM;

int main()
{

    cin >> n >> m;
    cin >> j;

    int sum = 0;
    leftM = 0;
    rightM = leftM + m - 1;

    for (int i = 0; i < j; i++)
    {
        int input;
        cin >> input;
        board[input - 1]++;

        if (input - 1 >= leftM && input - 1 <= rightM)
        {
            board[input - 1]--;
        }
        else
        {
            while (true)
            {
                if (input - 1 > rightM)
                    leftM++;
                else
                    leftM--;

                rightM = leftM + m - 1;
                sum++;
                if (input - 1 >= leftM && input - 1 <= rightM)
                    break;
            }
        }
    }

    cout << sum << '\n';

    return 0;
}