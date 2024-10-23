#include <bits/stdc++.h>
using namespace std;

/*
	N+1일 퇴사
	N일 근무
	T 시간
	P 금액
	백준이가 얻을 수 있는 최대 수익

	1 ≤ N ≤ 15
	1 ≤ Ti ≤ 5,
	1 ≤ Pi ≤ 1,000
*/

int n;
vector<pair<int, int>> v;
int maxResult = INT_MIN;

void Go(int start, int day, int sum)
{
	//cout << "Start -> " << start << ", Day -> " << day << ", Sum -> " << sum << '\n';
	if (start == n)
	{
		maxResult = max(maxResult, sum);
		//cout << "Done -> " << sum << '\n' << '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (day == 0 && v[i].first <= n - i)
		{
			sum += v[i].second;
			Go(i + 1, v[i].first - 1, sum);
			sum -= v[i].second;
		}
		else
		{
			if(day > 0)
				Go(i + 1, day - 1, sum);
			else
				Go(i + 1, day, sum);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		v.push_back({ in1,in2 });
	}

	Go(0, 0, 0);
	cout << maxResult << '\n';

	return 0;
}