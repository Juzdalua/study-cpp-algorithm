#include <bits/stdc++.h>
using namespace std;

/*
    한칸 움직이면 당근 1개 소모
    최단거리로 당근마켓으로 간다
    당근 몇개를 소모?
*/
int n, m, x, y, destX, destY;
int cnt = 0;
int a[104][104];
int visited[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS()
{
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || nx >= n || ny >= n)
                continue;

            if (visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

void Solution()
{
    BFS();
    cout << visited[destY][destX] << endl;
}

int main()
{
    cin >> n >> m;
    cin >> y >> x;
    cin >> destY >> destX;
    cnt++;

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