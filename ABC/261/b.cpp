#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<string> A(N);
    rep(i, N) cin >> A[i];

    bool ans = true;
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == 'W') {
                if (A[j][i] != 'L') ans = false;
            }
            else if (A[i][j] == 'L') {
                if (A[j][i] != 'W') ans = false;
            }
            else if (A[i][j] == 'D') {
                if (A[j][i] != 'D') ans = false;
            }
        }
    }
    if (ans) cout << "correct" << endl;
    else cout << "incorrect" << endl;
    
}