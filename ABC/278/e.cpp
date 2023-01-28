#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int H, W, N, h, w; cin >> H >> W >> N >> h >> w;
    set<int> st;
    vector<int> A(H, vector<int>(W)); {
        rep(i, H) rep(j, W) cin >> A[i][j];
        st.insert(A[i][j]);
    }
    set<int> dp = st;
    vector<int> ans(H - h, vector<int>(W - w));
    rep(i, H - h) rep(j, W - w) {
        if (i == 0 && j == 0) {
            ans[0][0] = st.size();
        }
        else {
            if (j == 0) {
                rep(k, w) 
            }
        }
    }
}