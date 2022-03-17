#include <bits/stdc++.h>
using namespace std;

void DFS(int v, const int &charge, vector<int> &res, const set<int> &D) {
    if (v >= charge) {
        res.push_back(v);
        return;
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (v == 0 && i == 0) continue;
            if (D.count(i)) continue;
            int next_v = 10 * v + i;
            DFS(next_v, charge, res, D);
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    set<int> D;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        D.insert(d);
    };

    vector<int> res;
    DFS(0, N, res, D);
    
    sort(res.begin(), res.end());

    int ans = *lower_bound(res.begin(), res.end(), N);
    cout << ans << endl;
}