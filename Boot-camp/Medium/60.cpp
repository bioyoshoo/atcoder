#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<char, int64_t> mp;
    string march = "MARCH";
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mp[S.at(0)]++;
    }

    int64_t ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                char ind1 = march.at(i), ind2 = march.at(j), ind3 = march.at(k);
                ans += mp[ind1] * mp[ind2] * mp[ind3];
            }
        }
    }
    cout << ans << endl;
}