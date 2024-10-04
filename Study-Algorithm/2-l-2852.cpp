#include <bits/stdc++.h>
using namespace std;

/*
	골이 들어갈 때 마다 골이 들어간 팀과 시간을 적는다.
	48분동안 경기 진행
	각 팀이 몇분동안 이기고 있는지 출력

	N(1<=N<=100)
	팀은 1과 2
	시간은 MM:SS
	00 <= MM <= 47
	00 <= SS <= 59
*/

const string START_TIME = "00:00";
const string END_TIME = "48:00";
int n;
vector<pair<int, string>> inputs;
string team1 = START_TIME;
string team2 = START_TIME;
int goal1 = 0;
int goal2 = 0;
int winTeam = 0;

string SubTime(string exTime, string curTime)
{
	string exMin = exTime.substr(0, exTime.find(":"));
	string exSec = exTime.substr(exTime.find(":") + 1);

	string curMin = curTime.substr(0, curTime.find(":"));
	string curSec = curTime.substr(curTime.find(":") + 1);

	int calcMin = stoi(curMin) - stoi(exMin);

	int calcSec = stoi(curSec) + 60 - stoi(exSec);
	if (calcSec >= 60)
	{
		calcSec -= 60;
	}
	else
	{
		calcMin -= 1;
	}

	string calcMinStr = to_string(calcMin);
	string calcSecStr = to_string(calcSec);

	if (calcMinStr.size() == 1)
		calcMinStr = "0" + calcMinStr;
	if (calcSecStr.size() == 1)
		calcSecStr = "0" + calcSecStr;

	return calcMinStr + ":" + calcSecStr;
}

string AddTime(string exTime, string curTime)
{
	string exMin = exTime.substr(0, exTime.find(":"));
	string exSec = exTime.substr(exTime.find(":") + 1);

	string curMin = curTime.substr(0, curTime.find(":"));
	string curSec = curTime.substr(curTime.find(":") + 1);

	int calcMin = stoi(curMin) + stoi(exMin);
	int calcSec = stoi(curSec) + stoi(exSec);
	if (calcSec >= 60)
	{
		calcSec -= 60;
		calcMin += 1;
	}

	string calcMinStr = to_string(calcMin);
	string calcSecStr = to_string(calcSec);

	if (calcMinStr.size() == 1)
		calcMinStr = "0" + calcMinStr;
	if (calcSecStr.size() == 1)
		calcSecStr = "0" + calcSecStr;

	return calcMinStr + ":" + calcSecStr;
}

void Solution()
{
	string winTime = "";

	for (auto& input : inputs)
	{
		if (input.first == 1)
			goal1++;
		else
			goal2++;
		
		if (winTeam == 0)
		{
			winTeam = goal1 > goal2 ? 1 : 2;
			winTime = input.second;
			continue;
		}

		if (goal1 > goal2)
			winTeam = 1;
		else if(goal1 < goal2)
			winTeam = 2;

		// 동점
		if (goal1 == goal2)
		{
			string calcTime = SubTime(winTime, input.second);
			
			if (winTeam == 1)
			{
				//cout << "Team1 -> Now: " << team1 << ", Calc: " << calcTime;
				team1 = AddTime(calcTime, team1);
				//cout << ", After: " << team1 << '\n';
			}
			else
			{
				//cout << "Team2 -> Now: " << team2 << ", Calc: " << calcTime;
				team2 = AddTime(calcTime, team2);
				//cout << ", After: " << team2 << '\n';
			}

			winTime = input.second;
			winTeam = 0;
		}
		
		// 1번 역전
		else if (goal1 > goal2)
		{

			
		}

		// 2번 역전
		else if (goal1 < goal2)
		{

		}
	}

	string calcTime = SubTime(winTime, END_TIME);

	//cout << "Last Win Team -> " << winTeam << '\n';
	if (winTeam == 1)
		team1 = AddTime(calcTime, team1);
	else if(winTeam == 2)
		team2 = AddTime(calcTime, team2);


	cout << team1 << '\n';
	cout << team2 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int team;
		string goalTime;
		cin >> team >> goalTime;

		inputs.push_back(make_pair(team, goalTime));
	}

	Solution();

	return 0;
}