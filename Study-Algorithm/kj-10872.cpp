#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	N(0 ¡Â N ¡Â 12)
*/

int n;

int Factorial(int x)
{
	int result = 1;
	for (int i = x; i >= 1; i--)
		result *= i;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << Factorial(n) << '\n';

	return 0;
}