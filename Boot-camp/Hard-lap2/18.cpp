#include <bits/stdc++.h>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans = "";

    vector<pair<int, int>> points;
    points.push_back({sx, ty});
    points.push_back({tx + 1, ty});
    points.push_back({tx + 1, sy - 1});
    points.push_back({sx, sy - 1});
    points.push_back({sx, sy});
    points.push_back({sx - 1, sy});
    points.push_back({sx - 1, ty + 1});
    points.push_back({tx, ty + 1});
    points.push_back({tx, sy});
    points.push_back({sx, sy});

    int pre_x = sx, pre_y = sy;
    char dir;
    int move;
    for (int i = 0; i < 10; i++) {
        int next_x, next_y;
        tie(next_x, next_y) = points.at(i);
        move = abs(next_x - pre_x) + abs(next_y - pre_y);

        if (pre_x < next_x) dir = 'R';
        else if (pre_x > next_x) dir = 'L';
        else if (pre_y < next_y) dir = 'U';
        else if (pre_y > next_y) dir = 'D';
        
        for (int i = 0; i < move; i++) ans += dir;
        pre_x = next_x; pre_y = next_y;
    }

    cout << ans << endl;
}