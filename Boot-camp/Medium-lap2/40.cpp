#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Gap(M - 1);
    for (int i = 0; i < M; i++) cin >> X.at(i);

    sort(X.begin(), X.end());

    int64_t ans = 0;
    if (M > 1) {
        for (int i = 1; i < M; i++) {
            Gap.at(i - 1) = X.at(i) - X.at(i - 1);
            ans += Gap.at(i - 1);
        }

        sort(Gap.rbegin(), Gap.rend());

        for (int i = 0; i < N - 1; i++) ans -= Gap.at(i);
    }
        
<<<<<<< HEAD
=======


>>>>>>> 360e01459e0d6390f3859a80197c3f887d9b6d45
    cout << ans << endl;
}