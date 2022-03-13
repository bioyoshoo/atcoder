#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> table.at(i).at(j);
        }
    }

    vector<vector<int>> ans(H, vector<int>(W, -1));
    int k = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table.at(i).at(j) == '#') {
                ans.at(i).at(j) = k;
                k++;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        int owner = -1;
        for (int j = 0; j < W; j++) {
            if (ans.at(i).at(j) == -1) ans.at(i).at(j) = owner;
            else owner = ans.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        int owner = -1;
        for (int j = W - 1; j >= 0; j--) {
            if (ans.at(i).at(j) == -1) ans.at(i).at(j) = owner;
            else owner = ans.at(i).at(j);
        }
    }

    for (int j = 0; j < W; j++) {
        int owner = -1;
        for (int i = 0; i < H; i++) {
            if (ans.at(i).at(j) == -1) ans.at(i).at(j) = owner;
            else owner = ans.at(i).at(j);
        }
    }

    for (int j = 0; j < W; j++) {
        int owner = -1;
        for (int i = H - 1; i >= 0; i--) {
            if (ans.at(i).at(j) == -1) ans.at(i).at(j) = owner;
            else owner = ans.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }
}