#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> table(N);
    for (int i = 0; i < N; i++) cin >> table.at(i);

    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 5 >= N) continue;
            if (j + 5 >= N) continue;
            
            // row
            for (int rx = 0; rx < 6; rx++) {
                int cnt = 0;
                for (int ry = 0; ry < 6; ry++) {
                    if (table[i + rx][j + ry] == '#') cnt++;
                }
                if (cnt >= 4) flag = true;
            }
            // col
            for (int ry = 0; ry < 6; ry++) {
                int cnt = 0;
                for (int rx = 0; rx < 6; rx++) {
                    if (table[i + rx][j + ry] == '#') cnt++;
                }
                if (cnt >= 4) flag = true;
            }
            // diagonal
            int cnt = 0;
            for (int r = 0; r < 6; r++) {
                if (table[i + r][j + r] == '#') cnt++;
            }
            if (cnt >= 4) flag = true;
            // diagonal
            cnt = 0;
            for (int r = 0; r < 6; r++) {
                if (table[i + r][j + 5 - r] == '#') cnt++;
            }
            if (cnt >= 4) flag = true;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}