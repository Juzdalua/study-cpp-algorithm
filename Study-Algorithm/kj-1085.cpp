#include <bits/stdc++.h>
using namespace std;

/*
	현재 (x,y)
	직사각형 왼쪽아래 (0,0) -> 오른쪽 위 (w,h)
	직사각형의 경계선까지 가는 최소거리

	1 ≤ w, h ≤ 1,000
	1 ≤ x ≤ w-1
	1 ≤ y ≤ h-1
	x, y, w, h는 정수
*/

int x, y, w, h;

void Solution()
{
	int minX = 0;
	int minY = 0;

	if (x > w / 2)
		minX = w - x;
	else
		minX = x;
	
	if (y > h / 2)
		minY = h - y;
	else
		minY = y;

	cout << min(minX, minY)<< '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> w >> h;

	Solution();

	return 0;
}