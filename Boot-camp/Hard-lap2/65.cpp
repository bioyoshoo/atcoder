#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a; cin >> a; mp[a]++;
    }

    int evens = 0;
    for (auto m: mp) if (m.second % 2 == 0) evens++;
    int ans = mp.size();
    if (evens % 2 != 0) ans--;
    cout << ans << endl;
}