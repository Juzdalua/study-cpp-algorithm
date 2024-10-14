#include <bits/stdc++.h>
using namespace std;

/*
	R * C
	ĭ���� �� �ִ� 1����
	���� ũ��, �ӵ�(ĭ/��)

	4*6 �ǿ���
	(0,-1) ���� -> (0,7) ���� �̵��� �����.

	������ ���� �Ͼ�� �����̴�
	1. ���������� ��ĭ �̵��Ѵ�.
	2. ���� �ִ� ��� ��, ���� ���� ����� �� ��´�. (���� ���� 0)
	3. ���� ���� �������, �� �̵��Ѵ�.

	�� �̵��ϴ� ĭ�� �������� �Ѿ�� �ݴ�������� �̵��Ѵ�.
	�� ĭ�� �� �θ��� �̻� �����ϸ�, ũ�Ⱑ ���� ū �� ��� �� ��ƸԴ´�.

	���ÿ��� ���� ����� ũ�� ���� ���϶�.

	2 �� R, C �� 100,
	0 �� M �� R��C (����� �� M) 10'000 -> 10^4

	r, c, s, d, z
	1 �� r �� R,
	1 �� c �� C,
	0 �� s �� 1000, (�ӷ�)
	1 �� d �� 4, (�̵�����) -> 1-��, 2-�Ʒ�, 3-����, 4-��
	1 �� z �� 10000 (ũ��)
*/

int r, c, m;
bool visited[10'004] = { false }; // ���� ����
pair<int, int> pos[10'004];
tuple<int, int, long long> info[10'004]; // ����, �ӷ�, ũ��
long long sum;

bool CompareShark(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

void PrintShark()
{
	for (int i = 0; i < m; i++)
	{
		cout << "i: " << i << ", Visited: " << visited[i] << ", (" << pos[i].first << ", " << pos[i].second << ")" << '\n';
	}
	cout << '\n';
}

void Go(int count)
{
	if (count >= c)
	{
		return;
	}

	// ���ÿ� �̵�
	int location = count + 1;
	int sharkRow = INT_MAX;

	for (int i = 0; i < m; i++)
	{
		if (visited[i])
			continue;

		if (pos[i].second != location)
			continue;

		sharkRow = min(sharkRow, pos[i].first);
	}

	int sharkNum = -1;
	if (sharkRow != INT_MAX)
	{
		for (int i = 0; i < m; i++)
		{
			if (pos[i].first == sharkRow && pos[i].second == location)
			{
				sharkNum = i;
				break;
			}
		}
	}

	// ����
	if (sharkRow != -1 && sharkNum != -1)
	{
		visited[sharkNum] = true;
		sum += get<2>(info[sharkNum]);
		pos[sharkNum] = { -1,-1 };
		//cout << "Fish -> Count: " << count + 1 << ", i: " << sharkNum << ", Add: " << get<2>(info[sharkNum]) << '\n';
	}

	// ��� �̵�
	map<pair<int, int>, vector<pair<int, int>>> temp;
	for (int i = 0; i < m; i++)
	{
		if (visited[i])
			continue;

		int& dir = get<0>(info[i]);
		int velocity = get<1>(info[i]);
		int y, x;
		tie(y, x) = pos[i];
		int ny = y;
		int nx = x;

		if (dir == 1)
		{
			int left = y;
			if (left > velocity)
			{
				ny -= velocity;
			}
			else
			{
				ny = 0;
				velocity -= left;
				dir = 2;

				left = r - 1;
				if (left > velocity)
				{
					ny += velocity;
				}
				else
				{
					ny += r - 1;
					velocity -= r - 1;
					dir = 1;
					ny -= velocity;
				}
			}
		}
		else if (dir == 2)
		{
			int left = (r - 1) - y;
			if (left > velocity)
			{
				ny += velocity;
			}
			else
			{
				ny += left;
				velocity -= left;
				dir = 1;
				ny -= velocity;
				if (ny < 0)
				{
					dir = 2;
					ny *= -1;
				}
			}
		}
		else if (dir == 3)
		{
			int left = (c - 1) - x;
			if (left > velocity)
			{
				nx += velocity;
			}
			else
			{
				nx += left;
				velocity -= left;
				dir = 4;
				nx -= velocity;
				if (nx < 0)
				{
					dir = 3;
					nx *= -1;
				}
			}
		}
		else if (dir == 4)
		{
			int left = x;
			if (left > velocity)
			{
				nx -= velocity;
			}
			else
			{
				nx = 0;
				velocity -= left;
				dir = 3;

				left = c - 1;
				if (left > velocity)
				{
					nx += velocity;
				}
				else
				{
					nx += c - 1;
					velocity -= c - 1;
					dir = 4;
					nx -= velocity;
				}
			}
		}

		//while (velocity--)
		//{
		//	switch (dir)
		//	{
		//		// ��
		//	case 1:
		//		ny -= 1;
		//		break;

		//		// �Ʒ�
		//	case 2:
		//		ny += 1;
		//		break;

		//		// ����
		//	case 3:
		//		nx += 1;
		//		break;

		//		// ��
		//	case 4:
		//		nx -= 1;
		//		break;

		//	default:
		//		break;
		//	}

		//	// ���� ��ȯ üũ
		//	if (ny >= r || nx >= c || ny < 0 || nx < 0)
		//	{
		//		if (dir == 1)
		//		{
		//			dir = 2;
		//			ny += 2;
		//		}
		//		else if (dir == 2)
		//		{
		//			dir = 1;
		//			ny -= 2;
		//		}
		//		else if (dir == 3)
		//		{
		//			dir = 4;
		//			nx -= 2;
		//		}
		//		else if (dir == 4)
		//		{
		//			dir = 3;
		//			nx += 2;
		//		}
		//	}
		//}
		//
		pos[i] = { ny, nx };
		temp[{ny, nx}].push_back({ get<2>(info[i]), i });
	}

	// ��� ��ƸԱ�
	
	for (auto& t : temp)
	{
		if (t.second.size() <= 1)
			continue;

		sort(t.second.begin(), t.second.end());
		for (int i = 0; i < t.second.size(); i++)
		{
			if (i != t.second.size() - 1)
			{
				int idx = t.second[i].second;
				visited[idx] = true;
				pos[idx] = { -1, -1 };
			}
		}
	}

	/*for (int i = 0; i < m - 1; i++)
	{
		if (visited[i])
			continue;
		for (int j = i + 1;j < m; j++)
		{
			if (visited[j])
				continue;

			if (pos[i] == pos[j])
			{
				if (get<2>(info[i]) > get<2>(info[j]))
				{
					visited[j] = true;
					pos[j] = { -1, -1 };
				}
				else
				{
					visited[i] = true;
					pos[i] = { -1, -1 };
					break;
				}
			}
		}
	}*/
	//PrintShark();
	Go(count + 1);
}

void Solution()
{
	//PrintShark();
	Go(-1);
	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> m;
	for (int i = 0; i < m; i++)
	{
		int in1, in2, in3, in4;
		long long in5;
		cin >> in1 >> in2 >> in3 >> in4 >> in5;

		pos[i] = { in1 - 1, in2 - 1 };

		if (in4 == 1 || in4 == 2)
			in3 = in3 % ((r - 1) * 2);
		else
			in3 = in3 % ((c - 1) * 2);

		info[i] = { in4, in3, in5 };
	}

	Solution();

	return 0;
}