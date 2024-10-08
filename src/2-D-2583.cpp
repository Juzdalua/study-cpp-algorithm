#include <bits/stdc++.h>
using namespace std;

/*
    (0,2) -> (0,2) / (4,4) -> (3,1)
    (1,1) -> (1,3) / (2,5) -> (1,0)
    (4,0) -> (4,4) / (6,2) -> (5,3)
*/

int n, m, k;
int a[104][104];
int visited[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int sector = 0;
vector<int> rectangle;

void DFS(int y, int x)
{
    rectangle[rectangle.size() - 1]++;
    if (visited[y][x] == 0)
        visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;

        if (a[ny][nx] == 1 && visited[ny][nx] == 0)
            DFS(ny, nx);
    }
}

int main()
{
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int j = m - ry; j <  m - ly; j++)
        {
            for (int h = lx ; h <rx; h++)
            {
                a[j][h] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && visited[i][j] == 0)
            {
                rectangle.push_back(0);
                sector++;
                DFS(i, j);
            }
        }
    }

    cout << sector << '\n';
    sort(rectangle.begin(), rectangle.end());
    for (int rec : rectangle)
        cout << rec << " ";

    return 0;
}