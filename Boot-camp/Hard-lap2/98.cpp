#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> counts(26, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            counts[c - 'a']++;
        }
    }

    int g1, g2, g4;
    if (H % 2 == 1 && W % 2 == 1) g1 = 1, g2 = H + W - 1;
    else if (H % 2 == 1) g1 = 0, g2 = W;
    else if (W % 2 == 1) g1 = 0, g2 = H;
    else g1 = 0, g2 = 0;
    g4 = H * W - g1 - g2;
    g2 /= 2; g4 /= 4;

    for (int r = 0; r < g1; r++) {
        for (int i = 0; i < 26; i++) {
            if (counts[i] >= 1 && (counts[i] % 4 == 1 || counts[i] % 4 == 3)) counts[i] -= 1;
        }
    }
    for (int r = 0; r < g4; r++) {
        for (int i = 0; i < 26; i++) {
            if (counts[i] >= 4 && (counts[i] % 4 == 0 || counts[i] % 4 == 2)) counts[i] -= 4;
        }
    }
    for (int r = 0; r < g2; r++) {
        for (int i = 0; i < 26; i++) {
            if (counts[i] >= 2 && (counts[i] % 4 == 0 || counts[i] % 4 == 2)) counts[i] -= 2;
        }
    }

    bool ans = true;
    for (int i = 0; i < 26; i++) if (counts[i] != 0) ans = false;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}