#include <bits/stdc++.h>
using namespace std;

/*
    영어이름: 대문자, 최대 50자
    팰린드롬 -> 이름 순서를 뒤바꿈
    좌우 대칭.
    답이 여러개면 사전순 1개 출력
*/
string no = "I'm Sorry Hansoo";

void Solution(string &input)
{
    map<char, int> inputMap;
    sort(input.begin(), input.end());

    for (int i = 0; i < input.size(); i++)
    {
        inputMap[input[i]]++;
    }

    vector<char> odd;
    for (auto &inputChar : inputMap)
    {
        if (inputChar.second & 1)
        {
            odd.push_back(inputChar.first);
        }
        if (odd.size() > 1)
        {
            cout << no << '\n';
            exit(0);
        }
    }

    string result;
    if (odd.size() > 0)
    {
        inputMap[odd[0]]--;
        result = odd[0];
    }
    else
    {
        result = "";
    }

    for (auto &inputChar : inputMap)
    {
        //cout << inputChar.first << " : " << inputChar.second << endl;
    }

    int i = 0;
    string end;
    for (auto &inputChar : inputMap)
    {
        if (inputChar.second != 0)
        {
            end += string(inputChar.second / 2, inputChar.first);
        }
        i++;
    }
    //cout << "END: " << end << endl;
    string start = end;
    reverse(end.begin(), end.end());

    cout << start + result + end << endl;
}

int main()
{
    string input;
    cin >> input;

    Solution(input);

    return 0;
}