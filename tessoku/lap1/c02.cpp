#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = max(ans, A[i] + A[j]);
        }
    }

    cout << ans << endl;
}
