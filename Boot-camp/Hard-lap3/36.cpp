#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll S; cin >> S;
    ll x, y;
    ll v = 1e9;
    y = (S + v - 1) / v; x = v * y - S;
    cout << "0 0 1000000000 1 " << x << " " << y << endl;
}