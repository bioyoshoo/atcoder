#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    int n = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '#') n++;
        }
    }

    if (n == H + W - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}