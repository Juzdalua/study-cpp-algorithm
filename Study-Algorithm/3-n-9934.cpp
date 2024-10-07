#include <bits/stdc++.h>
using namespace std;

/*
	���̰� N�� ���� ����Ʈ��
	�� ��忡�� �� ���� ��ġ�� ������ ��ȣ
	���� ������ ������ ������ ��� ���� ���� �ڽİ� ������ �ڽ��� ���´�

	��� ������ ����, �� ������� ��ȣ�� ���̿� ���� ���Ҵ�

	1. ���� ó���� ����̴� Ʈ���� ��Ʈ�� �ִ� ���� �տ� ���ִ�.
	2. ���� ������ ���� �ڽĿ� �ִ� ������ ���� ���� �ʾҴٸ�, ���� �ڽ����� �̵��Ѵ�.
	3. ���� �ִ� ��尡 ���� �ڽ��� ������ ���� �ʰų� ���� �ڽĿ� �ִ� ������ �̹� ���ٸ�, ���� ��忡 �ִ� ������ ���� ���̿� ��ȣ�� ���´�.
	4. ���� ������ �̹� ���� �� �����̰�, ������ �ڽ��� ������ �ִ� ��쿡�� ������ �ڽ����� �̵��Ѵ�.
	5. ���� ������ ����, ������ �ڽĿ� �ִ� ������ ��� �湮�ߴٸ�, �θ� ���� �̵��Ѵ�.

	������ȸ
	K (1 �� K �� 10)

*/

int k, n;
vector<int> inputs;
vector<int> result[14];

void Go(int startIdx, int endIdx, int depth)
{
	if (startIdx > endIdx || depth > k)
		return;

	if (startIdx == endIdx)
	{
		result[depth].push_back(inputs[startIdx]);
		return;
	}

	int midIdx = (endIdx + startIdx) / 2;
	result[depth].push_back(inputs[midIdx]);

	Go(startIdx, midIdx - 1, depth + 1);
	Go(midIdx + 1, endIdx, depth + 1);
}

void Solution()
{
	Go(0, inputs.size() - 1, 1);
	for (int i = 1; i <= k; i++)
	{
		for (int& i : result[i])
		{
			cout << i << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	int input;

	n = pow(2, k) - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		inputs.push_back(input);
	}

	Solution();

	return 0;
}