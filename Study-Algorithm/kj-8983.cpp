#include <bits/stdc++.h>
using namespace std;

/*
	N마리 동물들이 각각 특정한 위치에 있다.
	사냥꾼은 일직선상에 위치한 M개의 사대에서만 사격이 가능하다.

	총의 사정거리 L
	사대에서 동물과 거리가 L보다 작거나 같은 동물에게 사격
	사대x, 동물(a,b)의 거리는 |x-a| + b

	잡을 수 있는 동물의 수를 출력하라

	사대의 수 M (1 ≤ M ≤ 100,000)
	동물의 수 N (1 ≤ N ≤ 100,000)
	사정거리 L (1 ≤ L ≤ 1,000,000,000)
	좌표의 최대값 1,000,000,000 - 10억
*/

using int64 = long long;
int64 n, m, l;
vector<int64> hunter;
vector<pair<int64, int64>> animal;
int64 result;

void Solution()
{
	// 동물마다 탐색
	for (auto& a : animal)
	{
		int64 x, y;
		tie(x, y) = a;

		// 동물과 가장 가까운 사대 찾기
		auto findRightKey = upper_bound(hunter.begin(), hunter.end(), x);
		int64 right = (findRightKey != hunter.end()) ? *findRightKey : LLONG_MAX; // 오른쪽 사대
		int64 left = (findRightKey != hunter.begin()) ? *(--findRightKey) : LLONG_MIN; // 왼쪽 사대

		int64 closeHunter = -1;
		if (abs(x - left) > abs(x - right))
			closeHunter = right;
		else
			closeHunter = left;

		// 사대와 거리 계산
		if (l >= abs(closeHunter - x) + y)
			result++;
	}
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> l;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		hunter.push_back(input);
	}
	sort(hunter.begin(), hunter.end());

	for (int i = 0; i < n; i++)
	{
		int64 x, y;
		cin >> x >> y;

		// 사정거리 밖
		if (y > l)
			continue;


		// 사정거리 끝이면 사대와 동일 위치
		if (y == l)
		{
			if (find(hunter.begin(), hunter.end(), x) == hunter.end())
				continue;
		}

		// 나머지 삽입
		animal.push_back(make_pair(x, y));
	}

	Solution();

	return 0;
}