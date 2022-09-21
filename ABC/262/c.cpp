#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) {
        int a; cin >> a; a--;
        A[i] = a;
    }

    ll eq = 0, swp = 0;
    rep(i, N) {
        if (i == A[i]) eq++;
        else if (i == A[A[i]]) swp++;
    }
    swp /= 2;

    ll ans = (eq * (eq - 1)) / 2 + swp;
    cout << ans << endl;
}