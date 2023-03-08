#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    map<int, int> mp;

    rep(i, Q) {
        int n, x; cin >> n >> x;
        if (n == 1) {
            mp[x] += 1;
        }
        else if (n == 2) {
            mp[x] += 2;
        }
        else {
            if (mp[x] >= 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}