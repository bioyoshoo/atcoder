#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    ll K; cin >> K;
    int N = S.size();
    rep(i, N) {
        int to_a = (26 - (int)(S[i] - 'a')) % 26;
        if (to_a <= K) {
            S[i] = 'a';
            K -= to_a;
        }
        if (K <= 0) break;
    }
    if (K > 0) {
        K %= 26;
        S[N - 1] = (char)(S[N - 1] + K);
    }
    cout << S << endl;
}