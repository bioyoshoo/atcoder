#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    map<char, int64_t> mp;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mp[S[0]]++;
    }

    string march = "MARCH";
    int64_t ans = 0;
    for (int64_t i = 0; i < (1 << 5); i++) {
        int64_t cnt = 0, ptn = 1;
        for (int j = 0; j < 5; j++) {
            if (i & (1 << j)) {
                cnt++;
                ptn *= mp[march[j]];
            }
        }
        if (cnt == 3) ans += ptn;
    }

    cout << ans << endl;
}