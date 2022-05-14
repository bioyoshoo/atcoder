#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> table(H);
    for (int i = 0; i < H; i++) cin >> table.at(i);
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1}, dy = {0, 1, 1, 1, 0, -1, -1, -1};
    
    vector<string> cand(H, string(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '#') {
                bool flag = true;
                for (int r = 0; r < 8; r++) {
                    int next_i = i + dx[r], next_j = j + dy[r];
                    if (next_i < 0 || H <= next_i) continue;
                    if (next_j < 0 || W <= next_j) continue;
                    if (table[next_i][next_j] == '.') flag = false;
                }
                if (flag) cand[i][j] = '#';
            }
        }
    }

    vector<string> recover(H, string(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (cand[i][j] == '#') {
                recover[i][j] = '#';
                for (int r = 0; r < 8; r++) {
                    int next_i = i + dx[r], next_j = j + dy[r];
                    if (next_i < 0 || H <= next_i) continue;
                    if (next_j < 0 || W <= next_j) continue;
                    recover[next_i][next_j] = '#';
                }
            }
        }
    }

    bool ans = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] != recover[i][j]) ans = false;
        }
    }
    if (ans) {
        cout << "possible" << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << cand[i][j];
                if (j == W - 1) cout << endl;
            }
        }
    }
    else cout << "impossible" << endl;
}