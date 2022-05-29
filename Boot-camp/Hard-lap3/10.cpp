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

    ll ans = 0, sum = 0;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && sum < K) {
            sum += A[right];
            right++;
        }
        if (sum >= K) ans += N - right + 1;
        if (left == right) right++;
        sum -= A[left];
    }
    cout << ans << endl;
}