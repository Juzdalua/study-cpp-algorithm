#include <bits/stdc++.h>
using namespace std;

/*

*/

int k, q, l, b, n, p;
int K, Q, L, B, N, P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> q >> l >> b >> n >> p;

	K = 1 - k;
	Q = 1 - q;
	L = 2 - l;
	B = 2 - b;
	N = 2 - n;
	P = 8 - p;
	cout << K << " " << Q << " " << L << " " << B << " " << N << " " << P << '\n';
 
	return 0;
}