#include <iostream>
#include <vector>

using namespace std;

void rmq()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	vector<uint64_t> a(n), logs(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	logs[1] = 0;
	for (int i = 2; i <= n; i++)
		logs[i] = logs[i / 2] + 1;
	// tree
	vector<vector<pair<int, int>>> t(logs[n] + 1, vector<pair<int, int>>(n));
	for (int i = 0; i < n; i++)
		t[0][i] = { a[i], i };
	for (int i = 1; (1 << i) <= n; i++)
	{
		for (int j = 0; j + (1 << i) <= n; j++)
		{
			if (t[i - 1][j].first > t[i - 1][j + (1 << (i - 1))].first)
				t[i][j] = t[i - 1][j];
			else t[i][j] = t[i - 1][j + (1 << (i - 1))];
		}
	}
	long long int l, r;
	cin >> l >> r;
	l--;
	r--;
	int level = logs[r - l + 1];
	if (t[level][l] > t[level][r - (1 << level) + 1])
		cout << t[level][l].first << ' ' << t[level][l].second + 1 << '\n'; // the biggest value and then its index
	else cout << t[level][r - (1 << level) + 1].first << ' ' << t[level][r - (1 << level) + 1].second + 1 << '\n';
}