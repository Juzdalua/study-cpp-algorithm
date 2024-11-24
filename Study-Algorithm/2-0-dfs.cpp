#include <bits/stdc++.h>
using namespace std;

/*
    N * M맵, 맵의 배열이 주어진다.
*/
int a[104][104];
bool visiited[1004][1004];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;

void DFS(int y, int x)
{
    visiited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)
            continue;

        if (a[nextY][nextX] == 1 && !visiited[nextY][nextX])
            DFS(nextY, nextX);
    }
}

void Solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && !visiited[i][j])
                DFS(i, j);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    Solution();
    return 0;
}