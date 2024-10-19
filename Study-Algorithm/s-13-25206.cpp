#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double sum = 0;
	double hak = 0;
	for (int i = 0; i < 20; i++)
	{
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;

		if (s3 == "P")
		{
			continue;
		}

		else if (s3 == "A+")
		{
			sum += 4.5 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "A0")
		{
			sum += 4.0 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "B+")
		{
			sum += 3.5 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "B0")
		{
			sum += 3.0 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "C+")
		{
			sum += 2.5 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "C0")
		{
			sum += 2.0 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "D+")
		{
			sum += 1.5 * static_cast<double>(stoi(s2));
		}
		else if (s3 == "D0")
		{
			sum += 1.0 * static_cast<double>(stoi(s2));
		}
		hak += static_cast<double>(stoi(s2));
	}
	cout << sum / hak << '\n';

	return 0;
}