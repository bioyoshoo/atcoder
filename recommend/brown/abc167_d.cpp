#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        a--;
        cout << a << endl;
        cin >> A.at(i);
    }

    vector<vector<int>> table(61, vector<int>(N));
    for (int i = 0; i < N; i++) table[0][i] = A[i];
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < N; j++) {
            table[i + 1][j] = table[i][table[i][j]];
            cout << i << endl;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 61; i++) {
        if (K & (1LL << i)) ans = table[i][ans];
    }
    ans++;
    cout << ans << endl;
}