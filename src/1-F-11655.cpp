#include <bits/stdc++.h>
using namespace std;

/*
    ROT13 암호화
    알파벳을 13자리 밀어서 해쉬
    알파벳을 13자리 땡겨서 디코딩
    알파벳 대소문자 가능.
    'A' = 65, 'Z' = 90
    'a' = 97, 'z' = 122

    알파벳 아닌 문자열은 그대로
*/

vector<string> Split(const string &input, string delimiter)
{
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter, start);
    while (end != string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));

    return result;
}

void Solution(vector<string> &vec)
{
    string res;

    for (string &str : vec)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if ((ch >= 65 && ch <= 77) || ch >= 97 && ch <= 109)
            {
                res += ch + 13;
            }
            else if ((ch >= 78 && ch <= 90) || ch >= 110 && ch <= 122)
            {
                res += ch - 13;
            }
            else
            {
                res += ch;
            }
        }
        res += ' ';
    }
    
    cout << res.substr(0, res.size()-1) << endl;
}

string input;
int main()
{
    getline(cin, input);
    vector<string> split = Split(input, " ");
    Solution(split);

    return 0;
}