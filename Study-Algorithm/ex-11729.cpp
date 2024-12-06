#include <bits/stdc++.h>
using namespace std;

/*
	1���� 1�� �ű��
	2. �� ������ �Ʒ� ���Ǻ��� �۾ƾ��Ѵ�

	f(n) = 1 + 2 * f(n-1)
*/

int n, k, cnt;
vector<string> result;

void hanoi(int num, int from, int temp, int to)
{
	if (num == 1)
	{
		cnt++;
		string res = to_string(from);
		res.push_back(' ');
		res.push_back(to_string(to)[0]);
		result.push_back(res);
		//cout << from << " " << to << '\n';
		return;
	}

	hanoi(num - 1, from, to, temp);
	cnt++;

	string res = to_string(from);
	res.push_back(' ');
	res.push_back(to_string(to)[0]);
	result.push_back(res);
	//cout << from << " " << to << '\n';
	
	hanoi(num - 1, temp, from, to);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	hanoi(n, 1, 2, 3);
	
	cout << cnt << '\n';
	for (string& s : result)
		cout << s << '\n';

	return 0;
}