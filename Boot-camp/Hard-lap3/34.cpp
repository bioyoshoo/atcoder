#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    int N; cin >> N;
    map<int, int> mp;
    rep(i, N) {
        int a; cin >> a;
        mp[a]++;
    }
    
    bool flag = true;
    if (N % 2 == 1) {
        if (mp[0] != 1) flag = false;
        for (int i = 1; i < N; i++) {
            if (i % 2 == 0 && mp[i] != 2) flag = false;
            else if (i % 2 == 1 && mp[i] != 0) flag = false;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (i % 2 == 1 && mp[i] != 2) flag = false;
            else if (i % 2 == 0 && mp[i] != 0) flag = false;
        }
    }
    if (flag) {
        mint ans = 1;
        for (int i = 0; i < N / 2; i++) ans *= 2;
        cout << ans.val() << endl;
    }
    else cout << 0 << endl;
}