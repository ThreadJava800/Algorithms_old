#include <iostream>
#include <vector>

using namespace std;

void prefix_sum()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
	int n;
	cin >> n;
	uint64_t* values = new uint64_t[n];
	uint64_t* pref = new uint64_t[n];
	for (int i = 0; i < n; ++i)
		cin >> values[i];
	// setting things up
	pref[0] = values[0];
	for (int i = 1; i < n; i++)
		pref[i] = pref[i - 1] + values[i];
	// queries, infinite amount of calls
	// left is index of left border and right is an index of right border
	int left, right; 
	cin >> left >> right;
	if (left > 0) {
		cout << pref[right] - pref[left - 1];
	}
	else {
		cout << pref[right];
	}
}