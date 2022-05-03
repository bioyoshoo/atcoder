#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<int> ans(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        int n = i + 1;
        int sum = 0;
        for (int j = 2 * n - 1; j < N; j += n) sum += ans[j];
        if (sum % 2 == A[i]) ans[i] = 0;
        else ans[i] = 1;
    }

    int64_t total = 0;
    for (int i = 0; i < N; i++) if (ans[i] == 1) total++;
    cout << total << endl;
    for (int i = 0; i < N; i++) if (ans[i] == 1) cout << i + 1 << " ";
    cout << endl;
}