#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            table[i][j] = c;
        }
    }
    vector<vector<int>> ans(H, vector<int>(W, 0));
    int n = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '#') {
                ans[i][j] = n;
                n++;
            }
        }
    }

    // row right
    for (int i = 0; i < H; i++) {
        int last_n = 0;
        for (int j = 0; j < W; j++) {
            if (ans[i][j] != 0) last_n = ans[i][j];
            ans[i][j] = last_n;
        }
    }
    // row left
    for (int i = 0; i < H; i++) {
        int last_n = 0;
        for (int j = W - 1; j >= 0; j--) {
            if (ans[i][j] != 0) last_n = ans[i][j];
            ans[i][j] = last_n;
        }
    }
    // col down
    for (int j = 0; j < W; j++) {
        int last_n = 0;
        for (int i = 0; i < H; i++) {
            if (ans[i][j] != 0) last_n = ans[i][j];
            ans[i][j] = last_n;
        }
    }
    // col up
    for (int j = 0; j < W; j++) {
        int last_n = 0;
        for (int i = H - 1; i >= 0; i--) {
            if (ans[i][j] != 0) last_n = ans[i][j];
            ans[i][j] = last_n;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j] << " ";
            if (j == W - 1) cout << endl;
        }
    }
}