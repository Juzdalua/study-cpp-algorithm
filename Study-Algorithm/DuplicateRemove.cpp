#include <bits/stdc++.h>
using namespace std;

vector<int> RemoveDuplicate(vector<int>& vec)
{
    map<int, int> dMap;
    for(int i : vec)
    {
        // if(dMap[i]) // dMap[i] = 0으로 할당. -> false
        //     continue;
        if(dMap.find(i) != dMap.end())
            continue;
        dMap[i] = i;
    }

    vector<int> result;
    for(auto iter : dMap)
        result.push_back(iter.second);

    return result;
}

int main()
{
    vector<int> v = {2,2,1,1,2,3,4,3,5};

    vector<int> newV = RemoveDuplicate(v);
    for(auto& res : newV)
    {
        cout << res << endl;
    }

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    for(int i : v) cout << i << ",";
    cout << endl;
    v = {2,2,1,1,2,3,4,3,5};
    /*
        sort(from, to) -> 오름차순 정렬
        vector.erase(from, to) -> from부터 to까지 요소 삭제
        unique(from, to) -> 중복 제거가 끝난 index 반환
    */
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i : v) cout << i << ",";
    cout << endl;

    return 0;
}