#include <bits/stdc++.h>
using namespace std;

/*
    새집 N*N, 한칸 1*1
    각 칸은 (r,c)
    행과 열, r과 c는 1부터 시작

    파이프는 항상 빈칸만 차지한다.
    오른쪽, 아래, 오른아래 3방향 이동 가능
    0: 빈칸, 1: 벽

    처음 파이프 위치는 (1,1), (1,2) 가로
*/

int n;
int board[20][20];
int visited[20][20];
int result = 0;
int dp[20][20]; // 0: 가로, 1: 대각선, 2: 세로

int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};

bool CanGo(int i, int &position)
{
    if (i > 2 || i < 0)
        return false;

    switch (i)
    {
    // 가로 이동
    case 0:
        if (position == 0 || position == 1)
        {
            position = 0;
            return true;
        }
        break;

    // 대각선 이동
    case 1:
        position = 1;
        return true;
        break;

    // 세로 이동
    case 2:
        if (position == 1 || position == 2)
        {
            position = 2;
            return true;
        }
        break;

    default:
        break;
    }
    return false;
}

void DFS(int y, int x, int position)
{
    // cout << "START DFS: (" << y << ", " << x << ")" << endl;

    if (visited[y][x] = 0)
        visited[y][x] = 1;

    if (y == n - 1 && x == n - 1)
    {
        result++;
        // cout << "END DFS: (" << y << ", " << x << ")" << endl;
        return;
    }

    dp[y][x] = position;
    for (int i = 0; i < 3; i++)
    {
        position = dp[y][x];
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || nx >= n || ny < 0 || nx < 0)
            continue;

        if (!CanGo(i, position))
            continue;

        if (i == 1)
        {
            if (!(board[y][x + 1] == 0 && board[y + 1][x + 1] == 0 && board[y + 1][x] == 0))
                continue;
        }

        if (board[ny][nx] == 0 && visited[ny][nx] == 0)
        {
            // cout << "Y: " << y << ", X: " << x << " - ";
            // cout << "DY: " << dy[i] << ", DX: " << dx[i] << " - ";
            // cout << "NY: " << ny << ", NX: " << nx << " - ";
            // cout << "P: " << position << " / i: " << i << " -> (" << ny << ", " << nx << ")";
            // cout << " => DFS: (" << ny << ", " << nx << ")" << endl;

            DFS(ny, nx, position);
        }
    }
    // cout << "END DFS: (" << y << ", " << x << ")" << endl;
}

int main()
{
    cin >> n;
    memset(board, -1, sizeof(board));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }

    dp[0][1] = 1;
    DFS(0, 1, 0);
    cout << result << '\n';

    return 0;
}