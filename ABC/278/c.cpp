#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    map<int, map<int, int>> mp;
    rep(i, Q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            if (mp[a][b] == 0) mp[a][b] = 1;
        }
        else if (t == 2) {
            if (mp[a][b] == 1) mp[a][b] = 0;
        }
        else if (t == 3) {
            if ((mp[a][b] == 1) && (mp[b][a] == 1)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
