#include <bits/stdc++.h>
using namespace std;

/*
	깊이가 N인 완전 이진트리
	각 노드에는 그 곳에 위치한 빌딩의 번호
	가장 마지막 레벨을 제외한 모든 집은 왼쪽 자식과 오른쪽 자식을 갖는다

	모든 빌딩에 들어갔고, 들어간 순서대로 번호를 종이에 적어 놓았다

	1. 가장 처음에 상근이는 트리의 루트에 있는 빌딩 앞에 서있다.
	2. 현재 빌딩의 왼쪽 자식에 있는 빌딩에 아직 들어가지 않았다면, 왼쪽 자식으로 이동한다.
	3. 현재 있는 노드가 왼쪽 자식을 가지고 있지 않거나 왼쪽 자식에 있는 빌딩을 이미 들어갔다면, 현재 노드에 있는 빌딩을 들어가고 종이에 번호를 적는다.
	4. 현재 빌딩을 이미 들어갔다 온 상태이고, 오른쪽 자식을 가지고 있는 경우에는 오른쪽 자식으로 이동한다.
	5. 현재 빌딩과 왼쪽, 오른쪽 자식에 있는 빌딩을 모두 방문했다면, 부모 노드로 이동한다.

	중위순회
	K (1 ≤ K ≤ 10)

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