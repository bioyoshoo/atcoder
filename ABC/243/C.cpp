#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

void chmax(int64_t &a, int64_t b) {
    if (a < b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    map<int64_t, vector<pair<int64_t, int64_t>>> M;
    for (int i = 0; i < N; i++) {
        int64_t x, y;
        cin >> x >> y;
        M[y].push_back({x, i});
    }
    string S;
    cin >> S;

    bool ans = false;
    for (auto m: M) {
        int64_t r_min = 1e9 + 1, l_max = -1;
        for (auto p: m.second) {
            if (S.at(p.second) == 'R') chmin(r_min, p.first);
            else if (S.at(p.second) == 'L') chmax(l_max, p.first);
        }
        if (r_min < l_max) {
            ans = true;
            break;
        }

        if (ans) break;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}