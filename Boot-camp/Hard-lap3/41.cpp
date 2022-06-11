#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;

    ll n = 0;
    for (int i = 1; i <= N; i++) if (i % K == 0) n++;
    
    if (K % 2 == 1) cout << 1LL * n * n * n << endl;
    else {
        ll m = 0;
        for (int i = 1; i <= N; i++) if (i % K == K / 2) m++;
        cout << 1LL * n * n * n + m * m * m << endl;
    }
}