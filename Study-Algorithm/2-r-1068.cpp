#include <bits/stdc++.h>
using namespace std;

/*
	������� = �ڽ��� ������ 0�� ���
	Ʈ������ ��带 �ϳ� �����.
	���� Ʈ������ ��������� ������ ���ؾ��Ѵ�.
	1 <= n <= 50
*/

int n, k;
vector<vector<int>> inputs;
int result = 0;
vector<int> removeIdx;

void PrintNode()
{
	for (int i = 0; i < inputs.size(); i++)
	{
		cout << "Node: " << i << " -> ";
		for (int j = 0; j < inputs[i].size(); j++)
		{
			cout << inputs[i][j] << " ";
		}
		cout << "\n";
	}
}

void DFS(int idx)
{
	removeIdx.push_back(idx);
	if (inputs[idx].size() > 0)
	{
		for (int& i : inputs[idx])
		{
			DFS(i);
		}
	}
}

void RemoveNode()
{
	// k -> ���� ���
	for (int i = 0; i < inputs.size(); i++)
	{
		auto it = find(inputs[i].begin(), inputs[i].end(), k);
		if (it != inputs[i].end())
		{
			inputs[i].erase(it);
			break;
		}
	}
	
	//PrintNode();
	DFS(k);
	//PrintNode();

	for (int i = 0; i < inputs.size(); i++)
	{
		if (inputs[i].size() != 0)
			continue;

		bool flag = true;
		for (int j = 0; j < removeIdx.size(); j++)
		{
			if (i == removeIdx[j])
			{
				flag = false;
				break;
			}
		}

		if (!flag)
			continue;

		result++;
	}
}

void Solution()
{
	//PrintNode();

	RemoveNode();
	/*if (inputs[k].size() == 0)
	{
		for (int i = 0; i < inputs.size(); i++)
		{
			if (inputs[i].size() == 0)
				result++;
		}
		result--;
	}
	else 
	{
		RemoveNode();
	}*/
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	inputs.resize(n);
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input == -1)
			continue;
		inputs[input].push_back(i);
	}
	cin >> k;

	Solution();

	return 0;
}