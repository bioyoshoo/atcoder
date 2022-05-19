#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    vector<ll> S(N + 1);
    for (int i = 0; i <= N; i++) S[i + 1] += S[i] + A[i];

    ll ans = 0;
    ll mx = -1e10, sum = 0, start = 0;
    for (int i = 0; i < N; i++) {
        start += S[i];
        sum += A[i];
        mx = max(mx, sum);
        ans = max(ans, start + mx);
    }
    cout << ans << endl;
}