#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> table(H, vector<int>(W, -1));
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;
        A.at(i) = a;
    }

    vector<pair<int, int>> dir;
    dir.push_back({0, 1});
    dir.push_back({1, 0});
    dir.push_back({0, -1});
    dir.push_back({-1, 0});

    // 初期値
    int d_ind = 0, color_ind = 0;
    pair<int, int> pos = {0, 0};
    table.at(0).at(0) = color_ind + 1;
    A.at(color_ind)--;

    for (int i = 0; i < sum - 1; i++) {
        int new_x = pos.first + dir.at(d_ind).first, new_y = pos.second + dir.at(d_ind).second;
        
        // 可能な移動かどうか
        if (new_x >= H || new_x < 0 || new_y >= W || new_y < 0 || table.at(new_x).at(new_y) != -1) {
            d_ind++;
            d_ind %= 4;
            new_x = pos.first + dir.at(d_ind).first;
            new_y = pos.second + dir.at(d_ind).second;
        }

        pos.first = new_x;
        pos.second = new_y;

        // 塗り分け
        if (A.at(color_ind) == 0) color_ind++;
        table.at(pos.first).at(pos.second) = color_ind + 1;
        A.at(color_ind)--;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << table.at(i).at(j);
            if (j != W - 1) cout << " ";
            else cout << endl;
        }
    }
}