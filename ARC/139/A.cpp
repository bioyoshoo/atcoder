#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> T(N);
    for (int i = 0; i < N; i++) cin >> T.at(i);

    vector<int64_t> ans(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) ans[0] = pow(2, T[i]);
        else {
            int64_t base = (ans[i - 1] - (int64_t)pow(2, T[i])) / (int64_t)pow(2, T[i] + 1);
            int64_t cand1 = (int64_t)pow(2, T[i] + 1) * base + (int64_t)pow(2, T[i]);
            int64_t cand2 = (int64_t)pow(2, T[i] + 1) * (base + 1) + (int64_t)pow(2, T[i]);
            if (ans[i - 1] < cand1) ans[i] = cand1;
            else ans[i] = cand2; 
        }
    }

    cout << ans[N - 1] << endl;
}