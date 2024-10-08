#include <bits/stdc++.h>
using namespace std;

/*
	N개의 정수로 이루어진 벡터 A
	A에 없는 가장 작은 양의정수를 반환한다 (0보다 큰)

	A = [1, 3, 6, 4, 1, 2] => 5
	[1, 2, 3] = 4
	 [−1, −3] = 1

	 1 <= N <= 100'000 = 10^5
	 A의 각 원소 범위 = −1,000,000 <= a <= 1,000,000 = 10^5
*/

int solution(vector<int>& A)
{
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	
	if (A.back() < 0 || A[0] > 1)
	{
		return 1;
	}

	vector<int> postiveA;
	for (int a : A)
	{
		if (a > 0)
			postiveA.push_back(a);
	}
	if (postiveA.size() == 0 || postiveA[0] > 1)
		return 1;

	for (int i = 0; i < postiveA.size() - 1; i++)
	{
		if (postiveA[i + 1] - postiveA[i] != 1)
		{
			return postiveA[i] + 1;
		}
	}
	return postiveA.back() + 1;
}

int main()
{
	vector<int> A = { -3,2,3,4};
	cout << solution(A) << '\n';
	return 0;
}