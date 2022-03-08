#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();

    vector<vector<int>> next(MAX, vector<int>(N));

    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'L') next.at(0).at(i) = i - 1;
        else if (S.at(i) == 'R') next.at(0).at(i) = i + 1;
    }
    for (int step = 0; step < MAX - 1; step++) {
        for (int i = 0; i < N; i++) next[step + 1][i] = next[step][next[step][i]];
    }

    vector<int> res(N, 0);
    int K = 2 * N;
    for (int v = 0; v < N; v++) {
        int nv = v;
        for (int d = 0; d <= MAX; d++) {
            if (K & (1 << d)) nv = next[d][nv];
        }

        res.at(nv)++;
    }

    for (int r: res) cout << r << " ";
    cout << endl;
}