#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T; cin >> S >> T;
    int n = S.size(); int m = T.size();

    vector<pair<char, int>> S_v, T_v;
    
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && S[i] == S[j]) j++;
        S_v.push_back({S[i], j - i});
        i = j;
    }
    for (int i = 0; i < m;) {
        int j = i;
        while (j < m && T[i] == T[j]) j++;
        T_v.push_back({T[i], j - i});
        i = j;
    }

    bool ans = true;
    if (S_v.size() == T_v.size()) {
        int k = S_v.size();
        rep(i, k) {
            int s_c = S_v[i].first;
            int s_len = S_v[i].second;
            int t_c = T_v[i].first;
            int t_len = T_v[i].second;

            if (s_c != t_c) ans = false;
            else if (s_len > t_len) ans = false;
            else if (s_len < t_len && s_len == 1) ans = false;
        }
    }
    else ans = false;
    
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}