#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    map<int, int> mp;
    rep(i, N) {
        int a; cin >> a;
        mp[a]++;
    }
    int even = 0;
    for (auto m: mp) if (m.second % 2 == 0) even++;
    int ans = mp.size();
    if (even % 2 == 1) ans--;
    cout << ans << endl;
}