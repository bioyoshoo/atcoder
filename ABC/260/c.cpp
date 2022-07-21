#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    ll X, Y;
    cin >> N >> X >> Y;

    vector<ll> Red(N + 1), Blue(N + 1);
    Red[N] = 1;

    for (int i = N - 1; i >= 1; i--) {
        Red[i] = Red[i + 1] * (1 + X) + Blue[i + 1];
        Blue[i] = Red[i + 1] * X * Y + Blue[i + 1] * Y;
    }

    cout << Blue[1] << endl;
}