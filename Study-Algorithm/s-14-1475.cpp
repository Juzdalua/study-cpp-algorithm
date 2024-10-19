#include <bits/stdc++.h>
using namespace std;

/*
	�Ѽ�Ʈ 0~9���� �Ѱ���
	�ʿ��� ��Ʈ�� ���� �ּҰ�
	6->9�� 9->6���� ��� ����
	
	1 <= N <= 1,000,000
*/

string n;
map<int, int> m;
int cnt;

void SetArr()
{
	cnt++;
	for (int i = 0; i < 10; i++)
	{
		m[i]++;
	}
}

bool Check(int a)
{
	if (m[a] != 0)
	{
		m[a]--;
		return true;
	}
	else if (a == 6)
	{
		if (m[9] != 0)
		{
			m[9]--;
			return true;
		}
		return false;
	}
	else if (a == 9)
	{
		if (m[6] != 0)
		{
			m[6]--;
			return true;
		}
		return false;
	}
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	SetArr();
	for (int i = 0; i < n.size(); i++)
	{
		int num = n[i] - '0';
		//cout << num << '\n';

		if (!Check(num))
		{
			SetArr();
			Check(num);
		}
	}

	cout << cnt << '\n';

	return 0;
}