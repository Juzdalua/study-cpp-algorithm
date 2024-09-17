#include <bits/stdc++.h>
using namespace std;

/*
    
*/
int t, n, m, k, nx, ny;
int a[54][54] = {0};
int visited[54][54] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x)
{
    if(visited[y][x] == 0)
        visited[y][x] = 1;
    
    for(int i=0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(nx >= n || ny >= m || nx < 0 || ny < 0)
            continue;
            
        if(visited[ny][nx] == 0 && a[ny][nx] == 1)
            DFS(ny, nx);
    }
}

int main()
{
    vector<int> result;
    
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        
        int cnt = 0;
        cin >> m >> n >> k;
        
        for(int i=0; i<k; i++)
        {
            int o, p;
            cin >> o >> p;
            a[o][p] = 1;
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i][j] == 1 && visited[i][j] == 0)
                {
                    cnt++;
                    DFS(i, j);
                }
                
            }
        }
        //cout << cnt << '\n';
        result.push_back(cnt);
    }
    for(int res : result)
        cout << res << '\n';
        
    return 0;
}