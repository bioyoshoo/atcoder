#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<pair<ll, int>> B(N);
    rep(i, N) B[i] = {A[i], i};
    
    sort(B.begin(), B.end());

    ll cnt = 0, sub = 0;
    rep(i, N) {
        ll a; int idx; tie(a, idx) = B[i];
        a -= sub;
        // まだ食える
        if (cnt + a * (N - i) <= K) {
            cnt += a * (N - i);
            sub += a;
            A[idx] = 0;
        }
        // もう食えない
        // 周回の途中で止まる
        else {
            for (int j = 0; j < N; j++) {
                if (A[j] == 0) continue;
                if (cnt + a <= K) {
                    cnt += a;
                    A[j] -= a;
                }
                else {
                    A[j] = a - (K - cnt);
                    goto OUT;
                }
            }
        }
    }

OUT:
    rep(i, N) cout << A[i] << " ";
    cout << endl;
}
