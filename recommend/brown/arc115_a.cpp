#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> cnt(2, 0);
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        ll cnt_one = 0;
        for (int j = 0; j < M; j++) if (S[j] == '1') cnt_one++;
        cnt[cnt_one % 2]++;
    }
    ll ans = 1;
    ans = cnt[0] * cnt[1];
    cout << ans << endl;
}