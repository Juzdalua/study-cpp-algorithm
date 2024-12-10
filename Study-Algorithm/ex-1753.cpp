#include <bits/stdc++.h>
using namespace std;

/*

*/

int v, e;
int start;
vector<int> arr[20'004];
int w[20'004][20'004];
int visited[20'004];
vector<string> result;

void BFS(int destination)
{
	//cout << "BFS -> " << destination << '\n';
	if (start == destination)
	{
		result.push_back("0");
		return;
	}

	visited[start] = 1;

	queue<pair<int, int>> q;
	q.push({ start, 0 });

	int res = INT_MAX;
	bool flag = false;

	while (!q.empty())
	{
		auto [here, weight] = q.front();
		q.pop();
		/*cout << "Here -> " << here << ", Weight -> " << weight << '\n';*/

		if (here == destination)
		{
			flag = true;
			res = min(res, weight);
			continue;
		}

		if (weight >= res) continue;

		for (int i = 0; i < arr[here].size(); i++)
		{
			int next = arr[here][i];

			if (visited[next] != 0) continue;

			//cout << "Here -> " << here << ", Next -> " << next << ", Sum -> " << weight << ", Weight -> " << w[here][next] << ", Result -> " << res << '\n';
			visited[next] = true;
			q.push({ next, weight + w[here][next] });
		}
	}

	if (flag) result.push_back(to_string(res));
	else result.push_back("INF");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e >> start;
	for (int i = 0; i < e; i++)
	{
		int input1, input2, input3;
		cin >> input1 >> input2 >> input3;
		w[input1][input2] = input3;

		arr[input1].push_back(input2);
	}

	for (int i = 1; i <= v; i++)
	{
		memset(visited, 0, sizeof(visited));
		BFS(i);
	}

	for (string& s : result)
		cout << s << '\n';

	return 0;
}