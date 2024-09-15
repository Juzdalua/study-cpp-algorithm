#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

int a[104][104];
bool visiited[1004][1004];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int u)
{
    visited[u] = 1;
    cout << u << "\n";
    for (int v : adj[u])
    {
        if (visited[v] == 0)
        {
            DFS(v);
        }
    }
    cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

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

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[2].push_back(5);
    
    DFS(1);
}