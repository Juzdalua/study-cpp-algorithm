#include <bits/stdc++.h>
using namespace std;

/*
    보물지도 직사각형
    육지(L), 바다(W)
    상하좌우 육지만 이동 가능
    한칸-한시간
    가장 긴 시간이 걸리는 두곳 육지에 보물
    돌아가거나 같은곳 재방문 X

*/

int n, m;
char board[54][54];
int visited[54][54];
int result = -1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS(int y, int x)
{
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    int maxVisited = -1;

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx >= m || ny >= n || nx < 0 || ny < 0)
                continue;

            if (visited[ny][nx] == 0 && board[ny][nx] == 'L')
            {
                maxVisited = visited[y][x] + 1;
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    result = max(result, maxVisited);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++)
        {
            board[i][j] = input[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'L')
            {
                BFS(i, j);
            }
        }
    }

    //cout << "RESULT: ";
    cout << result-1 << '\n';
    return 0;
}