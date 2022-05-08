#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int r, c;
    cin >> r >> c;

    int ans = 0;
    if (1 <= r && r <= H && 1 <= c + 1 && c + 1 <= W) ans++;
    if (1 <= r + 1 && r + 1 <= H && 1 <= c && c <= W) ans++;
    if (1 <= r - 1 && r - 1 <= H && 1 <= c && c <= W) ans++;
    if (1 <= r && r <= H && 1 <= c - 1 && c - 1 <= W) ans++;
    cout << ans << endl;
}