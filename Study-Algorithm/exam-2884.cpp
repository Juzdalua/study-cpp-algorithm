#include <bits/stdc++.h>
using namespace std;

/*
	45분 일찍 알람설정하기

*/	

int h, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> m;
	if (m >= 45)
	{
		cout << h << " " << m - 45 << '\n';
		exit(0);
	}

	m += 60;
	m -= 45;
	if (h > 0)
		h -= 1;
	else
	{
		h = 23;
	}
	cout << h << " " << m << '\n';

	return 0;
}