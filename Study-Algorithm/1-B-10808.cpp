#include <bits/stdc++.h>
using namespace std;

/*
    알파벳 소문자로 이루어진 문자열 S
    각 알파벳이 단어에 몇개가 포함되어있는지
    a~z
*/

map<char, int> sMap;
void Solution(const string &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        auto it = sMap.find(input[i]);
        if(it != sMap.end())
        {
            sMap[input[i]]++;
        }
    }

    for(int i=97; i<=122; i++)
    {
        cout << sMap[i];
        if(i != 122)
            cout << " ";
    }
}

int main()
{
    string input;
    cin >> input;

    for(int i=97; i<=122; i++)
    {
        sMap[i] = 0;
    }

    Solution(input);

    return 0;
}