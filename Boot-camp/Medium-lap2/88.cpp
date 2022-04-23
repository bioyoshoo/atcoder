#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x;
    cin >> x;

    int64_t ans;
    ans = x / 11 * 2;
    if (x % 11 > 6) ans += 2;
    else if (x % 11 > 0) ans++;

    cout << ans << endl;
}