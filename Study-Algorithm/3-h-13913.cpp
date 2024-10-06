#include <bits/stdc++.h>
using namespace std;

/*
	숨바꼭질

	수빈 N(0 ≤ N ≤ 100,000)
	동생 K(0 ≤ K ≤ 100,000)

	수빈이 걸으면 x+1, x-1
	순간이동 x*2

	동생을 찾는 가장 빠른 시간
*/

int n, k;
const int LIMIT = 200'000;
int visited[LIMIT + 4];
int result;
int save[LIMIT + 4];
int minResult = INT_MAX;

void BFS(int start)
{
	queue<int> q;
	vector<int> v;
	q.push(start);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		/*cout << "BFS -> " << here << ", Visited -> " << visited[here] << '\n';
		for (int& i : cv)
			cout << i << " ";
		cout << '\n' << '\n';*/

		if (here == k)
		{
			result = visited[here];
			break;
		}

		for (int next : { here + 1, here - 1, here * 2 })
		{
			if (next >= LIMIT || next < 0)
				continue;

			if (visited[next] != 0)
				continue;

			visited[next] = visited[here] + 1;
			save[next] = here;
			q.push(next);
		}
	}
}

void Solution()
{
	if (n == k)
	{
		cout << 0 << '\n';
		cout << n << '\n';
		return;
	}

	BFS(n);

	cout << result << '\n';
	
	vector<int> vv;
	vv.push_back(k);
	int i = k;
	while (true)
	{
		if (save[i] == n)
		{
			vv.push_back(n);
			break;
		}
		vv.push_back(save[i]);
		i = save[i];
	}
	reverse(vv.begin(), vv.end());
	for (int& vvv : vv)
		cout << vvv << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	Solution();

	return 0;
}