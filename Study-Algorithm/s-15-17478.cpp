#include <bits/stdc++.h>
using namespace std;

/*
	1 �� N �� 50

	"����Լ��� ������?"
	"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.
	���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.
	���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������."
	��� �亯�Ͽ���.
*/

int n;
const string s1 = "\"����Լ��� ������?\"";
const string s2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
const string s3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
const string s4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
const string s5 = "��� �亯�Ͽ���.";
const string s6 = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
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

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	Go(-1, "");

	return 0;
}