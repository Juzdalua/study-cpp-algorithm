#include <bits/stdc++.h>
using namespace std;

/*
	1 ≤ X ≤ 10,000,000 - 10^7
*/
int x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x;

	int num = 1;
	int acc = 1;

	if (x == 1)
	{
		cout << "1/1" << '\n';
		exit(0);
	}

	while (true)
	{
		num++;
		acc += num;

		if (x <= acc)
			break;
	}
	//cout << "Num: " << num << ", Acc: " << acc << '\n';

	pair<int, int> pos = { -1, -1 };
	int diff = acc - x;

	// 짝수 대각선 -> 아래, 홀수 대각선 -> 위
	if (num % 2 == 0)
	{
		pos = { num, 1 };
		pos.first -= diff;
		pos.second += diff;
	}
	else
	{
		pos = { 1, num };
		pos.first += diff;
		pos.second -= diff;
	}

	cout << pos.first << "/" << pos.second << '\n';

	return 0;
}