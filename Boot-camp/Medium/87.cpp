#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x;
    cin >> x;

    int64_t ans = 0;
    ans = x / 11 * 2;

    if (x % 11 == 0) {
        cout << ans << endl;
    }
    else if (x % 11 <= 6) {
        cout << ans + 1 << endl;
    }
    else cout << ans + 2 << endl;
}