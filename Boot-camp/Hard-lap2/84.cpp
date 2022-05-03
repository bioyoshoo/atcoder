#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) cin >> F.at(i).at(j);
    }
    vector<vector<long long>> P(N, vector<long long>(11));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++) cin >> P.at(i).at(j);
    }

    long long ans = -1e15;
    for (long long i = 1; i < (1LL << 10); i++) {
        long long profit = 0;
        vector<int> compete(N, 0);
        for (int j = 0; j < 10; j++) {
            if (i & (1LL << j)) {
                for (int k = 0; k < N; k++) compete[k] += F[k][j];
            }
        }
        for (int l = 0; l < N; l++) profit += P[l][compete[l]];
        ans = max(ans, profit);
    }
    cout << ans << endl;
}