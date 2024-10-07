#include <bits/stdc++.h>
using namespace std;

/*
	순서열 A -> <, > k개 나열
	부등호 기호 앞뒤에 숫자를 넣어서 부등호 관계를 만족하게 한다.
	0~9, 선택된 숫자는 모두 달라야한다.

	A ⇒ < < < > < < > < >
	3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
	3456128790

	5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
	5689023174

	최대값, 최소값을 찾는다.
	10C1, 9C1, ... 1C1 -> 10!
*/

int k;
vector<char> inputs;
int visited[14];
string done = "";
vector<string> resultStr;

void Go(int idx, int start)
{
	//cout << '\n' << "Go -> idx: " << idx << ", Start: " << start << ", Op: " << inputs[idx] << '\n';
	if (idx == k)
	{
		resultStr.push_back(done);

		return;
	}

	int next = -1;
	for (int i = 0; i < 10; i++)
	{
		if (visited[i] != 0)
			continue;
		next = i;

		if ((inputs[idx] == '<' && start < next) || (inputs[idx] == '>' && start > next))
		{
			//cout << "Next -> " << next << '\n';
			visited[i] = 1;
			done += to_string(i);
			//cout << "ADD -> " << done << '\n';
			idx++;

			Go(idx, i);

			idx--;
			done.pop_back();
			visited[i] = 0;
			//cout << "SUB -> " << done << '\n';
		}
	}
}

void Solution()
{
	for (int i = 0; i < 10; i++)
	{
		done.clear();
		done += to_string(i);
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;

		Go(0, i);
	}

	sort(resultStr.begin(), resultStr.end());

	cout << resultStr.back() << '\n';
	cout << resultStr[0] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char input;
		cin >> input;
		inputs.push_back(input);
	}

	Solution();

	return 0;
}