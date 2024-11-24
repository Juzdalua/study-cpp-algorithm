#include <bits/stdc++.h>
using namespace std;

/*
    알파벳 소문자 여러개, * 한개
    "a*d" = "abcd", "ad", "anestonestod"
*/

string yes = "DA";
string no = "NE";

vector<string> Split(const string& input, const string& delimiter)
{
    vector<string> result;

    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos)
    {
        result.push_back(input.substr(start, end-start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    
    return result;
}

void Solution(const string &pattern, vector<string> &input)
{
    // Set pattern
    // patternVec[0] * patternVec[1]
    vector<string> patternVec = Split(pattern, "*");
    reverse(patternVec[1].begin(), patternVec[1].end());

    for(string& s : input)
    {
        if(s.size() < pattern.size()-1)
        {
            cout << no << endl;
            continue;
        }

        string originalS = s;
        reverse(s.begin(), s.end());

        //cout << "START: " << patternVec[0] << " / " << originalS.substr(0, patternVec[0].size()) << ", END: " << patternVec[1] << " / " << s.substr(0, patternVec[1].size()) << endl;
        if(patternVec[0] == originalS.substr(0, patternVec[0].size()) && s.substr(0, patternVec[1].size()) == patternVec[1])
        {
            cout << yes << endl;
            continue;
        }
        cout << no << endl;
    }
}

int main()
{
    int count;
    cin >> count;

    string pattern;
    cin >> pattern;

    vector<string> input;
    for (int i = 0; i < count; i++)
    {
        string str;
        cin >> str;
        input.push_back(str);
    }

    Solution(pattern, input);

    return 0;
}