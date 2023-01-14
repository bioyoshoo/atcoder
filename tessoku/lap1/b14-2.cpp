#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N, K;
ll A[50];

vector<ll> pairwise_sum(vector<ll> L) {
    vector<ll> res;
    int n = L.size();
    for (int i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += L[j];
        }
        res.push_back(sum);
    }
    return res;
}

int main() {
    cin >> N >> K;
    rep(i, N) cin >> A[i];

    vector<ll> L1, L2;
    for (int i = 0; i < N / 2; i++) L1.push_back(A[i]);
    L1 = pairwise_sum(L1);
    for (int i = N / 2; i < N; i++) L2.push_back(A[i]);
    L2 = pairwise_sum(L2);

    sort(L2.begin(), L2.end());

    for (auto x: L1) {
        auto idx = lower_bound(L2.begin(), L2.end(), K - x);
        if (idx < L2.end() && *idx == K - x) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
