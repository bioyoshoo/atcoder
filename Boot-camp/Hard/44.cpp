#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> table(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            if (y == 1) table.at(i).at(x) = 1;
            else if (y == 0) table.at(i).at(x) = -1;
        }
    }

    int ans = 0;
    for (int64_t p = 0; p <= (1LL << N); p++) {
        vector<int> honest1, honest2;
        for (int i = 0; i < N; i++) {
            if (p & (1 << i)) honest1.push_back(i);
        }
        for (int i: honest1) {
            for (int j = 0; j < N; j++) {
                if (table.at(i).at(j) == 1) honest2.push_back(j);
            }
        }
        set<int> honest;
        for (int i: honest1) honest.insert(i);
        for (int i: honest2) honest.insert(i);

        int honest_size = honest.size();
        bool flag = true;

        for (int j = 0; j < N; j++) {
            int row_max = -1, row_min = 1;
            for (auto v: honest) {
                row_max = max(row_max, table.at(v).at(j));
                row_min = min(row_min, table.at(v).at(j));
            }
            if (row_max == 1 && row_min == -1) {
                flag = false;
                break;
            }
        }
        if (flag) ans = max(ans, honest_size);
    }

    cout << ans << endl;
}