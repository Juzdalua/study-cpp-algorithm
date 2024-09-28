#include <bits/stdc++.h>
using namespace std;

/*
	�ҹ��ڷ� �̷���� �ܾ� N
	�Ʒ� �������� �����Ѵ�
	1. ���̰� ª�� �ͺ���
	2. ���̰� ������ ����������
	1 �� N �� 20,000
*/

int n;
vector<string> inputs;
vector<string> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		inputs.push_back(input);
	}

	sort(inputs.begin(), inputs.end(), [](string a, string b) {
		return a.size() < b.size();
		});

	vector<string> temp;
	vector<string> midResult;
	int checkSize = inputs[0].size();
	for (int i = 0; i < inputs.size(); i++)
	{
		if (inputs[i].size() == checkSize)
		{
			temp.push_back(inputs[i]);

			if (i == inputs.size() - 1)
			{
				sort(temp.begin(), temp.end());
				temp.erase(unique(temp.begin(), temp.end()), temp.end());
				for (auto& tt : temp)
					midResult.push_back(tt);
			}
		}
		else
		{
			checkSize = inputs[i].size();
			sort(temp.begin(), temp.end());
			temp.erase(unique(temp.begin(), temp.end()), temp.end());
			for (auto& tt : temp)
				midResult.push_back(tt);
			i -= 1;
			temp.clear();
		}
	}
	
	for (auto& mr : midResult)
	{
		cout << mr << '\n';
	}

	return 0;
}