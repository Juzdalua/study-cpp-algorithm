#include <bits/stdc++.h>
using namespace std;

/*
	윤년1, 아니면0
	1. 연도가 4의 배수
	2. 100의 배수가 아닐 때, 또는 400의 배수일 때
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if((n%4 == 0 && n%100 != 0) || (n%4 == 0 && n%400 == 0))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}