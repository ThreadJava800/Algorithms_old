#include <iostream>
#include <vector>

using namespace std;


// & передает только элементы за 1 времени, в ином случае масссивы будут копироваться
int bin(vector<int>& a, int key)
{
	// int l = 0, r = a.size() - 1;
	int l = -1, r = a.size();
	while (r - l > 1)
	{
		// int m = l + (r - l) * (key - a[l]) / (a[r] - a[l]);
		int m = (l + r) / 2;
		if (a[m] < key) l = m;
		else r = m;
	}
	if (r != a.size() && a[r] == key) return r;
	return -1;
}

void binary_search()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
	{
		int key = 0;
		cin >> key;
		if (bin(a, key) >= 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}