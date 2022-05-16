#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    string S; cin >> S;

    multiset<ll> st;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            int num_A = 0, num_C = 0;
            
            int j = i;
            while (j - 1 >= 0 && S[j - 1] == 'A') j--;
            num_A = i - j;

            int k = i;
            while (k + 1 < N && S[k + 1] == 'C') k++;
            num_C = k - i;

            int potential = min(num_A, num_C);
            if (potential > 0) st.insert(potential);
        }
    }
    int ans = 0;
    while (!st.empty()) {
        if (ans % 2 == 0) {
            int x = *prev(st.end());
            st.erase(prev(st.end()));
            if (x > 1) st.insert(x - 1);
        }
        else {
            st.erase(st.begin());
        }
        ans++;
    }
    cout << ans << endl;
}