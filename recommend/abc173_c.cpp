#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    int ans = 0;
    for (long long i = 0; i < (1LL << H); i++) {
        for (long long j = 0; j < (1LL << W); j++) {
            set<int> row, col;
            for (int a = 0; a < H; a++) if (i & (1LL << a)) row.insert(a);
            for (int b = 0; b < W; b++) if (j & (1LL << b)) col.insert(b);

            int cnt = 0;
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    if (row.count(h) || col.count(w)) continue;
                    if (table[h][w] == '#') cnt++;
                }
            }
            if (cnt == K) ans++;
        }
    }
    cout << ans << endl;
}