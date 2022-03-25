#include <bits/stdc++.h>
using namespace std;
using vvv = vector<vector<vector<int64_t>>>;

int main() {
    int N;
    cin >> N;
    vvv F(N, vector<vector<int64_t>>(5, vector<int64_t>(2)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                cin >> F[i][j][k];
            }
        }
    }
    vector<vector<int64_t>> P(N, vector<int64_t>(11));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    int64_t ans = -1e10;
    for (int64_t i = 1; i < (1 << 10); i++) {
        vector<int> cnt(N, 0);
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                int64_t day = j / 2, time = j % 2;     
                for (int64_t store = 0; store < N; store++) {
                    cnt[store] += F[store][day][time];
                }
            }   
        }
        int64_t profit = 0;
        for (int i = 0; i < N; i++) profit += P[i][cnt[i]];
        ans = max(ans, profit);
    }
    cout << ans << endl;
}