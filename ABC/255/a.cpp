#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int r, c; cin >> r >> c; r--; c--;
    vector<vector<int>> A(2, vector<int>(2));
    rep(i, 2) rep(j, 2) cin >> A[i][j];
    cout << A[r][c] << endl;
}