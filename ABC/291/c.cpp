#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    set<pair<int, int>> st;

    pair<int, int> cord = {0, 0};
    st.insert(cord);

    rep(i, N) {
        if (S[i] == 'R') cord.first += 1;
        else if (S[i] == 'L') cord.first -= 1;
        else if (S[i] == 'U') cord.second += 1;
        else cord.second -= 1;

        if (st.count(cord)) {
            cout << "Yes" << endl;
            return 0;
        }
        else {
            st.insert(cord);
        }
    }

    cout << "No" << endl;
    return 0;
}
