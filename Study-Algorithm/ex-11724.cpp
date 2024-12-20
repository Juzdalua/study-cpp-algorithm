#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;
vector<vector<int>> g;
long long result;
int visited[1004];

void BFS(int start)
{
	visited[start] = 1;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < g[here].size(); i++)
		{
			int next = g[here][i];
			if (visited[next] != 0) continue;

			visited[next] = 1;
			q.push(next);
		}
	}
	result++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	g.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;
		g[input1].push_back(input2);
		g[input2].push_back(input1);
	}

	/*for (auto& gg : g)
	{
		for (int& i : gg)
			cout << i << " ";
		cout << '\n';
	}*/

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0) BFS(i);
	}

	cout << result << '\n';

	return 0;
}