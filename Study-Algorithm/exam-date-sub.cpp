#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string date1 = "2024-12-23";
const string date2 = "2024-12-25";

vector<string> split(const string& s, const string& delimiter)
{
	vector<string> result;

	auto start = 0;
	auto end = s.find(delimiter);

	while (end != string::npos)
	{
		result.push_back(s.substr(start, end - start));
		start = end + delimiter.size();
		end = s.find(delimiter, start);
	}
	result.push_back(s.substr(start));

	return result;
}

bool IsYoon(int year, int month)
{
	if (month != 2) return false;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
	return false;
}

int daysInMonth(int year, int month)
{
	if (IsYoon(year, month)) return 29;
	return days[month - 1];
}

int daysFromStartOfYear(int year, int month, int day)
{
	int totalDays = 0;
	for (int m = 1; m < month; m++)
		totalDays += daysInMonth(year, m);
	totalDays += day;
	return totalDays;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> s1 = split(date1, "-");
	int year1 = stoi(s1[0]);
	int month1 = stoi(s1[1]);
	int day1 = stoi(s1[2]);

	vector<string> s2 = split(date2, "-");
	int year2 = stoi(s2[0]);
	int month2 = stoi(s2[1]);
	int day2 = stoi(s2[2]);

	int result = 0;
	if (year1 == year2) result = abs(daysFromStartOfYear(year1, month1, day1) - daysFromStartOfYear(year2, month2, day2));



	cout << result << '\n';

	return 0;
}