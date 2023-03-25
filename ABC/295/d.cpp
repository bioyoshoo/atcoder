#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int N = S.size();

    map<vector<int>, int> M;
    vector<int> V(10);
    M[V] += 1;

    rep(i, N) {
        int x = (int)(S[i] - '0');
        V[x] += 1; V[x] %= 2;
        M[V] += 1;
    }

    ll ans = 0;
    for (auto m: M) {
        int n = m.second;
        ans += 1LL*n*(n - 1)/2;
    }
    cout << ans << endl;
}