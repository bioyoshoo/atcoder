#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(N, 0)), A(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        T[a][b] = 1; T[b][a] = 1;
    }
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        A[c][d] = 1;
        A[d][c] = 1;
    }

    vector<int> P(N);
    for (int i = 0; i < N; i++) P.at(i) = i;

    bool ans = false;
    do {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (T[i][j] != A[P[i]][P[j]]) flag = false;
            }
        }
        if (flag) ans = true;
    } while (next_permutation(P.begin(), P.end()));

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}