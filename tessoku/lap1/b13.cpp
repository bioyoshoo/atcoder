#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    
    int R = 0;
    ll ans = 0, sum = 0;
    for (int L = 0; L < N; L++) {
        while (R < N && sum + A[R] <= K) {
            sum += A[R];
            R++;
        }
        ans += R - L;

        sum -= A[L];
    }

    cout << ans << endl;
}
