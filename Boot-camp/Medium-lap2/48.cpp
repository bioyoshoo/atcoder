#include <bits/stdc++.h>
using namespace std;

int main() {
    long double W, H, x, y;
    cin >> W >> H >> x >> y;

    long double ans_area = H * W / 2;
    int ans = 0;
    if (W / 2 == x && H / 2 == y) ans = 1;
    
    cout << fixed << setprecision(12);
    cout << ans_area << " " << ans << endl;
}