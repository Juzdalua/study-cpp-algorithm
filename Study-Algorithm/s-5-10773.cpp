#include <bits/stdc++.h>
using namespace std;

/*
	잘못된 수를 부르면 0을 외친다.
	가장 최근에 쓴 수를 지운다.

	1 ≤ K ≤ 100,000
	0 <= n <=1,000,000
	정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
*/

int k;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
			v.pop_back();
		else
			v.push_back(input);
	}

	int sum = 0;
	for (int& vv : v)
		sum += vv;
	cout << sum << '\n';

	return 0;
}