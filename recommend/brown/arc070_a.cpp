#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll X; cin >> X;
    ll ans = 0;
    ll pos = 0, j = 1;
    while (pos < X) {
        pos += j;
        ans++;
        j += 1;
    }
    cout << ans << endl;
}