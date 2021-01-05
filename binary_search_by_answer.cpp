#include <iostream>

using namespace std;


void binary_search_by_answer()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t1 = 0, t2 = 0, n = 0;
	cin >> t1 >> t2 >> n;
	int l = 0, r = n * (t1 + t2);
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		int am = m / t1 + m / t2;
		if (am < n) l = m;
		else r = m;
	}
	cout << r;
}