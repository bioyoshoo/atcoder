#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll ans = 0;
    ll sum = 0;
    rep(i, N) {
        if (A[i] == 0) {
            ans += sum / 2;
            sum = 0;
        }
        else sum += A[i];
    }
    ans += sum / 2;
    cout << ans << endl;
}