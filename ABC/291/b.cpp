#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> X(5*N); rep(i, 5*N) cin >> X[i];
    sort(X.begin(), X.end());

    ld ans = 0;
    for (int i = N; i < 4*N; i++) ans += X[i];
    ans /= 3*N;

    cout << fixed << setprecision(15);
    cout << ans << endl;
}