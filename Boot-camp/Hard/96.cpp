#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> table(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] % 2 == 1 && i + 1 < H) {
                cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << endl;
                table[i][j]--;
                table[i + 1][j]++;
            }
        }
    }

    for (int j = 0; j < W; j++) {
        if (table[H - 1][j] % 2 == 1 && j + 1 < W) {
            cout << H << " " << j + 1 << " " << H << " " << j + 2 << endl;
            table[H - 1][j]--;
            table[H - 1][j + 1]++;
        }
    }
}