#include <bits/stdc++.h>
using namespace std;

/*
	1 ≤ N ≤ 50

	"재귀함수가 뭔가요?"
	"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
	마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
	그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."
	라고 답변하였지.
*/

int n;
const string s1 = "\"재귀함수가 뭔가요?\"";
const string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
const string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
const string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
const string s5 = "라고 답변하였지.";
const string s6 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
const string un = "____";

void Go(int count, string ss)
{
	if (count == n)
		return;

	if (count == n - 1)
	{
		cout << ss << s1 << '\n';
		cout << ss << s6 << '\n';
	}
	else
	{
		cout << ss << s1 << '\n';
		cout << ss << s2 << '\n';
		cout << ss << s3 << '\n';
		cout << ss << s4 << '\n';
	}

	Go(count + 1, ss + un);

	cout << ss << s5 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
	Go(-1, "");

	return 0;
}