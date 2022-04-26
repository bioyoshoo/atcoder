#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();

    vector<string> ans;
    for (int start = 0; start < n; start++) {
        if (start + m > n) continue;
        string key = S.substr(start, m);

        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (S[start + j] != '?' && S[start + j] != T[j]) flag = false;
        }

        if (flag) {
            string cand = S;
            for (int i = 0; i < n; i++) {
                if (i < start && S[i] == '?') cand[i] = 'a';
                else if (start <= i && i < start + m) cand[i] = T[i - start];
                else if (start + m <= i && S[i] == '?') cand[i] = 'a';
            }
            ans.push_back(cand);
        }
    }

    if (ans.size() == 0) cout << "UNRESTORABLE" << endl;
    else {
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    }
}