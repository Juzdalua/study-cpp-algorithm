#include <bits/stdc++.h>
using namespace std;

/*
	N개의 수를 다루는 통계학
	N 홀수
	산술평균 : N개의 수들의 합을 N으로 나눈 값
	중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	최빈값 : N개의 수들 중 가장 많이 나타나는 값
	범위 : N개의 수들 중 최댓값과 최솟값의 차이

	1 ≤ N ≤ 500,000
	입력되는 정수의 절댓값은 4,000을 넘지 않는다.
*/

using int64 = long long;

int64 n;
vector<int64> v;

struct CompareOp
{
	bool operator()(pair<int64, int64>& a, pair<int64, int64>& b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

bool Compare(pair<int64, int64>& a, pair<int64, int64>& b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int64 i = 0; i < n; i++)
	{
		int64 input;
		cin >> input;
		v.push_back(input);
	}

	// 1
	double sum = 0;
	for (int64& i : v)
		sum += i;
	sum /= static_cast<double>(n);

	string s = to_string(sum);
	auto find = s.find(".");
	if (find != string::npos)
	{
		int64 a = stoi(s.substr(find + 1, 1));
		if (a >= 5)
		{
			if (sum > 0)
				sum++;
			else if (sum < 0)
				sum--;
		}
	}
	cout << static_cast<int64>(sum) << '\n';

	// 2
	sort(v.begin(), v.end());
	cout << v[n / 2] << '\n';

	// 3
	map<int64, int64> m;
	for (int64& i : v)
		m[i]++;
	vector<pair<int64, int64>> vec = { m.begin(), m.end() };
	sort(vec.begin(), vec.end(), Compare);
	if (vec.size() == 1)
		cout << vec[0].first << '\n';
	else
	{
		if (vec[0].second == vec[1].second)
			cout << vec[1].first << '\n';
		else
			cout << vec[0].first << '\n';
	}

	// 4
	cout << v[n - 1] - v[0] << '\n';

	return 0;
}