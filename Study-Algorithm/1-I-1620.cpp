#include <bits/stdc++.h>
using namespace std;

/*
    도감에 수록되어있는 포켓몬 수 N
    내가 맞춰야하는 문제의 갯수 M
    1<= N, M <=100'000 자연수

    N개의 포켓몬 이름 입력
    1~N 번호
    이름은 영어
    첫글자만 대문자, 나머지 소문자
    일부는 마지막 문자만 대문자
    2<= 이름 길이 <= 20

    M개의 맞춰야 하는 문제 입력
    알파벳 -> 번호 출력
    번호 -> 해당 포켓몬 이름 출력

*/

void Solution(int N, int M, map<int, string> &poketmonIds, map<string, int>& poketmonNames, vector<string> &question)
{
    for (int i = 0; i < M; i++)
    {
        if(isdigit(question[i][0]))
        {
            cout << poketmonIds[stoi(question[i]) - 1] << '\n';
        }
        else
        {
            cout << poketmonNames[question[i]] +1 << '\n';
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    map<int, string> poketmonIds;
    map<string, int> poketmonNames;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        poketmonIds[i] = input;
        poketmonNames[input] = i;
        
    }

    vector<string> question;
    for (int i = 0; i <M; i++)
    {
        string input;
        cin >> input;
        question.push_back(input);
    }

    Solution(N, M, poketmonIds, poketmonNames, question);
    return 0;
}