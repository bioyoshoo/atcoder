#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int64_t N;
    cin >> N;
    string S;
    cin >> S;

    map<char, int64_t> mp;
    for (char c: S) mp[c]++;

    int64_t ans = 1;
    for (auto m: mp) {
        ans *= m.second + 1;
        ans %= mod;
    }

    ans--;
    ans %= mod;
    cout << ans << endl;
}