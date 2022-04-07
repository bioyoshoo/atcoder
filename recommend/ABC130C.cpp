#include <bits/stdc++.h>
using namespace std;

int main() {
    long double W, H, x, y;
    cin >> W >> H >> x >> y;

    long double c_x = W / 2, c_y = H / 2;

    int ans_mult = 0;
    if (x == c_x && y == c_y) ans_mult = 1;

    cout << fixed << setprecision(10);
    cout << H * W / 2 << " " << ans_mult << endl;
}