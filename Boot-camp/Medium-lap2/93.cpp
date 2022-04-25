#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int64_t>> table(N, vector<int64_t>(M, 0));
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            s--;
            table.at(s).at(i) = 1;
        }
    }
    vector<int64_t> P(M);
    for (int i = 0; i < M; i++) cin >> P.at(i);

    int64_t ans = 0;
    for (int64_t i = 0; i < (1LL << N); i++) {
        vector<int64_t> lights(M, 0);
        for (int j = 0; j < N; j++) {
            if (i & (1LL << j)) {
                for (int k = 0; k < M; k++) {
                    lights.at(k) += table.at(j).at(k);
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < M; j++) {
            if (P.at(j) != lights.at(j) % 2) flag = false;
        }
        if (flag) ans++;
    }

    cout << ans << endl;
}