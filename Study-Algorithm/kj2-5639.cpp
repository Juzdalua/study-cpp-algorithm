#include <bits/stdc++.h>
using namespace std;

/*
	노드 왼쪽 서브트리에 있는 모든 노드의 키는 노드 키보다 작다.
	노드 오른쪽 서브트리에 있는 모든 노드의 키는 노드 키보다 크다.
	왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.

	전위 순회 결과는 50 30 24 5 28 45 98 52 60
	후위 순회 결과는 5 28 24 45 30 60 52 98 50

	전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램
*/

int MAX_COUNT = 10'000;
int head = 0;
vector<int> inputs;
unordered_map<int, pair<int, int>> m;


void Go(int parent, int num)
{
	// left
	if (num < parent)
	{
		if (m[parent].first == 0)
		{
			m[parent].first = num;
		}
		else
		{
			Go(m[parent].first, num);
		}
	}

	// right
	else
	{
		if (m[parent].second == 0)
		{
			m[parent].second = num;
		}
		else
		{
			Go(m[parent].second, num);
		}
	}
}

void postorder(int start)
{
	if (start == 0)
		return;

	postorder(m[start].first);
	postorder(m[start].second);
	cout << start << '\n';
}

void postorder(int startIdx, int endIdx)
{
	if (startIdx > endIdx)
		return;

	int parent = inputs[startIdx];

	int rightNodeIdx = startIdx + 1;
	while (rightNodeIdx <= endIdx && parent > inputs[rightNodeIdx])
		rightNodeIdx++;

	postorder(startIdx + 1, rightNodeIdx - 1);
	postorder(rightNodeIdx, endIdx);
	cout << inputs[startIdx] << '\n';
}

void Solution()
{
	head = inputs[0];

	for (int i = 1; i < inputs.size(); i++)
	{
		Go(head, inputs[i]);
	}

	postorder(head);

	/*for (auto& mm : m)
		cout << mm.first << " -> " << mm.second.first << ", " << mm.second.second << '\n';*/
}

void Solution2()
{
	postorder(0, inputs.size() - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	while (cin >> input)
	{
		inputs.push_back(input);
	}

	Solution2();

	return 0;
}