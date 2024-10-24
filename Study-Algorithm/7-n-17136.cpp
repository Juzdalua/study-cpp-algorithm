#include <bits/stdc++.h>
using namespace std;

/*
	5종류의 색종이. 각각 5개씩 있다
	1*1 2*2 3*3 4*4 5*5

	10*10칸에 덮는다.
	1로 쓰여진 칸을 색종이로 덮어야한다
	경계 밖으로 나가게 붙일수없다
	겹쳐도 안된다
	칸의 경계와 일치하게 붙여야한다.
	0으로 쓰여진 칸은 붙이면 안된다.

	1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수
	불가능한 경우, -1 출력한다.
*/

int board[14][14];
int sak[6];
int minResult = INT_MAX;
vector<pair<int, int>> ones;
int total;

void Print(int arr[14][14])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

bool Done(int arr[14][14])
{
	for (pair<int, int>& o : ones)
	{
		if (arr[o.first][o.second] != 1)
			return false;
	}
	return true;
}

bool Check(int y, int x, int size, int arr[14][14])
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (arr[i][j] != 1)
				return false;
		}
	}
	return true;
}

void Paste(int y, int x, int size, int arr[14][14])
{
	bool flag = false;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			arr[i][j] = -1;
		}
	}
}

void Go(int idx, int left, int arr[14][14])
{
	//cout << '\n' << "Go -> " << idx << '\n';
	//Print(arr);
	//cout << '\n' << "Start -> " << idx << '\n';
	if (idx == ones.size() - 1)
	{
		if (arr[ones[idx].first][ones[idx].second] == 1 && sak[1] != 0)
		{
			sak[1]--;
			int sum = 0;
			for (int i = 1; i <= 5; i++)
				sum += sak[i];
			minResult = min(minResult, 25 - sum);
			sak[1]++;
		}
		return;
	}

	if (left == 0)
	{
		int sum = 0;
		for (int i = 1; i <= 5; i++)
			sum += sak[i];
		minResult = min(minResult, 25 - sum);
		return;
	}

	int y = ones[idx].first;
	int x = ones[idx].second;
	//cout << "(" << y << ", " << x << ") " << arr[y][x] << '\n';
	if (arr[y][x] != 1)
	{
		Go(idx + 1, left, arr);
		return;
	}

	//cout << '\n' << "Go -> " << idx << ", (" << y << ", " << x << "), Total: " << left << '\n';
	//Print(arr);

	int temp[14][14] = { 0 };
	memcpy(temp, arr, sizeof(temp));

	for (int i = 5; i >= 1; i--)
	{
		int size = i;
		int endy = y + size - 1;
		int endx = x + size - 1;

		//cout << "Next -> " << idx << ", Size: " << size << ", Sak: " << sak[size] << ", (" << y << ", " << x << ") -> ( " << endy << ", " << endx << ") ,Total: " << total << '\n';
		if (sak[size] == 0)
			continue;

		if (endy >= 10 || endx >= 10)
			continue;
		if (!Check(y, x, size, temp))
			continue;

		left -= size * size;
		sak[size]--;
		Paste(y, x, size, temp);

		Go(idx + 1, left, temp);

		sak[size]++;
		left += size * size;
		memcpy(temp, arr, sizeof(temp));
	}
}

void Solution()
{
	//cout << '\n' << "SIZE: " << ones.size() << ", Total: " << total << '\n';
	if (ones.size() == 0)
	{
		cout << 0 << '\n';
		exit(0);
	}

	Go(0, total, board);

	if (minResult == 0 || minResult == INT_MAX)
		minResult = -1;
	cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				ones.push_back({ i,j });
				total++;
			}
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		sak[i] = 5;
	}

	Solution();


	return 0;
}