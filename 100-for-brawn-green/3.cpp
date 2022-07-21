#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool check(string s) {
    bool flag = true;
    for (auto c: s) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') flag = false;
    }
    return flag;
}

int main() {
    string S; cin >> S;
    int N = S.size();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            string sub_s = S.substr(i, j - i + 1);
            if (check(sub_s)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
}