#include <bits/stdc++.h>
using namespace std;

/*
	��Ϲ��� -  8�� ���, N or S��
	T���� �Ϸ�
	1��~T��

	��Ϲ����� �� K�� ȸ���Ѵ�
	�ð����, �ݽð����

	��Ϲ����� ȸ���� ��, �´��� ���� �ٸ��ٸ� �ݴ�������� ȸ���Ѵ�.
	������ ȸ������ �ʴ´�.

	�� K�� ȸ����Ų ���Ŀ� 12�ù����� S���� ��Ϲ����� ������ ����Ѵ�.

	12�ù������ �ð���� ������� �־�����.
	N���� 0, S���� 1
	ù ��° ������ ȸ����Ų ��Ϲ����� ��ȣ, �� ��° ������ ����
	������ 1�� ���� �ð� �����̰�, -1�� ���� �ݽð� ����
	1 �� T �� 1,000
	1 �� K �� 1,000

	������ index = 2
	���� index = 6
*/

int t, k;
vector<vector<int>> inputs;
vector<pair<int, int>> rotation;
int result = 0;

void Print()
{
	cout << '\n';
	for (int i = 0; i < t; i++)
	{
		cout << "Topni: " << i << '\n';
		for (int j = 0; j < inputs[i].size(); j++)
		{
			cout << inputs[i][j] << " ";
		}
		cout << "\n";
	}
}

void CalcResult()
{
	for (int i = 0; i < t; i++)
	{
		if (inputs[i][0] == 1)
			result++;
	}
}

void RotateTN(char move, int start, int num, int dir, vector<vector<int>>& arr)
{
	//cout << "RotateTN -> " << start << ", Num: " << num << ", Dir: " << dir << '\n';
	if (num < 0 || num >= inputs.size())
	{
		return;
	}

	// ����
	if (move == '0')
	{
		//cout << "RotateTN -> " << start << ", Num: " << num << ", Dir: " << dir << '\n';
		// �ð� ����
		if (dir == 1)
		{
			rotate(arr[num].begin(), arr[num].end() - 1, arr[num].end());
		}

		// �ݽð� ����
		else if (dir == -1)
		{
			rotate(arr[num].begin(), arr[num].begin() + 1, arr[num].end());
		}

		// �¿� 
		RotateTN('L', start, num - 1, -dir, arr);
		RotateTN('R', start, num + 1, -dir, arr);
	}

	// ���� ����
	else if (move == 'L')
	{
		if (inputs[num + 1][6] != inputs[num][2])
		{
			//cout << "RotateTN -> " << start << ", Num: " << num << ", Dir: " << dir << '\n';
			if (dir == 1)
				rotate(arr[num].begin(), arr[num].end() - 1, arr[num].end());

			else
				rotate(arr[num].begin(), arr[num].begin() + 1, arr[num].end());
			RotateTN('L', start, num - 1, -dir, arr);
		}
	}

	// ������ ����
	else if (move == 'R')
	{
		if (inputs[num - 1][2] != inputs[num][6])
		{
			//cout << "RotateTN -> " << start << ", Num: " << num << ", Dir: " << dir << '\n';
			if (dir == 1)
				rotate(arr[num].begin(), arr[num].end() - 1, arr[num].end());

			else
				rotate(arr[num].begin(), arr[num].begin() + 1, arr[num].end());
			RotateTN('R', start, num + 1, -dir, arr);
		}
	}
}

void SetTemp(vector<vector<int>>& temp)
{
	for (int i = 0; i < t; i++)
	{
		vector<int> a;
		for (int j = 0; j < 8; j++)
		{
			a.push_back(inputs[i][j]);
		}
		temp.push_back(a);
	}
}

void CopyTemp(vector<vector<int>>& temp)
{
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			inputs[i][j] = temp[i][j];
		}
	}
}

void Solution()
{
	for (pair<int, int>& r : rotation)
	{
		vector<vector<int>> temp;
		SetTemp(temp);

		int num = r.first;
		int dir = r.second;

		RotateTN('0', num, num, dir, temp);
		CopyTemp(temp);
		//Print();
	}

	CalcResult();
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	inputs.resize(t);
	for (int i = 0; i < t; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			inputs[i].push_back(input[j] - '0');
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;
		rotation.push_back({ input1 - 1, input2 });
	}

	Solution();

	return 0;
}