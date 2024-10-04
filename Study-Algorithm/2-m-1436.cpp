#include <bits/stdc++.h>
using namespace std;

/*
	종말의 수
	6이 적어도 3개 이상 연속으로 들어가는 수

	666, 1666, 2666, 3666, ...
	N번째 영화제목 -> N번째로 작은 종말의 수
	1 <= N <= 10'000

	N = 1, 666
	N = 2, 1666
	N = 8, 9666
	N = 9, 10666
	N = 10, 11666
	
	N = 187, 66666
	N = 500, 166699
*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int i = 0;
	int a = 665;
	while (true)
	{
		a++;
		if (to_string(a).find("666") != string::npos)
		{
			i++;
			if (i == n)
			{
				cout << a << '\n';
				break;
			}
		}
	}

	return 0;
}