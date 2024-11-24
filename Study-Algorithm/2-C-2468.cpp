#include <bits/stdc++.h>
using namespace std;

int n;
int a[104][104];
int visited[104][104];

vector<int> height;
vector<int> counts;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x, int len)
{
    if(visited[y][x] == 0)
        visited[y][x] = 1;
        
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny >= n || nx >= n || ny < 0 || nx < 0)
            continue;
            
        if(a[ny][nx] > len && visited[ny][nx] == 0)
            DFS(ny,nx, len);
    }
}

int main()
{
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int input;
            cin >> input;
            a[i][j] = input;
            height.push_back(input);
        }
    }
    
    sort(height.begin(), height.end());
    height.erase(unique(height.begin(), height.end()), height.end()); 
    
    for(int k =0; k<height.size(); k++)
    {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i][j] > height[k] && visited[i][j] == 0)
                {
                    cnt++;
                    DFS(i, j, height[k]);
                }
            }
        }
        counts.push_back(cnt);
    }
    
    sort(counts.begin(), counts.end());
    int max = counts[counts.size()-1];
    if(max == 0)
        max = 1;
        
    cout << max << '\n';
    
    return 0;
}