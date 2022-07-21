#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;

    set<int> st;
    vector<int> prev(N, -1), num(N);
    vector<int> ans(N, -1);

    rep(step, N) {
        int p; cin >> p; p--;

        auto it = st.lower_bound(p);

        if (it == st.end()) {
            st.insert(p);
            num[p] = 1;
        }
        else {
            prev[p] = *it;
            num[p] = num[*it] + 1;

            st.erase(*it);
            st.insert(p);
        }

        if (num[p] == K) {
            st.erase(p);
            int x = p;
            while (x != -1) {
                ans[x] = step + 1;
                x = prev[x];
            }
        }
    }
    rep(i, N) cout << ans[i] << '\n';
}