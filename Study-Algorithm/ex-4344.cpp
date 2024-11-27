#include <bits/stdc++.h>
using namespace std;

/*
	
*/

int c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;

		double arr[1004];
		double avg = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			avg += arr[i];
		}
		avg /= n;
		
		double count = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > avg)
			{
				count++;
			}
		}
		
		cout << setprecision(5) << count / n * 100 << "%" << '\n';
	}

	return 0;
}