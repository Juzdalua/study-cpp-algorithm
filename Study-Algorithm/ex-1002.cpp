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

		// ���� ���� ���
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

		// �� �� �߽� ���� �Ÿ�
		double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		// 1. ���� ������ ���
		if (distance > r1 + r2) cout << 0 << '\n';

		// 2. ���ο��� ������ �ʴ� ���
		else if (distance < abs(r1 - r2)) cout << 0 << '\n';

		// 3. �ܺο��� �� ���� ���� ���
		else if (distance == r1 + r2) cout << 1 << '\n';

		// 4. ���ο��� �� ���� ���� ���
		else if (distance == abs(r1 - r2)) cout << 1 << '\n';
		
		// 4. �� ���� ���� ���
		else cout << 2 << '\n';
	}

	return 0;
}