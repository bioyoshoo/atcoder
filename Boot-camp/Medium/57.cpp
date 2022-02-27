#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int64_t> mp;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        mp[S]++;
    }

    int64_t ans = 0;
    for (auto m: mp) ans += (int64_t)(m.second * (m.second - 1)) / 2;
    cout << ans << endl;
}