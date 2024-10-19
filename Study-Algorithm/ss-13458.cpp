#include <bits/stdc++.h>
using namespace std;

/*
	N개의 시험장
	각 시험장마다 응시자가 있다.
	i번 시험장의 응시자는 A[i]명

	총감독관, 부감독관
	총감독관 - 한 시험장에서 B명 감시
	부감독관 - 한 시험장에서 C명 감시
	각 시험장에 총 감독관은 1명, 부감독관은 여러명 가능
	각 시험장의 응시생을 모두 감시해야한다.

	필요한 감독관의 최소값을 구하라

	시험장 1 ≤ N ≤ 1,000,000 - 10^6
	각 시험장 응시자 수 1 ≤ Ai ≤ 1,000,000 - 10^6
	1 ≤ B, C ≤ 1,000,000
*/

using int64 = long long;

int n;
int arr[1'000'004];
int b, c;
int64 sum;

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		// 총감독
		sum++;
		arr[i] -= b;
		if (arr[i] <= 0)
			continue;

		if (arr[i] % c == 0)
		{
			sum += arr[i] / c;
		}
		else
		{
			sum += (arr[i] / c) + 1;
		}
	}
	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> b >> c;

	Solution();

	return 0;
}