#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<char, int> mp;
    string march = "MARCH";
    for (char c: march) mp[c] = 0;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mp[S.at(0)]++;
    }

    int64_t ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                int ind1 = march.at(i), ind2 = march.at(j), ind3 = march.at(k);
                ans += mp.at(ind1) * mp.at(ind2) * mp.at(ind3);
            }
        }
    }
    cout << ans << endl;
}