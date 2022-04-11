#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n), min_idx, max_idx;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.at(i) = a;
        if (a == x) max_idx.push_back(i);
        else if (a == y) min_idx.push_back(i);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        int max_border = *lower_bound(max_idx.begin(), max_idx.end(), i);
        int min_border = *lower_bound(min_idx.begin(), min_idx.end(), i);
        int border = max(max_border, min_border);
        ans += n - border;
    }

    cout << ans << endl;
}