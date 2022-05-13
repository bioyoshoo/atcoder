#include <bits/stdc++.h>
using namespace std;
const int MAX = 2.5 * 1e6;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            table[i][j] = (int)(s[j] - '0');
        }
    }
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vector<vector<int>> ans(N, vector<int>(M, 0));
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            int n = MAX;
            for (int r = 0; r < 4; r++) n = min(n, table[i + dx[r]][j + dy[r]]);
            ans[i][j] = n;
            for (int r = 0; r < 4; r++) table[i + dx[r]][j + dy[r]] -= n;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j];
            if (j == M - 1) cout << endl;
        }
    }
}