#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*

*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		cout << n << " * " << i << " = " << n * i << '\n';
	}

	return 0;
}