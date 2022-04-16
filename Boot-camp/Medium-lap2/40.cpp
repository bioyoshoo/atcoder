#include <bits/stdc++.h>
using namespace std;

int main() {
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

    cout << ans << endl;
}