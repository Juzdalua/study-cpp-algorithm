#include <bits/stdc++.h>
using namespace std;

/*
	빈도 조사
	숫자 N개로 이루어진 수열
	숫자는 모두 C보다 작거나 같다.
	자주 등장하는 빈도대로 수를 정렬한다.
	
	빈도 정렬
	1. X가 Y보다 많이 등장하면 XY
	2. 빈도가 같다면, 먼저 나온게 먼저
	1 ≤ N ≤ 1,000,
	1 ≤ C ≤ 1,000,000,000 = 10억
*/

int n, c;
vector<int> arr;
unordered_map<int, pair<int, int>> arrMap;

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		if (arrMap.find(arr[i]) == arrMap.end())
			arrMap[arr[i]] = make_pair(1, i);
		else
			arrMap[arr[i]].first++;
	}
	
	vector<tuple<int, int, int>> v;
	for (auto& a : arrMap)
	{
		//cout << a.first << ": " << a.second.first << ", " << a.second.second << '\n';
		v.push_back(make_tuple(a.first, a.second.first, a.second.second));
	}

	// 숫자, 빈도, 인덱스
	sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
		if (get<1>(a) == get<1>(b))
			return get<2>(a) < get<2>(b);
		return get<1>(a) > get<1>(b);
		});
	 
	vector<int> result;
	for (auto& a : v)
	{
		//cout << get<0>(a) << ": " << get<1>(a) << ", " << get<2>(a) << '\n';
		for (int i = 0; i < get<1>(a); i++)
			result.push_back(get<0>(a));
	}

	for (int r : result)
		cout << r << " ";
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Solution();

	return 0;
}