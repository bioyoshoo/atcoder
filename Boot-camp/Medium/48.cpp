#include <bits/stdc++.h>
using namespace std;

int main() {
    double W, H, x, y;
    cin >> W >> H >> x >> y;

    cout << fixed << setprecision(7);
    cout << (H * W) / 2 << " ";

    if (x == W / 2 && y == H / 2) cout << 1 << endl;
    else if (x == W / 2) cout << 0 << endl;
    else if (y == H / 2) cout << 0 << endl;
    else if (y == H / W * x) cout << 0 << endl;
    else if (y == (-1) * H / W * x + H) cout << 0 << endl;
    else cout << 1 << endl;
}