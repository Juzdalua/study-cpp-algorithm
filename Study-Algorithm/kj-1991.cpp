#include <bits/stdc++.h>
using namespace std;

/*
	전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
	중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
	후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
*/

int n;
int arr[30][30];
int visited[30][30];
vector<char> result;
int node[30][2];

void PrintArr()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void PrintTree()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Parent: " << i << '\n';
		for (int j = 0; j < 2; j++)
		{
			cout << node[i][j] << " ";
		}
		cout << '\n';
	}
}


void DFS(int y, int x)
{
	//cout << "START: (" << y << ", " << x << ") \n";
	if (visited[y][x] == 0)
	{
		visited[y][x] = 1;
		visited[x][y] = 1;

	}

	for (int i = 1; i < n; i++)
	{
		int nx = x + i;

		if (arr[y][nx] != 1 || visited[y][nx] == 1)
			continue;

		if (nx >= n || nx < 0)
			continue;

		visited[y][nx] = 1;
		visited[nx][y] = 1;
		result.push_back(static_cast<char>(nx + 65));
		DFS(nx, y);
	}
}

void preorder(int start)
{
	cout << static_cast<char>(start + 65);

	if (node[start][0] != 0)
		preorder(node[start][0]);

	if (node[start][1] != 0)
		preorder(node[start][1]);
}

void inorder(int start)
{
	if (node[start][0] != 0)
	{
		inorder(node[start][0]);
	}

	cout << static_cast<char>(start + 65);

	if (node[start][1] != 0)
	{
		inorder(node[start][1]);
	}
}

void postorder(int start)
{
	if (node[start][0] != 0)
	{
		postorder(node[start][0]);
	}

	if (node[start][1] != 0)
	{
		postorder(node[start][1]);
	}

	cout << static_cast<char>(start + 65);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char parent;
		char left;
		char right;

		cin >> parent >> left >> right;

		// . -> 46
		if (left != 46)
		{
			arr[parent - 65][left - 65] = 1;
			arr[left - 65][parent - 65] = 1;
			node[parent - 65][0] = left - 65;
		}

		if (right != 46)
		{
			arr[parent - 65][right - 65] = 1;
			arr[right - 65][parent - 65] = 1;
			node[parent - 65][1] = right- 65;
		}
	}

	//PrintArr();
	//PrintTree();

	/*{
		result.push_back(static_cast<char>(65));
		DFS(0, 0);
		for (char r : result)
			cout << r;
		cout << '\n';
	}*/

	preorder(0);
	cout << '\n';

	inorder(0);
	cout << '\n';

	postorder(0);
	cout << '\n';

	return 0;
}