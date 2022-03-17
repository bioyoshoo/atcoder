#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> table(H);
    for (int i = 0; i < H; i++) cin >> table.at(i);

    vector<vector<int>> L(H, vector<int>(W, 0)), V(H, vector<int>(W, 0));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W;) {
            int k = j + 1;
            while (k < W && table[i][j] == table[i][k]) k++;
            if (table[i][j] == '.' ) for (int l = j; l < k; l++) L[i][l] = k - j;
            j = k;
        }
    }

    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H;) {
            int k = i + 1;
            while (k < H && table[i][j] == table[k][j]) k++;
            if (table[i][j] == '.') for (int l = i; l < k; l++) V[l][j] = k - i;
            i = k;
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int cond = L[i][j] + V[i][j] - 1;
            ans = max(ans, cond);
        }
    }

    cout << ans << endl;
}