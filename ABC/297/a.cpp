#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, D; cin >> N >> D;
    vector<int> T(N); rep(i, N) cin >> T[i];

    for (int i = 1; i < N; i++) {
        if (T[i] - T[i - 1] <= D) {
            cout << T[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}