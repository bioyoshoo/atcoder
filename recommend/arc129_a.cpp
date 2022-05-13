#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, L, R;
    cin >> N >> L >> R;

    ll ans = 0;
    for (int i = 60; i >= 0; i--) {
        if (N & (1LL << i)) {
            ll right = min((1LL << (i + 1)) - 1, R);
            ll left = max((1LL << i), L);
            ans += max(0LL, right - left + 1);
        }
    }
    cout << ans << endl;
}