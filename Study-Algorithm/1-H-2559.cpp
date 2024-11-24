#include <bits/stdc++.h>
using namespace std;

vector<string> Split(const string &input, const string &delimiter)
{
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

/*
    k = 2
    p[2]
    p[3] - p[1]
    p[4] - p[2]
    p[5] - p[3]
    p[n] - p[n-k]
*/
void Solution(int n, int k, vector<string> &dayVec)
{
    reverse(dayVec.begin(), dayVec.end());
    dayVec.push_back("0");
    reverse(dayVec.begin(), dayVec.end());

    vector<int> psum;
    psum.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        psum.push_back(psum[i - 1] + stoi(dayVec[i]));
    }

    if (k == n)
    {
        cout << psum[n] << endl;
        exit(0);
    }

    vector<int> result;
    for (int i = k; i <= n; i++)
    {
        result.push_back(psum[i] - psum[i - k]);
    }

    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());
    cout << result[0] << endl;
}

int main()
{
    string input;
    getline(cin, input);

    vector<string> inputVec = Split(input, " ");
    int n = stoi(inputVec[0]); // 온도를 측정한 전체 날 수
    int k = stoi(inputVec[1]); // 합을 구하기 위한 연속적인 날의 수

    string days;
    getline(cin, days);
    vector<string> dayVec = Split(days, " ");

    Solution(n, k, dayVec);

    return 0;
}