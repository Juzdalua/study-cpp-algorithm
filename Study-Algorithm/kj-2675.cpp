#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
	문자열 S 입력
	각 문자를  R번 반복해서 P를 만든다.
*/

int t;
vector<string> inputs;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int inputInt;
		cin >> inputInt;

		string inputStr;
		cin >> inputStr;

		inputs.push_back(to_string(inputInt) + ":" + inputStr);
	}

	vector<string> result;
	for (auto& i : inputs)
	{
		int inputI = stoi(i.substr(0, i.find(":")));
		string inputS = i.substr(i.find(":") + 1);
		//cout << inputI << " "<<inputS << endl;

		string newStr = "";
		for (int i = 0; i < inputS.size(); i++)
		{
			newStr += string(inputI, inputS[i]);
		}
		result.push_back(newStr);
	}

	for (string& r : result)
	{
		/*if (r.size() > 20)
			r = r.substr(0, 20);*/
		cout << r << '\n';
	}

	return 0;
}