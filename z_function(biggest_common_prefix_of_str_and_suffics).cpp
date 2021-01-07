#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void z_func() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1;
    for (auto val : z_function(s1))
        cout << val << ' ';
}