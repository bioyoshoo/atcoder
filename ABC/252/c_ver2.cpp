#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);

    ll ans = 1e10;
    for (int n = 0; n <= 9; n++) {
        map<char, int> mp;
        for (int i = 0; i < N; i++) {
            string s = S[i];
            for (int j = 0; j < 10; j++) {
                if (s[j] == (char)(n + '0')) mp[j]++;
            }
        }
        ll cand = 0;
        for (auto m: mp) {
            ll time = 0;
            ll t = m.first, num = m.second;
            time += t;
            num--;
            if (num > 0) time += 10 * num;
            cand = max(cand, time);
        }
        ans = min(ans, cand);
    }
    cout << ans << endl;
}