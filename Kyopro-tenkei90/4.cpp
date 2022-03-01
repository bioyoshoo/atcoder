#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<int>> table(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> table.at(i).at(j);
    }

    vector<int> Row(H, 0), Col(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) Row.at(i) += table.at(i).at(j);
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) Col.at(j) += table.at(i).at(j);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << Row.at(i) + Col.at(j) - table.at(i).at(j);
            if (j != W - 1) cout << " ";
            else cout << endl;
        }
    }
}