#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    int N = S.size();

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'U') {
            ans += N - 1 - i;
            ans += 2 * i;
        }
        else if (S[i] == 'D') {
            ans += 2 * (N - 1 - i);
            ans += i;
        }
    }
    cout << ans << endl;
}