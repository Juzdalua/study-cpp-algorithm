#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

/*
	양의 정수 N = 이진갭 길이
	9 = 1001 = 2
	529 = 10 0001 0001 = 4
	20 = 1 0100 = 1
	15 = 1111 => 0
	32 = 100000 => 0
	1041 = 10000010001 => 5
	63 = 111111 => 0

	가장 긴 이진갭 출력
	이진갭 -> 양쪽이 1로 둘러 쌓인 0의 갯수

	1. 이진수로 변환하기
	2. 최대 이진갭 구하기
*/
const long long MAX = 2'147'483'647;

string ToBinary(int n)
{
	string str = "";
	while (true)
	{
		if (n == 1)
		{
			str += "1";
			break;
		}

		if (n % 2 == 0)
		{
			str += "0";
		}
		else
		{
			str += "1";
		}
		n = n / 2;
	}

	reverse(str.begin(), str.end());
	return str;
}

int Solve(string result)
{
	vector<long long> dp(result.size());
	for (int i = 0; i < dp.size(); i++)
		dp[i] = -1;
	long long sum = 0;

	for (int i = 0; i < result.size() - 1; i++)
	{
		for (int j = i + 1; j < result.size(); j++)
		{
			if (result[i] == '0')
				break;

			if (result[j] == '1')
			{
				dp[i] = sum;
				sum = 0;
				break;
			}
			else
			{
				sum++;
			}
		}
	}

	long long maxSum = 0;
	for (int i = 0; i < result.size(); i++)
	{
		maxSum = max(maxSum, dp[i]);
	}

	return maxSum;
}

int solution(int N) {
	string result = ToBinary(N);
	return Solve(result);
}