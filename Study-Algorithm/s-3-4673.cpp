#include <bits/stdc++.h>
using namespace std;

/*
	양의 정수N
	d(n) => n과 n의 각 자릿수를 더하는 함수
	d(75) = 75+7+5 = 87

	33 + 3 + 3 = 39
	39 + 3 + 9 = 51
	51 + 5 + 1 = 57
	33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...

	n은 d(n)의 생성자
	101의 생성자는 91, 100 두개
	생성자가 없는수는 셀프넘버

	100보다 작은 셀프 넘버는 총 13개가 있다.
	1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97

	10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	map<int, int> m;
	for (int i = 1; i <= 10'000; i++)
	{
		string s = to_string(i);
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			sum += s[i] - '0';
		}
		int num = i + sum;
		if (num <= 10'000)
			m[num]++;
	}

	/*for (auto& mm : m)
		cout << mm.first << " : " << mm.second << '\n';*/

	for (int i = 1; i <= 10'000; i++)
	{
		if (m[i] == 0)
			cout << i << '\n';
	}

	return 0;
}