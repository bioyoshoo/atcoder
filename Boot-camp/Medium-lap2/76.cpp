#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e6;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> W(N, 0), E(N, 0);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'W') W[i] = 1;
        else if (S[i] == 'E') E[i] = 1;
    }

    for (int i = 1; i < N; i++) W[i] += W[i - 1];
    for (int i = N - 2; i >= 0; i--) E[i] += E[i + 1];

    int ans = MAX;
    for (int i = 0; i < N; i++) {
        if (i == 0) chmin(ans, E[0]);
        else if (i == N - 1) chmin(ans, W[N - 1]);
        else chmin(ans, W[i - 1] + E[i + 1]);
    }

    cout << ans << endl;
}