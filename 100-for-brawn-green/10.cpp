#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int q; cin >> q;

    rep(i, q) {
        int m; cin >> m;

        bool ans = false;
        for (ll i = 0; i < (1LL << N); i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1LL << j)) {
                    sum += A[j];
                }
            }

            if (sum == m) {
                ans = true;
                break;
            }
        }

        if (ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}