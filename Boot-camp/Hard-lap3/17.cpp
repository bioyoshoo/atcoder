#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    int a = 0, b = 0, ab = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        int n = S.size();
        for (int i = 0; i < n; i++) {
            if (S[i] == 'A' && S[i + 1] == 'B') ans++;
        }
        if (S[0] == 'B' && S[n - 1] == 'A') ab++;
        else if (S[0] == 'B') b++;
        else if (S[n - 1] == 'A') a++;
    }
    if (ab > 1) {
        ans += ab - 1;
        ab = 1;
    }
    if (a > 0 || b > 0) ans += min(a + ab, b + ab);
    cout << ans << endl;
}