#include <bits/stdc++.h>
using namespace std;

int main() {
<<<<<<< HEAD
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
        
=======
    string S;
    cin >> S;
    int size = S.size();

    set<char> string_set;
    for (char c: S) string_set.insert(c);

    int ans = 10000;
    if (string_set.size() == 1) ans = 0;
    else {
        for (char c: string_set) {
            int candidate = 0;
            int pre_idx = 0;
            for (int i = 0; i < size; i++) {
                if (S[i] == c) {
                    if (pre_idx == 0) candidate = max(candidate, i);
                    else candidate = max(candidate, i - pre_idx - 1);
                    pre_idx = i;
                }
                else if (i == size - 1) candidate = max(candidate, size - 1 - pre_idx);
            }

            ans = min(ans, candidate);
        }
    }
>>>>>>> 90b983a3b7ed233c62f00ab424f77a6514f7372a

    cout << ans << endl;
}