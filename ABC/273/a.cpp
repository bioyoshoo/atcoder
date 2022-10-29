#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll rec(ll k) {
    if (k == 0) return 1;
    return k * rec(k - 1);
}

int main() {
    ll N; cin >> N;

    cout << rec(N) << endl;
}