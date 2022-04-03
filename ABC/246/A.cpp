#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> X, Y;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        X[x]++;
        Y[y]++;
    }

    int ans_x, ans_y;
    for (auto x: X) if (x.second == 1) ans_x = x.first;
    for (auto y: Y) if (y.second == 1) ans_y = y.first;

    cout << ans_x << " " << ans_y << endl;
}