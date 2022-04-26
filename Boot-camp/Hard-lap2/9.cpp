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
            if (i + M > N) continue;
            if (j + M > N) continue;

            bool flag = true;
            for (int a = 0; a < M; a++) {
                for (int b = 0; b < M; b++) {
                    if (A[i + a][j + b] != B[a][b]) flag = false;
                }
            }

            if (flag) {
                ans = true;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}