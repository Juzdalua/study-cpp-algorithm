#include <bits/stdc++.h>
using namespace std;

/*
	탁자 위에 N개의 돌
	턴을 번갈아가며 돌을 가져간다.
	돌은 1개 또는 3개 가져간다
	마지막 돌을 가져가는 사람이 이긴다
	상근이가 먼저 시작한다.
	이기는 사람을 구하라

	상근-홀수
	찬영-짝수

	1 ≤ N ≤ 1000
*/

const string SK = "SK";
const string CY = "CY";
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if (n % 2 == 0)
		cout << CY << '\n';
	else
		cout << SK << '\n';

	return 0;
}