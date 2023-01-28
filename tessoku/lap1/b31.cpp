#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N; cin >> N;
    ll a = N / 3, b = N / 5, c = N / 7, d = N / 15, e = N / 21, f = N / 35, g = N / 105;

    cout << a + b + c - d - e - f + g << endl;
}
