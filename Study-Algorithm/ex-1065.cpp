#include <bits/stdc++.h>
using namespace std;

/*
	양의정수 X
	각 자리가 등차수열 = 한수
	등차수열 = 연속된 두개의 수의 차이가 일정한 수열
	1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램
*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n < 100)
	{
		cout << n << '\n';
		exit(0);
	}

	int result = 99;
	for (int i = 100; i <= n; i++)
	{
		string num = to_string(i);

		int sub = (num[1] - '0') - (num[0] - '0');
		//cout << "i: " << i << ", sub: " << sub << '\n';
		for (int j = 0; j < num.size() - 1; j++)
		{
			if (num[j + 1] - num[j] != sub)
				break;
			if (j == num.size() - 2)
			{
				//cout << "HAN -> " << i << '\n';
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}