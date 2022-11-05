#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using cord = pair<int, int>;

int main() {
    vector<cord> V;
    set<cord> st;
    int n = 0;
    rep(i, 9) {
        string S; cin >> S;
        rep(j, 9) {
            if (S[j] == '#') {
                V.push_back({i, j});
                st.insert({i, j});
                n++;
            }
        }
    }
    
    int ans = 0;
    rep(i, n) rep(j, n) if (i != j) {
        int ai, aj, bi, bj;
        tie(ai, aj) = V[i]; tie(bi, bj) = V[j];

        int di = bi - ai, dj = bj - aj;

        cord c = {bi - dj, bj + di}, d = {ai - dj, aj + di};

        if (st.count(c) && st.count(d)) ans++;
    }

    ans /= 4;
    cout << ans << endl;
}