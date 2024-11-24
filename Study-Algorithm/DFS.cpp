#include <bits/stdc++.h>
using namespace std;
/*
    1. 방문체크
    2. 이동 가능한 노드 재귀

DFS(u, adj)
{
	u.visited = true
	for each v ∈ adj[u]
		if v.visited == false
			DFS(v, adj)
}

void DFS(int here)
{
    visited[here] = 1;
    for(int there : adj[here])
	    if(visited[there]) 
            continue;
        DFS(there);
}

void DFS(int here)
{
    if(visited[here]) 
    	return;
    visited[here] = 1;
    for(int there : adj[here])
    	DFS(there);
}
*/
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