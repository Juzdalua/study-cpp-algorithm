#include <bits/stdc++.h>
using namespace std;

/*
    크기 N * N 도시
    한칸 = 빈칸(0) / 집(1) / 치킨집(2)
    (r, c) r, c >= 1
    치킨거리 = 집과 가장 가까운 치킨집 사이의 거리
    각각 집은 치킨거리를 가지고 있다.
    도시의 치킨거리 = 모든 집의 치킨거리의 합
    (r1, c1) , (r2, c2) 의 거리 = |r1-r2| + |c1-c2|

    2 <= N <= 50, 1 <= M <= 13
    치킨집 최대 M개
    도시의 치킨거리 최소값 구하기
*/

int n, m;
int board[54][54];
vector<pair<int, int>> home;
vector<pair<int, int>> chickenHouse;
vector<vector<int>> chickenV;

void Combination(int start, vector<int> &v)
{
    if (v.size() == m)
    {
        chickenV.push_back(v);
        return;
    }

    for (int i = start + 1; i < chickenHouse.size(); i++)
    {
        v.push_back(i);
        Combination(i, v);
        v.pop_back();
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;

            if (input == 1)
                home.push_back(make_pair(i, j));
            else if (input == 2)
                chickenHouse.push_back(make_pair(i, j));
        }
    }

    // m개 치킨집 뽑기
    vector<int> v;
    Combination(-1, v);

    int result = 987654321;
    for (vector<int> &c : chickenV)
    {
        int minResult = 0;

        for (pair<int, int> &h : home)
        {
            int minLen = 987654321;
            for (int cIdx : c)
            {
                int chickenX, chickenY;
                tie(chickenX, chickenY) = chickenHouse[cIdx];

                int len = abs(h.first - chickenX) + abs(h.second - chickenY);
                minLen = min(len, minLen);
            }
            minResult += minLen;
        }
        result = min(result, minResult);
    }

    cout << result << '\n';

    return 0;
}