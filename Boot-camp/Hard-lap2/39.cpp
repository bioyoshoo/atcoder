#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<int> sharp(N), dot(N);
    for (int i = 0; i < N; i++) {
        if (S.at(i) == '#') sharp[i] = 1;
        else dot[i] = 1;
    }
    for (int i = 1; i < N; i++) sharp[i] += sharp[i - 1];
    for (int i = N - 2; i >= 0; i--) dot[i] += dot[i + 1];

    int ans = 1e6;
    for (int i = 0; i < N + 1; i++) {
        if (i == 0) chmin(ans, dot[0]);
        else if (i == N) chmin(ans, sharp[N - 1]);
        else chmin(ans, sharp[i - 1] + dot[i]);
    }

    cout << ans << endl;
}