#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<pair<int, int>> C;
    rep(i, N) C.push_back({A[i], 0});
    rep(j, M) C.push_back({B[j], 1});

    sort(C.begin(), C.end());

    vector<int> a, b;
    rep(i, N + M) {
        if (C[i].second == 0) a.push_back(i + 1);
        else b.push_back(i + 1);
    }

    rep(i, N) cout << a[i] << " ";
    cout << endl;
    rep(i, M) cout << b[i] << " ";
    cout << endl;
}