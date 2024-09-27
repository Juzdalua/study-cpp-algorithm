#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	90~100 => A
	80~89 => B
	70~79 => C
	60~69 => D
	~59 => F
*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string result;
	cin >> n;
	if (n >= 90)
		result = "A";
	else if (n >= 80)
		result = "B";
	else if (n >= 70)
		result = "C";
	else if (n >= 60)
		result = "D";
	else
		result = "F";
	cout << result << '\n';
	return 0;
}