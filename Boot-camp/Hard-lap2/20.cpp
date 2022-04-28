#include <bits/stdc++.h>
using namespace std;

template<class T> string padding(T n) {
    string ans = "";
    string n_s = to_string(n);
    int keta = n_s.size();
    for (int i = 0; i < 6 - keta; i++) ans += "0";
    ans += n_s;
    return ans;
}

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<vector<pair<int64_t, int64_t>>> table(N);
    for (int i = 0; i < M; i++) {
        int64_t p, y;
        cin >> p >> y;
        p--;
        table[p].push_back({y, i});
    }
    
    vector<string> ans(M);
    for (int i = 0; i < N; i++) {
        if (table[i].size() == 0) continue;
        vector<pair<int64_t, int64_t>> pref = table[i];
        int size = pref.size();
        sort(pref.begin(), pref.end());
        string p_id = padding(i + 1);
        for (int j = 0; j < size; j++) {
            string y_id = padding(j + 1);
            int idx = pref[j].second;
            ans[idx] = p_id + y_id;
        }
    }

    for (int i = 0; i < M; i++) cout << ans[i] << endl;
}