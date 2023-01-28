#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool is_prime(int n) {
    if (n < 2) return false;

    for (int a = 2; a * a <= n; a++) {
        if (n % a == 0) return false;
    }
    return true;
}

int main() {
    int Q; cin >> Q;
    vector<int> V(1e5 + 1);

    for (int x = 3; x <= 1e5; x += 2) {
        if (is_prime(x) && is_prime((x + 1) / 2)) V[x] = 1;
    }

    for (int i = 1; i <= 1e5; i++) V[i] += V[i - 1];

    rep(i, Q) {
        int L, R; cin >> L >> R;
        cout << V[R] - V[L - 1] << endl;
    }
}
