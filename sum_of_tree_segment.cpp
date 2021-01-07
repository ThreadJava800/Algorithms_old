#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

uint64_t n;
vector<uint64_t> tree;

void put(int val1, int val2)
{
    val1 += n - 1;
    tree[val1] = val2;
    do
    {
        val1 /= 2;
        tree[val1] = tree[2 * val1] + tree[2 * val1 + 1];
    } while (val1 > 1);
}

uint64_t sum(int l, int r)
{
    uint64_t sum = 0;
    l += n - 1;
    r += n - 1;
    while (l <= r)
    {
        if (l % 2 != 0) sum += tree[l];
        if (r % 2 == 0) sum += tree[r];
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return sum;
}

void sum_of_segment() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    uint64_t a_size = n;
    n = 1 << (uint64_t)log2(n - 1) + 1;
    tree.resize(2 * n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < a_size; i++)
    {
        uint64_t temp;
        cin >> temp;
        put(i, temp);
    }
    // val1 is left index and val2 is right
    uint64_t val1, val2;
    cin >> val1 >> val2;
    cout << sum(val1, val2);
}