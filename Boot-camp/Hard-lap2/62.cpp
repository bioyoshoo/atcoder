#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    vector<vector<int>> row(H, vector<int>(W, 0)), col(H, vector<int>(W, 0)), total(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W;) {
            int k = j + 1;
            while (k < W && table[i][j] == table[i][k]) k++;
            for (int l = j; l < k; l++) if (table[i][j] == '.') row[i][l] = k - j;
            j = k;
        }
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H;) {
            int k = i + 1;
            while (k < H && table[i][j] == table[k][j]) k++;
            for (int l = i; l < k; l++) if (table[i][j] == '.') col[l][j] = k - i;
            i = k;
        }    
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '.') total[i][j] = row[i][j] + col[i][j] - 1;
        }
    }

    int ans = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, total[i][j]);
        }
    }
    cout << ans << endl;
}