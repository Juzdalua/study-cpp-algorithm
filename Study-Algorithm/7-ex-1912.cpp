#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
	n개의 정수로 이루어진 임의의 수열
	연속된 몇개의 수를 선택해서 가장 큰 합을 구한다.
	수는 한 개 이상 선택해야한다.
	1 <= n <= 100'000
	-1'000 <= data <= 1'000
*/

using int64 = long long;

int n;
int64 arr[100'004];
int64 maxSum = -1001;


void Solution()
{
	int64 sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		maxSum = max(maxSum, sum);

		if (sum < 0)
			sum = 0;
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
		cin >> arr[i];
	}

	Solution();

	cout << maxSum << '\n';

	return 0;
}