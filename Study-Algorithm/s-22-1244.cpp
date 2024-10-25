#include <bits/stdc++.h>
using namespace std;

/*
	1���� ���������� ��ȣ�� �ִ� ����ġ
	�����ְų� �����ִ�.
	1: ����, 0: ����

	�л��鿡�� 1�̻� ����ġ ���� ������ �ڿ����� �����ش�.
	-���л�
		����ġ ��ȣ�� �ڱⰡ ���� ���� ����̸�, ����ġ�� ���¸� �ٲ۴�.
	3�� ���� -> 3, 6 �ٲٱ�
	0	1	0	1	0	0	0	1
	0	1	1	1	0	1	0	1

	-���л�
		���� ��ȣ�� ���� ���� ����ġ �߽����� �¿찡 ��Ī�̸鼭 ���� ���� ����ġ�� �����ϴ� ������ ã�Ƽ�
		�� ���� ����ġ�� ���¸� ��� �ٲ۴�.
		������ ���� ����ġ�� �׻� Ȧ���̴�.
	3�� ���� -> 1~5 �ٲٱ�
	0	1	1	1	0	1	0	1
	1	0	0	0	1	1	0	1

	�Է����� ����ġ���� ó�� ���°� �־�����, �� �л��� ������ ���� ���� �־�����.
	�л����� �ԷµǴ� ������� �ڱ��� ������ ���� ���� ���� ����ġ�� ���¸� �ٲپ��� ��,
	����ġ���� ������ ���¸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	����ġ�� ���¸� 1�� ����ġ���� �����Ͽ� ������ ����ġ���� �� �ٿ� 20���� ����Ѵ�.
	���� ��� 21�� ����ġ�� �ִٸ� �� ����ġ�� ���´� ��° �� �� �տ� ����Ѵ�.
	���� ����ġ�� 1, ���� ����ġ�� 0���� ǥ���ϰ�, ����ġ ���� ���̿� ��ĭ�� �ϳ��� �д�.
	���л��� 1��, ���л��� 2
*/

int n, m;
int arr[104];
vector<pair<int, int>> v;

void Print()
{
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	cout << '\n';
}

void PrintResult()
{
	int cnt = 0;
	if (n <= 20)
		cnt = 1;
	else if (n > 20)
	{
		if (n % 20 == 0)
			cnt = n / 20;
		else
			cnt = n / 20 + 1;
	}

	int number = 1;
	while (number <= cnt)
	{
		for (int i = (number - 1) * 20 + 1; i <= min(n, number * 20); i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		number++;
	}
}

void Switch(int i)
{
	if (arr[i] == 1)
		arr[i] = 0;
	else
		arr[i] = 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		v.push_back({ in1,in2 });
	}

	for (pair<int, int>& student : v)
	{
		int gender = student.first;
		int num = student.second;

		// ���л�
		if (gender == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				int next = i * num;
				if (next > n)
					break;
				Switch(next);
			}
			//Print();
		}

		// ���л�
		else if (gender == 2)
		{
			int mid = num;
			if (num == 1)
			{
				Switch(num);
			}
			else
			{
				int left = num - 1;
				int right = num + 1;

				while (true)
				{
					//cout << "Left -> " << left << ", Right -> " << right << '\n';
					if (left < 1 || right > n)
					{
						left++;
						right--;
						break;
					}

					if (arr[left] != arr[right])
					{
						left++;
						right--;
						break;
					}

					left--;
					right++;
				}
				//cout << "Left -> " << left << ", Right -> " << right << '\n';
				for (int i = left; i <= right; i++)
					Switch(i);
			}
			//Print();
		}
	}

	PrintResult();

	return 0;
}