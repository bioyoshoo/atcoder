#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e15;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t x, y;
    cin >> x >> y;

    int64_t ans = MAX;

    if (x <= y) chmin(ans, y - x);
    if (-x <= y) chmin(ans, y + x + 1);
    if (x <= -y) chmin(ans, -y - x + 1);
    if (-x <= -y) chmin(ans, -y + x + 2);

    cout << ans << endl;
}