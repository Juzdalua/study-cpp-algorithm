#include <bits/stdc++.h>
using namespace std;

/*
    출발 (1,1)
    도착 (n,m)
    최소 칸의 수 -> BFS

*/

int x, y, nx, ny, n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int a[104][104] = {0};
int visited[104][104] = {0};
queue<pair<int, int>> q;

void BFS()
{
    if (visited[y][x] == 0)
        visited[y][x] = 1;

    q.push(make_pair(y, x));

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        //cout << "BFS: (" << y << ", " << x << ")" << " / Visit: " << visited[y][x] << endl;

        for (int i = 0; i < 4; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny >= n || nx >= m || ny < 0 || nx < 0)
                continue;

            if (visited[ny][nx] != 0)
                continue;

            if (a[ny][nx] == 0)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++)
        {
            a[i][j] = input[j] - '0';
        }
    }

    x = y = 0;
    BFS();
    cout << visited[n - 1][m - 1];
    return 0;
}