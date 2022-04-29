#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1e5;
    vector<bool> table(n + 1, true);
    table[0] = false; table[1] = false;
    for (int a = 2; a <= n; a++) {
        if (!table[a]) continue;
        for (int b = 2 * a; b <= n; b += a) table[b] = false;
    }
    vector<int> num(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (table[i] && table[(i + 1) / 2]) num[i] = 1;
    }
    for (int i = 1; i <= n; i++) num[i] += num[i - 1];

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << num[r] - num[l - 1] << endl;
    }
}