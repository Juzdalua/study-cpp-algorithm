#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, s;
int arr[24];
int result;

void Go(int idx, int sum, int cnt) {
	if (idx == n) {
		if (sum == s && cnt > 0) {
			result++;
		}
		return;
	}
	Go(idx + 1, sum, cnt);
	Go(idx + 1, sum + arr[idx], cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Go(0, 0, 0);
	cout << result << '\n';


	return 0;
}