#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n = 1e5;
    vector<int> table(n + 1, true);
    table[0] = false; table[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!table[i]) continue;
        for (int j = 2 * i; j <= n; j += i) table[j] = false;
    }
    vector<int> num(n + 1);
    for (int i = 0; i <= n; i++) {
        if (table[i] && table[(i + 1) / 2]) num[i] = 1;
    }
    for (int i = 1; i <= 1e5; i++) num[i] += num[i - 1];
    
    int Q; cin >> Q;
    rep(i, Q) {
        int l, r;  cin >> l >> r;
        cout << num[r] - num[l - 1] << endl;
    }
}