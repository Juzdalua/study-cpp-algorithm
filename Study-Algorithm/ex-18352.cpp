#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m, k, x;
vector<int> arr[300'004];
int visited[300'004];

void BFS(int start) {
	visited[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		vector<int> nexts = arr[now];
		for (int next : nexts) {
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
	}
	BFS(x);

	vector<int> result;
	for (int i = 1; i <= n; i++) {
		//cout << "Visitied: " << i << " ->" << visited[i] << '\n';
		if (visited[i] == k) {
			result.push_back(i);
		}
	}
	if (result.size() == 0) cout << -1 << '\n';
	else {
		sort(result.begin(), result.end());
		for (int r : result) {
			cout << r << '\n';
		}
	}

	return 0;
}