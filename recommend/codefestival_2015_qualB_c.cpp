#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < M; i++) cin >> B.at(i);

    bool ans;
    if (N < M) ans = false;
    else {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        bool flag = true;
        for (int i = 0; i < M; i++) {
            if (A[i] < B[i]) flag = false;
        }
        if (flag) ans = true;
        else ans = false;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}