#include <bits/stdc++.h>
using namespace std;

/*
    모든 글자가 A, B로 바뀜
    좋은 단어 세어보기
    A, B끼리 쌍을 지어보았다
    선끼리 교차하지 않으면 좋은 단어
    단어의 수, 1 <= N <= 100
    단어 길이, 2 <= input <= 100'000
    모든 단어 길이의 합, 2 <= total <= 1'000'000
*/

void Solution(vector<string> &words)
{
    int cnt = 0;

    for (int i = 0; i < words.size(); i++)
    {
        vector<char> temp;

        for (int j = 0; j < words[i].size(); j++)
        {   
            temp.push_back(words[i][j]);
            if(temp.size() > 1 && temp[temp.size()-1] == temp[temp.size() -2])
            {   
                temp.pop_back();
                temp.pop_back();
            }
        }
        if(temp.size() == 0)
            cnt++;
    }

    cout << cnt << '\n';
}

int main()
{
    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        words.push_back(input);
    }

    Solution(words);
    return 0;
}