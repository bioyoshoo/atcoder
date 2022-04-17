#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, C, K;
    cin >> N >> C >> K;
    
    vector<int64_t> T(N);
    for (int i = 0; i < N; i++) cin >> T.at(i);
    sort(T.begin(), T.end());

    int64_t ans = 0;
    for (int i = 0; i < N;) {
        int64_t limit = T.at(i) + K;
        int j = i;
        while (j < N && T.at(j) <= limit && j - i + 1 <= C) j++;
        ans++;
        if (i == j) j++;
        i = j;
    }

    cout << ans << endl;
}