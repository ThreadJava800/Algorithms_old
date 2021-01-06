#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nvp()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 0;
	cin >> n;
	vector<int> v(n), dp(n, 1);
	int mx = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (mx < dp[i]) mx = dp[i];
	}
	cout << mx << '\n'; // length of the biggest incr. subseq.
}