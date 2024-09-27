#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	정수 n개, n개의 합

*/

long long sum(vector<int>& a)
{
	long long result = 0;
	for (int r : a)
		result += r;
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	return 0;
}