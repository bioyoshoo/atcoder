#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            table.at(i).at(j) = c;
        }
    }

    set<int> remove_rows, remove_cols;
    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) if (table.at(i).at(j) == '#') flag = false;
        if (flag) remove_rows.insert(i);
    }

    for (int j = 0; j < W; j++) {
        bool flag = true;
        for (int i = 0; i < H; i++) if (table.at(i).at(j) == '#') flag = false;
        if (flag) remove_cols.insert(j);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!remove_rows.count(i) && !remove_cols.count(j)) cout << table.at(i).at(j);
            if (j == W - 1 && !remove_rows.count(i)) cout << endl;
        }
    }
}