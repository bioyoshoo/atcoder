#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S.at(i);

    vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};
    vector<vector<int>> ans(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                for (int d = 0; d < 8; d++) {
                    int dh = dx[d], dw = dy[d];
                    
                    if (i + dh >= 0 && i + dh < H && j + dw >= 0 && j + dw < W) ans[i + dh][j + dw]++;
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') cout << '#';
            else cout << ans[i][j];

            if (j == W - 1) cout << endl;
        }
    }
}