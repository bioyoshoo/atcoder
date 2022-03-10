#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < M; i++) cin >> B.at(i);

    bool ans = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + M - 1 >= N || j + M - 1 >= N) continue;

            bool scan = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i + k][j + l] != B[k][l]) {
                        scan = false;
                        break;
                    }
                }
                if (!scan) break;
            }

            if (scan) {
                ans = true;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}