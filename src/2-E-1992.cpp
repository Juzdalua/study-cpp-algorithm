#include <bits/stdc++.h>
using namespace std;

/*
    쿼드트리
    흰점 0 / 검은점 1
    왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 4개로 압축
    -> (0(0011)(0(0111)01)1)
*/

int a[68][68];
int visited[68][68];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

string Quad(int y, int x, int size)
{
    if (size == 1)
        return string(1, a[y][x]);

    char b = a[y][x];
    string res = "";

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (b != a[i][j])
            {
                res += '(';
                res += Quad(y, x, size / 2);
                res += Quad(y, x + size / 2, size / 2);
                res += Quad(y + size / 2, x, size / 2);
                res += Quad(y + size / 2, x + size / 2, size / 2);
                res += ')';

                return res;
            }
        }
    }

    return string(1, a[y][x]);
}

string Solution(int x, int y)
{
    string res;
    int temp = -1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; i < 2; i++)
        {
            if (temp == -1)
            {
                temp == a[i][j];
                res += to_string(temp);
            }

            if (!a[i][j] == temp)
                res += to_string(a[i][j]);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            a[i][j] = input;
        }
    }

    Quad(0, 0, n);

    return 0;
}