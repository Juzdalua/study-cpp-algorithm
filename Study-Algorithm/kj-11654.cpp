#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	소문자, 대문자, 0~9
*/

char n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << static_cast<int>(n);

	return 0;
}