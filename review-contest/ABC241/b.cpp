#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    map<int, int> mp;
    rep(i, N) {
        int a; cin >> a; mp[a] += 1;
    }

    rep(i, M) {
        int b; cin >> b;
        if (mp[b] > 0) mp[b] -= 1;
        else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}