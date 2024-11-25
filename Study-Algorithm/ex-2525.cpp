#include <bits/stdc++.h>
using namespace std;

/*
	현재 시각은 시 A (0 ≤ A ≤ 23) 와 분 B (0 ≤ B ≤ 59)가 정수로 빈칸을 사이에 두고 순서대로 주어진다.

*/

int hour, minutes, req;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> hour >> minutes >> req;



	if (minutes + req >= 60)
	{
		minutes += req;
		hour += minutes / 60;

		if (hour >= 24)
			hour -= 24;

		minutes %= 60;
	}
	else
		minutes += req;

	cout << hour << " " << minutes << '\n';
	return 0;
}