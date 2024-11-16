#include <bits/stdc++.h>
using namespace std;

/*
	최대값 m
	점수 / m*100

	0 <= n <= 1000

*/

int n;
double arr[1004];
double m = INT_MIN;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		m = max(m, arr[i]);
	}

	double sum = 0.0f;
	for (int i = 0; i < n; i++)
	{
		double jumsu = arr[i] / m * 100.0f;
		sum += jumsu;
	}

	cout << sum / static_cast<double>(n) << '\n';

	return 0;
}