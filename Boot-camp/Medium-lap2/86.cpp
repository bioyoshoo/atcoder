#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a]++;
    }

    bool ans = false;
    if (mp.size() == 3) {
        vector<int64_t> V;
        for (auto m: mp) V.push_back(m.first);
        bool cand1 = (V[0] ^ V[1] ^ V[2]) == 0;
        bool cand2 = (mp[V[0]] == N / 3) && (mp[V[1]] == N / 3) && (mp[V[2]] == N / 3);
        if (cand1 && cand2) ans = true;
    }
    else if (mp.size() == 2 && mp[0] == N / 3) ans = true;
    else if (mp.size() == 1 && mp[0] == N) ans = true;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}