#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ll mod = 1e9 + 7;
using mint = modint1000000007;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    mint Block = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) Block++;
        }
    }
    mint Block2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] < A[j]) Block2++;
        }
    }
    mint ans = 0;
    ans = K * Block + K * (K - 1) / 2 * Block2;
    cout << ans.val() << endl;
}