#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t H, W, C, Q;
    cin >> H >> W >> C >> Q;
    vector<int64_t> ans(C, 0);
    vector<tuple<int64_t, int64_t, int64_t>> query;

    for (int i = 0; i < Q; i++) {
        int64_t t, n, c;
        cin >> t >> n >> c;
        n--; c--;
        query.push_back({t, n, c});
    }

    set<int64_t> used_row, used_col;

    for (int i = Q - 1; i >= 0; i--) {
        int64_t t, n, c;
        tie(t, n, c) = query.at(i);
        
        if (t == 1) {
            if (used_row.count(n)) continue;
            ans.at(c) += W - used_col.size();
            used_row.insert(n);
        }
        else if (t == 2) {
            if (used_col.count(n)) continue;
            ans.at(c) += H - used_row.size();
            used_col.insert(n);
        }
    }

    for (int i = 0; i < C; i++) cout << ans.at(i) << " ";
    cout << endl;
}