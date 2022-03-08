#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, x;
    cin >> a >> b >> x;

    int64_t ans;
    if (a % x == 0) ans = b / x - a / x + 1;
    else if (a % x != 0) ans = b / x - a / x;
    cout << ans << endl;
}