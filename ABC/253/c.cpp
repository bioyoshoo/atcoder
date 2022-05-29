#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    map<ll, ll> mp;
    priority_queue<ll> max_pq;
    priority_queue<ll, vector<ll>, greater<ll>> min_pq;
    rep(q, Q) {
        int i; cin >> i;
        if (i == 1) {
            ll x; cin >> x;
            if (mp[x] == 0) {
                max_pq.push(x);
                min_pq.push(x);
            }
            mp[x]++;
        }
        else if (i == 2) {
            ll x, c; cin >> x >> c;
            if (mp[x] == 0) continue;
            
            mp[x] = max(mp[x] - c, 0LL);
            if (mp[x] == 0 && max_pq.top() == x) max_pq.pop();
            if (mp[x] == 0 && min_pq.top() == x) min_pq.pop();
        }
        else if (i == 3) {
            ll max_cand = max_pq.top();
            while (mp[max_cand] != 0) {
                max_pq.pop();
                max_cand = max_pq.pop();
            }
            ll min_cand = min_pq.top();
            while (mp[min_cand] != 0) {
                min_pq.pop();
                min_cand = min_pq.pop();
            }
            cout << max_cand - min_cand << endl;
        }
    }
}