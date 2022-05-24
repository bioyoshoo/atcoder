#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);

    ll ans = 1e10;
    for (int i = 0; i < 10; i++) {
        map<int, int> mp;
        for (int j = 0; j < N; j++) {
            string s = S[j];
            for (int k = 0; k < 10; k++) {
                if (i == (int)(s[k] - '0')) mp[k] += 1;
            }
        }
        ll time = 0;
        for (auto m: mp) {
            ll t = 0;
            t += m.first;
            m.second--;
            if (m.second > 0) t += 10 * m.second;
            time = max(t, time);
        }
        if (time == 0) continue;
        ans = min(ans, time);
    }
    cout << ans << endl;
}