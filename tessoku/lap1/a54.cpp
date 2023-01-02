#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    map<string, int> mp;

    rep(i, Q) {
        int q; string x; cin >> q >> x;
        if (q == 1) {
            int y; cin >> y;
            mp[x] = y;
        }
        else if (q == 2) {
            cout << mp[x] << endl;
        }
    }
}
