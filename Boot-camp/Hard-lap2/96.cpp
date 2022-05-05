#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> table(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    vector<vector<int>> ans;
    int N = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j + 1 < W && table[i][j] % 2 != 0) {
                table[i][j]--;
                table[i][j + 1]++;
                N++;
                ans.push_back({i + 1, j + 1, i + 1, j + 2});
            }
        }
    }
    for (int i = 0; i < H; i++) {
        if (i + 1 < H && table[i][W - 1] % 2 != 0) {
            table[i][W - 1]--;
            table[i + 1][W - 1]++;
            N++;
            ans.push_back({i + 1, W, i + 2, W});
        }
    }
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ans[i][j];
            if (j == 3) cout << endl;
            else cout << " ";
        }
    }
}