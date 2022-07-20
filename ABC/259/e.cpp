#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    set<map<ll, ll>> st;
    vector<vector<pair<ll, ll>>> A(N);
    map<ll, priority_queue<ll>> mp;
    map<ll, ll> lcm_mp;
    rep(i, N) {
        int m; cin >> m;
        rep(j, m) {
            ll p, e; cin >> p >> e;
            A[i].push_back({p, e});
            mp[p].push(e);
            if (lcm_mp[p] < e) lcm_mp[p] = e;
        }
    }
    
    rep(i, N) {
        int m = A[i].size();
        map<ll, priority_queue<ll>> mp_i = mp;
        map<ll, ll> lcm_mp_i = lcm_mp;
        
        rep(j, m) {
            ll p, e;
            tie(p, e) = A[i][j];
            if (mp_i[p].top() == e) {
                mp_i[p].pop();
                lcm_mp_i[p] = mp_i[p].top();
            }
            st.insert(lcm_mp_i);
        }
    }
    int ans = st.size();
    cout << ans << endl;
}