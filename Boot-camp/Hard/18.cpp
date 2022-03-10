#include <bits/stdc++.h>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<vector<int>> path;
    path.push_back({sx, sy});
    path.push_back({sx, ty});
    path.push_back({tx + 1, ty});
    path.push_back({tx + 1, sy - 1});
    path.push_back({sx, sy - 1});
    path.push_back({sx, sy});
    path.push_back({sx - 1, sy});
    path.push_back({sx - 1, ty + 1});
    path.push_back({tx, ty + 1});
    path.push_back({tx, sy});
    path.push_back({sx, sy});

    for (int i = 0; i < 10; i++) {
        int diff_x, diff_y, steps;
        char dir;
        diff_x = path.at(i + 1).at(0) - path.at(i).at(0);
        diff_y = path.at(i + 1).at(1) - path.at(i).at(1);
        steps = max(abs(diff_x), abs(diff_y));

        if (diff_y == 0) {
            if (diff_x > 0) dir = 'R';
            else if (diff_x < 0) dir = 'L';
        }
        else if (diff_x == 0) {
            if (diff_y > 0) dir = 'U';
            else if (diff_y < 0) dir = 'D';
        }

        for (int j = 0; j < steps; j++) cout << dir;
    }
    cout << endl;
}