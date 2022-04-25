#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<set<char>> V(N);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        set<char> s;
        for (char c: S) s.insert(c);
        V.at(i) = s;
    }

    int ans = 0;
    for (int i = 0; i < (1LL << N); i++) {
        vector<int> table(26, 0);
        for (int j = 0; j < N; j++) {
            if (i & (1LL << j)) {
                for (char c: V[j]) table[c - 'a']++;
            }
        }
        int cand = 0;
        for (int k = 0; k < 26; k++) if (table[k] == K) cand++;
        ans = max(ans, cand);
    }

    cout << ans << endl;
}