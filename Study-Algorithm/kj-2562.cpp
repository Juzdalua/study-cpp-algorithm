#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	9���� ��
	�ִ밪 ã��
	���° ������ ã��

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> data;
	int maxData = -1;
	for (int i = 0; i < 9; i++)
	{
		int input;
		cin >> input;
		data.push_back(input);
		maxData = max(input, maxData);
	}

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == maxData)
		{
			cout << maxData << '\n';
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}