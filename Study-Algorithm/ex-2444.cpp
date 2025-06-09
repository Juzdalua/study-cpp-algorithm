#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

const char star = '*';
const char space = ' ';
string s = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	cin >> input;
	int mid = input - 1;

	s = string(input * 2 - 1, space);
	s[mid] = '*';
	int before = mid - 1;
	int after = mid + 1;

	for (int i = 1; i <= input; i++) {
		std::cout << s << '\n';
		if (i == input) break;
		s[before] = star;
		s[after] = star;
		before--;
		after++;
	}

	before = 0;
	after = input * 2 - 2;
	s[before] = space;
	s[after] = space;

	for (int i = input; i > 1; i--) {
		std::cout << s << '\n';
		if (i == 1) break;
		before++;
		after--;
		s[before] = space;
		s[after] = space;
	}

	return 0;
}