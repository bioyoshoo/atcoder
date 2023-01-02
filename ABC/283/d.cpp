#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    int n = S.size();

    vector<int> l_brancket(n), r_brancket(n);
    int l_cnt = 0, r_cnt = 0;
    rep(i, n) {
        if (S[i] == '(') {
            l_cnt++; l_brancket[i] = l_cnt;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (S[i] == ')') {
            r_cnt++; r_brancket[i] = r_cnt;
        }
    }

    bool ans = true;
    map<char, int> mp;
    rep(i, n) {
        if (S[i] == ')') {
            
            int l = 0;
            for (; l < n; l++) if (l_brancket[l] == r_brancket[i]) break;

            // remove
            for (int j = l; j < i; j++) {
                if (S[j] != '(' && S[j] != ')') mp[S[j]]--;
            }
        }
        
        else if (S[i] != '(' && S[i] != ')') {
            mp[S[i]]++;
            if (mp[S[i]] > 1) ans = false;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}