#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> seen(26, -1);
    for (int i = 0; i < N; i++) seen[S[i] - 'a'] = i;

    int add_idx = -1;
    for (int i = 0; i < 26; i++) {
        if (seen[i] == -1) {
            add_idx = i;
            break;
        }
    }

    string ans = "";
    if (add_idx != -1) ans = S + (char)('a' + add_idx);
    else {
        for (int i = N - 1; i >= 0; i--) {
            for (int next = S[i] - 'a' + 1; next < 26; next++) {
                if (seen[next] > i) {
                    ans = S.substr(0, i) + (char)('a' + next);
                    goto OUT;
                }
            }
        }
    }
OUT:
    if (ans == "") cout << -1 << endl;
    else cout << ans << endl;
}