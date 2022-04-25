#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<int> ans(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        int n = i + 1;
        int sum = 0;
        for (int m = 2 * n; m <= N; m += n) sum += ans[m - 1];
        if (sum % 2 != A[i]) ans[i] = 1;
    }

    int M = 0;
    for (int i = 0; i < N; i++) if (ans[i] == 1) M++;
    cout << M << endl;
    for (int i = 0; i < N; i++) if (ans[i] == 1) cout << i + 1 << endl;
}