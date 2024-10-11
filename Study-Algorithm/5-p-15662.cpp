#include <bits/stdc++.h>
using namespace std;

/*
	톱니바퀴 -  8개 톱니, N or S극
	T개가 일렬
	1번~T번

	톱니바퀴를 총 K번 회전한다
	시계방향, 반시계방향

	톱니바퀴를 회전할 때, 맞닿은 극이 다르다면 반대방향으로 회전한다.
	같으면 회전하지 않는다.

	총 K번 회전시킨 이후에 12시방향이 S극인 톱니바퀴의 개수를 출력한다.

	12시방향부터 시계방향 순서대로 주어진다.
	N극은 0, S극은 1
	첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향
	방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향
	1 ≤ T ≤ 1,000
	1 ≤ K ≤ 1,000

	오른쪽 index = 2
	왼쪽 index = 6
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

	// 시작
	if (move == '0')
	{
		//cout << "RotateTN -> " << start << ", Num: " << num << ", Dir: " << dir << '\n';
		// 시계 방향
		if (dir == 1)
		{
			rotate(arr[num].begin(), arr[num].end() - 1, arr[num].end());
		}

		// 반시계 방향
		else if (dir == -1)
		{
			rotate(arr[num].begin(), arr[num].begin() + 1, arr[num].end());
		}

		// 좌우 
		RotateTN('L', start, num - 1, -dir, arr);
		RotateTN('R', start, num + 1, -dir, arr);
	}

	// 왼쪽 진행
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

	// 오른쪽 진행
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