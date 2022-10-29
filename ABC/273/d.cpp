#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int search_min(vector<int> V, int x) {
    return lower_bound(V.begin(), V.end(), x) - V.begin() - 1;
}

int search_max(vector<int> V, int x) {
    return upper_bound(V.begin(), V.end(), x) - V.begin();
}

int main() {
    int H, W, rs, cs; cin >> H >> W >> rs >> cs;
    int N; cin >> N;
    map<int, vector<int>> R, C;
    set<int> R_st, C_st;
    rep(i, N) {
        int r, c; cin >> r >> c;
        R[r].push_back(c); C[c].push_back(r);
        R_st.insert(r); C_st.insert(c);
    }

    for (auto r: R_st) sort(R[r].begin(), R[r].end());
    for (auto c: C_st) sort(C[c].begin(), C[c].end());

    int Q; cin >> Q;
    int x = rs, y = cs;
    rep(i, Q) {
        char d; int l; cin >> d >> l;
        if (d == 'L') {
            // left
            if ((int)R[x].size() == 0) y = max(1, y - l);
            else {
                int idx = search_min(R[x], y);
                if (idx == -1) y = max(1, y - l);
                else y = max(R[x][idx] + 1, y - l);
            }
            cout << x << " " << y << endl;
        }
        else if (d == 'R') {
            // right
            if ((int)R[x].size() == 0) y = min(W, y + l);
            else {
                int idx = search_max(R[x], y);
                if (idx == (int)R[x].size()) y = min(W, y + l);
                else y = min(R[x][idx] - 1, y + l);
            }
            cout << x << " " << y << endl;
        }
        else if (d == 'U') {
            // up
            if ((int)C[y].size() == 0) x = max(1, x - l);
            else {
                int idx = search_min(C[y], x);
                if (idx == -1) x = max(1, x - l);
                else x = max(C[y][idx] + 1, x - l);
            }
            cout << x << " " << y << endl;
        }
        else if (d == 'D') {
            // down
            if ((int)C[y].size() == 0) x = min(H, x + l);
            else {
                int idx = search_max(C[y], x);
                if (idx == (int)C[y].size()) x = min(H, x + l);
                else y = min(C[y][idx] - 1, x + l);
            }
            cout << x << " " << y << endl;
        }
    }
}
