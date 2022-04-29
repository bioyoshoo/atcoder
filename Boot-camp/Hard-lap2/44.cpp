#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> table(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            table[i][x] = y;
        }
    }

    int ans = 0;
    for (int64_t i = 0; i < (1LL << N); i++) {
        set<int> cand;
        vector<int> honest, not_honest;
        for (int j = 0; j < N; j++) {
            if (i & (1LL << j)) {
                cand.insert(j);
                for (int k = 0; k < N; k++) {
                    if (table[j][k] == 1) honest.push_back(k);
                    else if (table[j][k] == 0) not_honest.push_back(k);
                }
            }
        }
        bool flag = true;
        for (auto h: honest) if (!cand.count(h)) flag = false;
        for (auto n: not_honest) if (cand.count(n)) flag = false;
        
        if (flag) ans = max(ans, (int)cand.size());
    }

    cout << ans << endl;
}