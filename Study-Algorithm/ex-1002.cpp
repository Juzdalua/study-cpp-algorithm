#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int t;
vector<int> result;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 원이 같을 경우
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << '\n';
			continue;
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2)
		{
			cout << 0 << '\n';
			continue;
		}

		// 두 원 중심 사이 거리
		double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		// 1. 원이 떨어진 경우
		if (distance > r1 + r2) cout << 0 << '\n';

		// 2. 내부에서 만나지 않는 경우
		else if (distance < abs(r1 - r2)) cout << 0 << '\n';

		// 3. 외부에서 한 점이 만날 경우
		else if (distance == r1 + r2) cout << 1 << '\n';

		// 4. 내부에서 한 점이 만날 경우
		else if (distance == abs(r1 - r2)) cout << 1 << '\n';
		
		// 4. 두 점이 만날 경우
		else cout << 2 << '\n';
	}

	return 0;
}