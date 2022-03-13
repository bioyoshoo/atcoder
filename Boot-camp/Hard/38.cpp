#include <bits/stdc++.h>
using namespace std;
using vvc = vector<vector<char>>;
using vvi = vector<vector<int64_t>>;
using vp = vector<pair<int, int>>;
using pp = pair<int64_t, int64_t>;

vp valid_move(pair<int, int> p, vvc table) {
    int H = table.size(), W = table.at(0).size();
    vp dir;
    dir.push_back({1, 0});
    dir.push_back({0, 1});
    dir.push_back({0, -1});
    dir.push_back({-1, 0});

    vp ans;
    for (int  i = 0; i < 4; i++) {
        int new_h, new_w;
        new_h = p.first + dir.at(i).first;
        new_w = p.second + dir.at(i).second;
        if (new_h >= 0 && new_h < H && new_w >= 0 && new_w < W && table.at(new_h).at(new_w) == '.') {
            ans.push_back({new_h, new_w});
        }
    }
    return ans;
}

void BFS(vvc table, pp pos, vvi &seen) {
    int64_t h0, w0;
    tie(h0, w0) = pos;
    int64_t depth = 0;
    seen.at(h0).at(w0) = depth;

    queue<pp> todo;
    todo.push(pos);

    while (!todo.empty()) {
        pp p = todo.front();
        int64_t hp, wp;
        tie(hp, wp) = p;
        todo.pop();

        for (pp next_p: valid_move(p, table)) {
            int next_h, next_w;
            tie(next_h, next_w) = next_p;
            if (seen.at(next_h).at(next_w) != -1) continue;
            seen.at(next_h).at(next_w) = seen.at(hp).at(wp) + 1;
            todo.push(next_p);
        }
    }
}

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    int H, W;
    cin >> H >> W;
    vvc table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> table.at(i).at(j);
        }
    }

    int64_t ans = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table.at(i).at(j) == '#') continue;
            vvi seen(H, vector<int64_t>(W, -1));
            pp start = make_pair(i, j);
            BFS(table, start, seen);

            for (int x = 0; x < H; x++) {
                for (int y = 0; y < W; y++) {
                    chmax(ans, seen.at(x).at(y));
                }
            }
        }
    }

    cout << ans << endl;
}