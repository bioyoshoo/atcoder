#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e6;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> B(N, 0);
    for (int i = 0; i < N; i++) if (S.at(i) == '#') B.at(i) = 1;
    for (int i = 1; i < N; i++) B.at(i) += B.at(i - 1);
    
    vector<int> W(N, 0);
    for (int i = 0; i < N; i++) if (S.at(i) == '.') W.at(i) = 1;
    for (int i = N - 2; i >= 0; i--) W.at(i) += W.at(i + 1);
    
    int ans = MAX;
    for (int i = 0; i <= N; i++) {
        if (i == 0) chmin(ans, W.at(0));
        else if (i == N) chmin(ans, B.at(N - 1));
        else chmin(ans, B.at(i - 1) + W.at(i));
    }
    
    cout << ans << endl;
}