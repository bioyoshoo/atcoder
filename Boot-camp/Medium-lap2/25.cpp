#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a]++;
    }

    vector<int64_t> freq;
    for (auto m: mp) freq.push_back(m.second);
    int64_t n = freq.size();

    sort(freq.rbegin(), freq.rend());

    int64_t ans = 0;
    for (int i = K; i < n; i++) ans += freq.at(i);

    cout << ans << endl;
}