#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll X; cin >> X;
    int K; cin >> K;

    ll div = 1;
    rep(i, K) {
        div *= 10;

        ll a = X / div * div;
        ll b = (X / div + 1) * div;

        if (abs(a - X) < abs(b - X)) X = a;
        else X = b;
    }

    cout << X << endl;
}