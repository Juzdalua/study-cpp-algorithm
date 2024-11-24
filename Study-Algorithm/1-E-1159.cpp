#include <bits/stdc++.h>
using namespace std;

/*
    선발명단
    성의 첫 글자가 같은 5명
    5 미만이면 기권

*/

string stop = "PREDAJA";
vector<string> names;

void Solution()
{
    sort(names.begin(), names.end());

    map<char, int> nameMap;
    for (int i = 97; i <= 122; i++)
    {
        nameMap[static_cast<char>(i)] = 0;
    }

    for (string &name : names)
    {
        char first = name.substr(0, 1)[0];
        nameMap[first]++;
    }

    string result;
    for(auto& pair : nameMap)
    {
        if(pair.second >= 5){
            result += pair.first;
        }
    }

    if(result.size() > 0)
    {
        cout << result << endl;
        return ;
    }
    cout << stop << endl;
    return;
}

int main()
{
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string name;
        cin >> name;
        names.push_back(name);
    }

    Solution();
    return 0;
}