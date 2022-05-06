#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long W; cin >> W;
    map<int, long long> mp;
    for (int i = 0; i < N; i++) {
        int s, t; cin >> s >> t;
        long long p; cin >> p;
        mp[s] += p;
        mp[t] += -p;
    }
    bool ans = true;
    long long total = 0;
    for (auto m: mp) {
        total += m.second;
        if (total > W) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}