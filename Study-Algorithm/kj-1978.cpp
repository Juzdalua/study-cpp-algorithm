#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	소수가 몇개인지 출력하라.
*/

int n;
vector<int> inputs;

bool CheckPrime(int num)
{
	if (num < 2)
		return false;

	int cnt = 0;
	for (int i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			cnt++;
		}

		if (cnt > 1)
			break;
	}
	if (cnt == 1)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		inputs.push_back(input);
	}

	int sum = 0;
	for (int i = 0; i < inputs.size(); i++)
	{
		if (CheckPrime(inputs[i]))
			sum++;
	}

	cout << sum << '\n';

	return 0;
}