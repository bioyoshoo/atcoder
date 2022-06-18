#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;
    ll ans = 1;
    for (int i = 0; i < N; i++) ans *= 2;
    cout << ans << endl;
}