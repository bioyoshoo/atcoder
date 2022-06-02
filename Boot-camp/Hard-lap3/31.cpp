#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    vector<int> ans(N);
    int n = 0;
    for (int i = N - 1; i >= 0; i--) {
        int sum = 0;
        for (int j = 2 * i + 1; j < N; j += i + 1) sum += ans[j];
        if (sum % 2 != A[i]) {
            ans[i] = 1;
            n++;
        }
    }
    cout << n << endl;
    rep(i, N) if (ans[i] == 1) cout << i + 1 << endl;
}