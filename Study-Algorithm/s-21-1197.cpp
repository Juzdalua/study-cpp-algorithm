#include <bits/stdc++.h>
using namespace std;

/*
	�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

	1 �� V �� 10,000
	1 �� E �� 100,000
*/

int v, e;
vector<pair<int, int>> arr[10'004];
int visited[10'004];
long long minResult = INT_MAX;

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

void Go(int here, int edgeCnt, long long sum)
{
	if (edgeCnt == v - 1)
	{
		cout << sum << '\n';
		exit(0);
	}
	if (arr[here].size() == 0)
	{
		return;
	}

	for (int i = 0; i < arr[here].size(); i++)
	{
		pair<int, int> next = arr[here][i];
		int nv = next.first;
		int add = next.second;

		if (visited[nv] != 0)
			continue;

		visited[nv] = 1;
		sum += add;
		
		Go(nv, edgeCnt + 1, sum);

		visited[nv] = 0;
		sum -= add;
	}
}

void Solution()
{
	for (int i = 1; i <= v; i++)
		sort(arr[i].begin(), arr[i].end(), Compare);

	for (int i = 1; i <= v; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		Go(i, 0, 0);
	}
	//cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		arr[in1].push_back({ in2,in3 });
		arr[in2].push_back({ in1,in3 });
	}

	Solution();

	return 0;
}