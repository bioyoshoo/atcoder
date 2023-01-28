#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    map<int, vector<int>> mp;
    rep(i, N) {
        if (A[i] < 0) {
            int t = (abs(A[i]) + i) / (i + 1);
            mp[t].push_back(i);
        }
        else mp[1].push_back(i);
    }

    for (int i = 1; i <= M; i++) {
        mp[i]
    }
}