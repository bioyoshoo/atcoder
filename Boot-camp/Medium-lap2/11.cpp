#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e10;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<pair<int64_t, int64_t>> students(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        students.at(i) = {a, b};
    }
    vector<pair<int64_t, int64_t>> checkpoints(M);
    for (int i = 0; i < M; i++) {
        int64_t c, d;
        cin >> c >> d;
        checkpoints.at(i) = {c, d};
    }

    vector<vector<int64_t>> table(N, vector<int64_t>(M, 0));
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            pair<int64_t, int64_t> s = students.at(n), c = checkpoints.at(m);
            table.at(n).at(m) = abs(s.first - c.first) + abs(s.second - c.second);
        }
    }

    for (int i = 0; i < N; i++) {
        int64_t ans = -1, ans_max = MAX;
        for (int j = 0; j < M; j++) {
            if (chmin(ans_max, table.at(i).at(j))) ans = j + 1;
        }
        cout << ans << endl;
    }
}
