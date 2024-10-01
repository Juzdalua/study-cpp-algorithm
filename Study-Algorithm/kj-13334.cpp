#include <bits/stdc++.h>
using namespace std;

/*
	집과 사무실을 통근하는 사람 N명
	집과 사무실은 평행
	A의 집 또는 사무실의 위치가, B의 집 또는 사무실 위치와 같을 수 있다.
	철로의 길이 d
	(h, o) -> h:집, o:사무실

	d = 30
	L -> (10, 40)
	(h1, o1) = (5, 40),
	(h2, o2) = (35, 25),  -> 1
	(h3, o3) = (10, 20),  -> 1
	(h4, o4) = (10, 25),  -> 1
	(h5, o5) = (30, 50),
	(h6, o6) = (50, 60),
	(h7, o7) = (30, 25),  -> 1
	(h8, o8) = (80, 100)
	답은 4

	n (1 ≤ n ≤ 100,000)
	d (1 ≤ d ≤ 200,000,000) -> 10^8(1억)
*/

int n, d;
multimap<int, int> inputs;
vector<pair<int, int>> ho;
map<int, int> result;

void SetInput()
{
	for (pair<int, int> input : inputs)
	{
		if (abs(input.first - input.second) <= d)
			ho.push_back(input);
	}

	//for (auto r : ho)
		//cout << r.first << " " << r.second << '\n';
}

void Solution()
{
	SetInput();

	int startNum;
	for (int i = 0; i < ho.size(); i++)
	{
		startNum = ho[i].first;
		auto findResultKey = result.find(startNum);
		if (findResultKey == result.end() || (*findResultKey).second == 0)
		{
			int end = ho[i].first + d;
			for (int j = i; j < ho.size(); j++)
			{
				if (ho[j].second <= end)
					result[startNum]++;
			}
		}
	}

	int maxResult = 0;
	for (auto& r : result)
	{
		//cout << r.first << " " << r.second << '\n';
		maxResult = max(maxResult, r.second);
	}

	cout << maxResult << '\n';
}

void Solution2()
{
	SetInput();
	/*for (pair<int, int> input : inputs)
	{
		ho.push_back(input);
	}*/

	sort(ho.begin(), ho.end(), [](pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
		});

	int maxResult = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto& a : ho)
	{
		//cout << a.first << " " << a.second << '\n';

		int h = a.first;
		int o = a.second;

		//while (!pq.empty() && pq.top() < o - d)
		while (!pq.empty() && d < o - pq.top())
		{
			pq.pop();
		}

		pq.push(h);
		maxResult = max(maxResult, static_cast<int>(pq.size()));
		//cout << "size: " << pq.size() << '\n';
	}

	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;

		if (input1 <= input2)
			inputs.insert(make_pair(input1, input2));
		else
			inputs.insert(make_pair(input2, input1));
	}
	cin >> d;

	//Solution();
	Solution2();

	return 0;
}