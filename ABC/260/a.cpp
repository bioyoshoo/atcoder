#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    vector<int> cnt(26);
    for (auto c: S) cnt[(int)(c - 'a')]++;
    
    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            flag = true;
            cout << (char)('a' + i) << endl;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
}