#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    map<int, int> mp;
    rep(i, 5) {
        int a; cin >> a;
        mp[a]++;
    }

    if (mp.size() != 2) {
        cout << "No" << endl;
    }
    else {
        int flag = 0;
        for (auto m: mp) {
            if (m.second == 2) flag += 1;
            if (m.second == 3) flag += 1;
        }
        if (flag == 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}