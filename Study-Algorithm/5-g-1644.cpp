#include <bits/stdc++.h>
using namespace std;

/*
	하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수
	3 : 3 (한 가지)
	41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
	53 : 5+7+11+13+17 = 53 (두 가지)

	20 : 7+13 -> 연속 없음
	20 : 3+5+5+7 -> 중복사용

	이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램
	(1 ≤ N ≤ 4,000,000) 4*10^5
*/

int n;
vector<int> primeNum;
queue<int> primeQ;
int sum = 0;
int result = 0;
bool che[4'000'004];

bool IsPrime(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void Era()
{
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) 
			continue;
		
		for (int j = i * 2; j <= n; j += i)
		{
			che[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if(!che[i])
			primeNum.push_back(i);
	}
}

void Go(int idx)
{
	if (idx >= primeNum.size())
		return;

	//if (idx == primeNum.size() - 1)
	//{
	//	result++;
	//	return;
	//}

	int sum = 0;
	for (int i = idx; i < primeNum.size(); i++)
	{
		sum += primeNum[i];
		if (sum == n)
		{
			result++;
			return;
		}

		else if (sum > n)
		{
			return;
		}
	}
}

void GoQ(int start)
{
	if (start == n)
	{
		result++;
		return;
	}
	
	queue<int> temp = primeQ;
	int sum = start;
	//cout << "Current Pop: " << start << '\n';
	
	while(!temp.empty())
	{
		//cout << "Current Pop: " << temp.front() << '\n';
		int now = temp.front();
		sum += now;
		temp.pop();

		if (sum == n)
		{
			//cout << "Now: "<< now << ", Sum: " << sum << ", N: " << n << '\n';
			result++;
			return;
		}

		else if (sum > n)
		{
			return;
		}
	}
}

void Solution()
{
	//for (int i = 1; i <= n; i++)
	//{
	//	if (IsPrime(i))
	//	{
	//		//primeNum.push_back(i);
	//		primeQ.push(i);
	//	}
	//}
	Era();

	/*for (int& p : primeNum)
		cout << p << " ";
	cout << '\n';*/

	for (int i = 0; i < primeNum.size(); i++)
	{
		Go(i);
	}

	/*while (!primeQ.empty())
	{
		int now = primeQ.front();
		primeQ.pop();
		GoQ(now);
	}*/

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Solution();

	return 0;
}