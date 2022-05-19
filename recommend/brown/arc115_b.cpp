#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<vector<ll>> C(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> C[i][j];
    }
    vector<ll> A(N), B(N);
    ll mini = 1e10;
    for (int i = 0; i < N; i++) mini = min(mini, C[0][i]);
    A[0] = mini;
    for (int i = 0; i < N; i++) B[i] = C[0][i] - A[0];
    for (int i = 1; i < N; i++) A[i] = C[i][0] - B[0];

    bool ans = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] < 0 || B[j] < 0) ans = false;
            if (A[i] + B[j] != C[i][j]) ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
        for (int i = 0; i < N; i++) cout << A[i] << " ";
        cout << endl;
        for (int i = 0; i < N; i++) cout << B[i] << " ";
        cout << endl;
    }
    else cout << "No" << endl;
}