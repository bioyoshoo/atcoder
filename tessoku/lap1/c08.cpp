#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int check(string s, string t) {
    int cnt = 0;
    rep(i, 4) {
        if (s[i] != t[i]) cnt++;
    }
    if (cnt == 0) return 1;
    else if (cnt == 1) return 2;
    return 3;
}

string pad(string s) {
    rep(i, 4 - (int)s.size()) s = "0" + s;
    return s;
}

int main() {
    int N; cin >> N;
    vector<pair<string, int>> V(N);
    rep(i, N) {
        string s; int t; cin >> s >> t;
        if (t == 1) {
            cout << s << endl;
            return 0;
        }
        V[i] = make_pair(s, t);
    }

    vector<string> ans;
    for (int x = 0; x <= 9999; x++) {
        string cand = pad(to_string(x));

        bool ok = true;
        rep(i, N) {
            string s; int t; tie(s, t) = V[i];
            if (t != check(cand, s)) ok = false;
        }

        if (ok) ans.push_back(cand);
    }

    if (ans.size() > 1) cout << "Can't Solve" << endl;
    else cout << ans[0] << endl;
    return 0;
}
