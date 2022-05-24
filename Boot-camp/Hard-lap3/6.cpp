#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T; cin >> S >> T;
    int n = S.size(), m = T.size();

    vector<string> V;
    for (int s = 0; s < n; s++) {
        if (s + m - 1 >= n) continue;
        
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (S[s + i] != '?' && S[s + i] != T[i]) flag = false;
        }
        if (flag) {
            string cand = "";
            for (int i = 0; i < n;) {
                if (i == s) {
                    cand += T;
                    i += m;
                }
                else {
                    if (S[i] == '?') cand += 'a';
                    else cand += S[i];
                    i++;
                }
            }
            V.push_back(cand);
        }
    }
    string ans = "";
    if (V.size()) {
        sort(V.begin(), V.end());
        ans = V[0];
    }
    else ans = "UNRESTORABLE";
    cout << ans << endl;
}