#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

string zero_pad(string s) {
    string res = s;
    int n = s.size();
    if (s.size() < 3) {
        rep(i, 3 - n) res = '0' + res;
    }
    return res;
}

int main() {
    int N; cin >> N;
    string S; cin >> S;

    set<string> ans;
    for (int x = 0; x < 1000; x++) {
        string cand = zero_pad(to_string(x));
        int cur = 0;
        rep(i, N) {
            if (S[i] == cand[cur]) cur++;
            if (cur == 3) {
                ans.insert(cand);
                break;
            }
        }
    }
    cout << ans.size() << endl;
}