#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    bool ok = false;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] + A[k] == 1000) ok = true;
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
