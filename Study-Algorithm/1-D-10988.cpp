#include <bits/stdc++.h>
using namespace std;

/*
    input -> string
    level, noon -> 1
    leved, noom -> 0
*/
string input;

void Solution()
{
    string reverseInput = input;
    reverse(input.begin(), input.end());

    if (input == reverseInput)
    {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
    return;
}

int main()
{
    cin >> input;
    Solution();
    return 0;
}