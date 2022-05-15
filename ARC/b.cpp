#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    string S; cin >> S;

    ll ans = -1;
    for (int i = 1; i <= N / 2; i++) {
        if (N % i != 0) continue;
        vector<map<char, int>> V(i);
        for (int j = 0; j < N; j++) {
            V[j % i][S[j]]++;
        }
        ll change = 0;
        for (auto v: V) {
            for (auto m: v) {
                change += N / i - m.second;
                break;
            }
        }
        if (change <= K) {
            ans = i;
            break;
        }
    }
    if (ans == -1) {
        set<string> st;
        for (int i = 0; i < N; i++) {
            st.insert(S.substr(i) + S.substr(0, i));
        }
        ans = st.size();
    }
    cout << ans << endl;
}