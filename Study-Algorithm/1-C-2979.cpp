#include <bits/stdc++.h>
using namespace std;
/*
    3대의 트럭
    주차하는데 드는 비용 알아보기

    1대 주차 -> 1분에 한대당 A원
    2대 주차 -> 1분에 한대당 B원
    3대 주차 -> 1분에 한대당 C원
    주차요금 구하기

    시각은 항상 "이상-미만" -> for문 
*/
vector<string> input;
vector<int> pay;
int parkCount[100] = {0};
int sum = 0;

vector<int> Split(const string &input, string delimiter)
{
    vector<int> result;

    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos)
    {
        result.push_back(stoi(input.substr(start, end - start)));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(stoi(input.substr(start)));

    return result;
}

void Solution()
{
    for(int i=1; i<100; i++)
    {
        if(parkCount[i] == 1)
        {
            sum += pay[0];
        }
        else if(parkCount[i] == 2)
        {
            sum += pay[1] * 2;
        }
        else if(parkCount[i] == 3)
        {
            sum += pay[2] * 3;
        }
    }
    cout << sum << endl;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        string inputVal;
        getline(cin, inputVal);
        input.push_back(inputVal);
    }

    pay = Split(input[0], " ");

    for (int i = 1; i < 4; i++)
    {
        int start = Split(input[i], " ")[0];
        int end = Split(input[i], " ")[1];

        for(int j=start; j<end; j++)
        {
            parkCount[j]++;
        }
    }

    Solution();

    return 0;
}