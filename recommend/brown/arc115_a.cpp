#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int zero = 0, one = 0;
        for (auto c: s) {
            if (c == '0') zero++;
            else one++;
        }
        pair<int, int> p = {zero, one};
        mp[p]++;
    }
    long long ans = 0;
    for (auto m: mp) {
        ans += (N - m.second) * m.second;
    }
    ans /= 2;
    cout << ans << endl;
}