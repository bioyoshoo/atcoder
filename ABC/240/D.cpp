#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        if (st.empty()) {
            pair p = make_pair(n, 1);
            st.push(p);
            ans++;
        }
        else {
            int pre_n, cnt;
            tie(pre_n, cnt) = st.top();

            if (n != pre_n) {
                pair p = make_pair(n, 1);
                st.push(p);
                ans++;
            }
            else if (n == pre_n) {
                st.pop();
                ans -= cnt;
                if (n > cnt + 1) {
                    pair p = make_pair(n, cnt + 1);
                    st.push(p);
                    ans += cnt + 1;
                }
            }
        }
        cout << ans << endl;
    }
}