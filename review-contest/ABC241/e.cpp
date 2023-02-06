#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll X = 0;
    int i = 0;
    vector<vector<pair<int, ll>>> L(N);
    ll start = -1, T = -1, sum = -1;
    while (true) {
        L[X % N].push_back(make_pair(i, X));

        if ((int)L[X % N].size() == 2) {
            start = L[X % N][0].first;
            T = L[X % N][1].first - L[X % N][0].first;
            sum = L[X % N][1].second - L[X % N][0].second;
            break;
        }

        i++;
        X += A[X % N];
    }

    cout << T << " " << sum << endl;

    ll ans = 0;
    
    ans += 
}