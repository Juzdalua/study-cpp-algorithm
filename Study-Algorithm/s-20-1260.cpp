#include <bits/stdc++.h>
using namespace std;

/*
	1~N번 방문
	1 ≤ N ≤ 1,000
	1 ≤ M ≤ 10,000
	탐색을 시작할 정점의 번호 V
*/

int n, m, v;
vector<int> arr[1004];
int visited[1004];
vector<int> result;

void DFS(int here)
{
	if (visited[here] == 0)
	{
		visited[here] = 1;
		result.push_back(here);
	}

	for (int i = 0; i < arr[here].size(); i++)
	{
		int next = arr[here][i];
		if (visited[next] != 0)
			continue;

		DFS(next);
	}
}

void BFS(int start)
{
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	result.push_back(start);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < arr[here].size(); i++)
		{
			int next = arr[here][i];
			if (visited[next] != 0)
				continue;

			visited[next] = 1;
			result.push_back(next);
			q.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	for (int i = 0; i < m;i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		arr[in1].push_back(in2);
		arr[in2].push_back(in1);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	DFS(v);
	for (int& r : result)
		cout << r << " ";
	cout << '\n';
	result.clear();
	memset(visited, 0, sizeof(visited));

	BFS(v);
	for (int& r : result)
		cout << r << " ";
	cout << '\n';

	return 0;
}