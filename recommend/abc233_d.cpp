#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    vector<ll> S(N + 1);
    for (int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];
    map<ll, ll> mp;
    for (int i = 0; i <= N; i++) mp[S[i]]++;

    ll ans = 0;
    for (int l = 1; l <= N; l++) {
        mp[S[l - 1]]--;
        ans += mp[S[l - 1] + K];
    }
    cout << ans << endl;
}