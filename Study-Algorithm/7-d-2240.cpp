#include <bits/stdc++.h>
using namespace std;

/*
	�ڵθ� �ɰ� �Դ´�
	�ڵα� �������� �޾ƸԴ´�
	�ڵΰ� �ٴڿ� �������� �� ����� ���� �� ��ƾ��Ѵ�

	�� ��, �ΰ� ������ �ϳ��� �������� �ڵΰ� ��������
	���� ���Ű� �������� ����, �ڵΰ� �� ������ �Ʒ��� �� ������ �ڵδ� �� ���Ÿ� �޾Ƹ��� �� �ִ�.
	�ڵδ� �ϳ��� ���� �Ʒ��� �� �ִٰ� �ٸ� ���� �Ʒ��� ������(1�ʺ��� �ξ� ª�� �ð���) ������ �� �ִ�.

	�ڵδ� T�ʵ��� ��������
	�ڵδ� �ִ� W�� �����δ�
	1��T��1,000
	1��W��30

	�ڵΰ� ���� �� �ִ� �ڵ��� �ִ� ������ ����Ѵ�
	�ڵδ� 1�� �ڵγ��� �Ʒ��� ��ġ�� �ִٰ� �Ѵ�.
*/

int t, w;
int arr[1'004];
int maxResult = INT_MIN;
int dp[1'004][4][34]; // [T][location][W]

void Go(int cnt, int sum, int location)
{
	//cout << "Start -> Count: " << cnt << ", Sum: " << sum << ", Location: " << location << '\n';
	if (cnt >= t)
	{
		maxResult = max(maxResult, sum);
		return;
	}

	int jadu = arr[cnt];

	for (int i = 0; i < 2; i++)
	{
		//cout << "i: " << i << '\n';
		if (i == 1)
		{
			if (location == 1)
				location = 2;
			else if (location == 2)
				location = 1;
		}

		if (location == jadu)
			sum++;
		Go(cnt + 1, sum, location);
		if (location == jadu)
			sum--;
	}
}

int Go2(int cnt, int location, int moveCount)
{
	if (cnt >= t)
		return 0;

	if (dp[cnt][location][moveCount] != -1)
		return dp[cnt][location][moveCount];

	int jadu = arr[cnt];
	int& result = dp[cnt][location][moveCount];

	for (int i = 0; i < 2; i++)
	{
		if (i == 1 && moveCount < w)
		{
			if (location == 1)
				location = 2;
			else
				location = 1;
			moveCount++;
		}
		if (location == jadu)
			result = max(result, 1 + Go2(cnt + 1, location, moveCount));
		else
			result = max(result, Go2(cnt + 1, location, moveCount));
	}

	// �̵����� �ʰ�
	//if (location == jadu)
	//	result = 1 + Go2(cnt + 1, location, moveCount);
	//else
	//	result = Go2(cnt + 1, location, moveCount);

	//// �̵��ϰ�
	//if (moveCount < w)
	//{
	//	if (location == 1)
	//		location = 2;
	//	else
	//		location = 1;

	//	if (location == jadu)
	//		result = max(result, 1 + Go2(cnt + 1, location, moveCount + 1));
	//	else
	//		result = max(result, Go2(cnt + 1, location, moveCount + 1));
	//}

	return result;
}

void Solution()
{
	//Go(1, 0, 1);
	//cout << maxResult << '\n';

	memset(dp, -1, sizeof(dp));
	int result = Go2(0, 1, 0);
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}

	Solution();

	return 0;
}