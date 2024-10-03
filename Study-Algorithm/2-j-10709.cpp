#include <bits/stdc++.h>
using namespace std;

/*
	JOI 시
	가로 W, 세로 H
	가로세로 1인 H * W 구역

	구역마다 구름이 있거나 없다
	구름은 1분마다 동쪽으로 1 이동

	구름이 있으면 c, 없으면 .
	구름이 뜨지 않으면 -1,
	처음부터 떠있으면 0

	각 구역에 몇분 뒤 구름이 처음 오는지 구하라

	1 ≦ H ≦ 100,
	1 ≦ W ≦ 100
*/

int h, w;
char sky[104][104];
int result[104][104];

void Solution()
{
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << sky[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < h; i++)
	{
		int c = -1;
		for (int j = 0; j < w; j++)
		{
			if (sky[i][j] == '.')
			{
				if (c == -1)
					result[i][j] = -1;
				else
				{
					c++;
					result[i][j] = c;
				}
			}
			else {
				c = 0;
				result[i][j] = c;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> sky[i][j];
		}
	}

	Solution();

	return 0;
}