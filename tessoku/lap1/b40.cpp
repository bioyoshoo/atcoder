#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    rep(i, N) {
        cin >> A[i];
        mp[A[i] % 100] += 1;
    }

    ll ans = 0;
    rep(i, N) {
        int mod = (100 - (A[i] % 100)) % 100;

        if (A[i] % 100 == mod) ans += mp[mod] - 1;
        else ans += mp[mod];
    }

    ans /= 2;
    cout << ans << endl;
}
