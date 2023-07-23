#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Interval = pair<int, int>;

bool cmp1(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

bool cmp2 (const Interval &a, const Interval &b) {
    return a.first > b.first;
}

int L[100010], R[100010];
int cntL[200010], cntR[200010];

int main() {
    int N, K; cin >> N >> K;
    vector<Interval> M(N);
    rep(i, N) {
        cin >> L[i] >> R[i]; R[i] += K;
    }

    // L までに参加できる最大の会議数
    vector<Interval> tmp1;
    rep(i, N) tmp1.push_back(Interval(L[i], R[i]));
    sort(tmp1.begin(), tmp1.end(), cmp1);
    rep(i, 200010) cntL[i] = 0;
    int cur_t = -1;
    int cnt = 0;
    rep(i, N) {
        int start, end; tie(start, end) = tmp1[i];
        if (cur_t <= start) {
            cnt++;
            cur_t = end;
            cntL[cur_t] = cnt;
        }
    }

    // R 以降参加できる最大の会議数
    vector<Interval> tmp2;
    rep(i, N) tmp2.push_back(Interval(L[i], R[i]));
    sort(tmp2.begin(), tmp2.end(), cmp2);
    rep(i, 200010) cntR[i] = 0;
    cur_t = 200000;
    cnt = 0;
    rep(i, N) {
        int start, end; tie(start, end) = tmp2[i];
        if (end <= cur_t) {
            cnt++;
            cur_t = start;
            cntR[cur_t] = cnt;
        }
    }

    for (int i = 1; i < 200000; i++) cntL[i] = max(cntL[i], cntL[i - 1]);
    for (int i = 200000; i >= 0; i--) cntR[i] = max(cntR[i], cntR[i + 1]);
    
    rep(i, N) {
        int ans = cntL[L[i]] + 1 + cntR[R[i]];
        cout << ans << endl;
    }
}
