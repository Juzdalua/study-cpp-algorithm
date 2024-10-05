#include <bits/stdc++.h>
using namespace std;

/*
	N개의 컴퓨터
	A가 B를 신뢰 -> B해킹 => A도 해킹됨
	한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호
	1<= N <= 10'000
	1<= M <= 100'000
*/

bool CustomCompare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int n, m;
vector<vector<int>> inputs;
vector<pair<int, int>> result;
int visited[10'004];
int maxResult = -1;

void PrintResult()
{
	for (auto& r : result)
	{
		if (r.second == maxResult)
		{
			cout << r.first << " ";
		}
		if (r.second < maxResult)
			break;
	}
}

void Print()
{
	for (int i = 1; i <= n; i++)
	{
		cout << i << " -> ";
		for (int ii : inputs[i])
			cout << ii << " ";
		cout << "\n";
	}
}

int DFS(int idx)
{
	if (visited[idx] == 0)
		visited[idx] = 1;

	int cnt = 1;

	for (auto& i : inputs[idx])
	{
		if(visited[i] == 0)
			cnt += DFS(i);
	}

	return cnt;
}

void Solution()
{
	//Print();

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		int res = DFS(i);
		result.push_back(make_pair(i, res));

		//cout << "i: " << i << ", MAX: " << res << '\n';
		maxResult = max(maxResult, res);
	}

	sort(result.begin(), result.end(), CustomCompare);
	
	PrintResult();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	inputs.resize(n + 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		inputs[b].push_back(a);
	}

	Solution();

	return 0;
}