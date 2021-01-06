#include <iostream>
#include <vector>
#include <string>

using namespace std;

void nop()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	vector<vector<int>> dp(s1.size(), vector<int>(s2.size()));
	for (int i = 1; i < s1.size(); ++i)
	{
		for (int j = 1; j < s2.size(); ++j)
		{
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = s1.size() - 1, j = s2.size() - 1;
	cout << dp[i][j] << '\n'; // biggest length
	vector<int> ans1, ans2;
	while (i > 0 && j > 0)
	{
		if (s1[i] == s2[j])
		{
			ans1.push_back(i);
			ans2.push_back(j);
			i--, j--;
		}
		else if (dp[i][j - 1] > dp[i - 1][j]) j--;
		else i--;
	}
	// substring indexes sorted by growth in the first word
	while (!ans1.empty())
	{
		cout << ans1.back() << ' ';
		ans1.pop_back();
	}
	cout << '\n';
	// substring indexes sorted by growth in the second word
	while (!ans2.empty())
	{
		cout << ans2.back() << ' ';
		ans2.pop_back();
	}
}