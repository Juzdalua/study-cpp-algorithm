#include <bits/stdc++.h>
using namespace std;

/*
    next_permutation(from, to): 오름차순으로 정렬된 순열 뽑기
    반드시 오름차순으로 정렬되어있어야 한다.
    
    from은 시작할 변수를 말한다.
    vector: vector.begin() / array: 0

    end는 마지막 변수를 포함하지 않는다. -> end는 마지막보다 1 크게
    vector: vector.end() / array: array.size()

    공식
    nPr -> n개중에 r개를 뽑는 경우의 수
    n! / (n-r)!
*/

int main()
{
    vector<int> v = {1,2,3};
    sort(v.begin(), v.end());
    do{
        for(int i : v) 
            cout << i << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}

/*
    1 2 3 
    1 3 2 
    2 1 3 
    2 3 1 
    3 1 2 
    3 2 1
*/