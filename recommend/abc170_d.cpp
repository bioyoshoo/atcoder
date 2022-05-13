#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    vector<bool> table(MAX + 1, true);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        mp[a]++;
        A.at(i) = a;
        if (mp[a] > 1) continue;
        for (int j = 2 * a; j <= MAX; j += a) {
            if (table[j]) table[j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (table[A[i]] && mp[A[i]] == 1) ans++;
    }
    cout << ans << endl;
}