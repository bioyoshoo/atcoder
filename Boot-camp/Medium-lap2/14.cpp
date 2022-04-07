#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            table.at(i).at(j) = c;
        }
    }

    vector<int> dh = {1, 0, 0, -1}, dw = {0, 1, -1, 0};
    bool ans = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table.at(i).at(j) == '.') continue;

            bool flag = true;
            for (int k = 0; k < 4; k++) {
                if (i + dh.at(k) < 0 || i + dh.at(k) >= H) continue;
                if (j + dw.at(k) < 0 || j + dw.at(k) >= W) continue;

                if (table.at(i + dh.at(k)).at(j + dw.at(k)) == '#') flag = false;
            }
            if (flag) {
                ans = false;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}