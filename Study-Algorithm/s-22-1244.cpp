#include <bits/stdc++.h>
using namespace std;

/*
	1부터 연속적으로 번호가 있는 스위치
	켜져있거나 꺼져있다.
	1: 켜짐, 0: 꺼짐

	학생들에게 1이상 스위치 갯수 이하인 자연수를 나눠준다.
	-남학생
		스위치 번호가 자기가 받은 수의 배수이면, 스위치의 상태를 바꾼다.
	3번 받음 -> 3, 6 바꾸기
	0	1	0	1	0	0	0	1
	0	1	1	1	0	1	0	1

	-여학생
		받은 번호의 수와 같은 스위치 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서
		그 구간 스위치의 상태를 모두 바꾼다.
		구간에 속한 스위치는 항상 홀수이다.
	3번 받음 -> 1~5 바꾸기
	0	1	1	1	0	1	0	1
	1	0	0	0	1	1	0	1

	입력으로 스위치들의 처음 상태가 주어지고, 각 학생의 성별과 받은 수가 주어진다.
	학생들은 입력되는 순서대로 자기의 성별과 받은 수에 따라 스위치의 상태를 바꾸었을 때,
	스위치들의 마지막 상태를 출력하는 프로그램을 작성하시오.

	스위치의 상태를 1번 스위치에서 시작하여 마지막 스위치까지 한 줄에 20개씩 출력한다.
	예를 들어 21번 스위치가 있다면 이 스위치의 상태는 둘째 줄 맨 앞에 출력한다.
	켜진 스위치는 1, 꺼진 스위치는 0으로 표시하고, 스위치 상태 사이에 빈칸을 하나씩 둔다.
	남학생은 1로, 여학생은 2
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

		// 남학생
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

		// 여학생
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