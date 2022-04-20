#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();

    set<char> s;
    for (char c: S) s.insert(c);

    int ans = 0;
    for (char c: s) {
        
        int pre_idx = -1;
        for (int i = 1; i < n; i++) {
            if (S[i] == c) {
                ans = max(ans, i - pre_idx - 1);
                pre_idx = i;
            }
            else if (i == n - 1) ans = max(ans, i - pre_idx);
        }
    }

    cout << ans << endl;
}