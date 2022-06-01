#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digit(ll n) {
    return to_string(n).size();
}

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll N; cin >> N;
        int keta = n_digit(N);
        ll ans = -1;
        
        // b: block length
        for (int b = 1; b <= keta + 1; b++) {
            if (keta % b != 0) continue;
            
            ll div = 1;
            for (int j = 0; j < b; j++) div *= 10;
            ll top_div = 1;
            for (int j = 0; j < keta / b - 1; j++) top_div *= div;
            ll top_block = N / top_div;

            // top_block
            ll cand = 0;
            for (int j = 0; j < keta / b; j++) {
                cand *= div;
                cand += top_block;
            }
            if (cand > N || b == keta) cand = -1;
            ans = max(ans, cand);
            // top_block - 1;
            ll next_block = top_block - 1;
            ll cand2 = 0;
            if (n_digit(next_block) == n_digit(top_block) && b != keta) {
                for (int j = 0; j < keta / b; j++) {
                    cand2 *= div;
                    cand2 += next_block;
                }
            }
            else {
                for (int j = 0; j < keta - 1; j++) {
                    cand2 *= 10;
                    cand2 += 9;
                }
            }
            ans = max(ans, cand2);
        }
        cout << ans << endl;
    }
}