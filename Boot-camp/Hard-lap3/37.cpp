#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> T(H, vector<int>(W));
    int k = 1;
    rep(i, H) rep(j, W) {
        char s; cin >> s;
        if (s == '#') {
            T[i][j] = k;
            k++;
        }
    }

    // row right
    for (int i = 0; i < H; i++) {
        int owner = 0;
        for (int j = 0; j < W; j++) {
        if (T[i][j] != 0) owner = T[i][j];
        else T[i][j] = owner;
        }
    }
    // row left
    for (int i = 0; i < H; i++) {
        int owner = 0;
        for (int j = W - 1; j >= 0; j--) {
        if (T[i][j] != 0) owner = T[i][j];
        else T[i][j] = owner;
        }
    }
    // col down
    for (int j = 0; j < W; j++) {
        int owner = 0;
        for (int i = 0; i < H; i++) {
        if (T[i][j] != 0) owner = T[i][j];
        else T[i][j] = owner;
        }
    }
    // col up
    for (int j = 0; j < W; j++) {
        int owner = 0;
        for (int i = H - 1; i >= 0; i--) {
        if (T[i][j] != 0) owner = T[i][j];
        else T[i][j] = owner;
        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}