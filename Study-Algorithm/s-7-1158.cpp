#include <bits/stdc++.h>
using namespace std;

/*
	1~N 사람이 원형으로 앉아있고 K가 주어진다.
	순서대로 K번쨰 사람을 제거한다
	N명의 사람이 모두 제거될때까지 반복한다.

	(n,k) 요세푸스 순열
	(7, 3) -> <3, 6, 2, 7, 5, 1, 4>

	1 ≤ K ≤ N ≤ 5,000

	7 3
	<3, 6, 2, 7, 5, 1, 4>

	6 6
	<6, 1, 3, 2, 5, 4>
*/

int n, k;
queue<int> q;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	int i = 0;
	while (!q.empty())
	{
		int  num = q.front();
		q.pop();
		i++;

		if (i == k)
		{
			result.push_back(num);
			i = 0;
		}
		else
		{
			q.push(num);
		}
	}

	cout << "<";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		if (i != result.size() - 1)
			cout << ", ";
	}
	cout << ">";

	return 0;
}