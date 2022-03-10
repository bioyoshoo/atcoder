#include <bits/stdc++.h>
using namespace std;

string make_id(int n) {
    string n_s = to_string(n);
    int n_size = n_s.size();
    string ans = "";
    for (int i = 0; i < (6 - n_size); i++) ans += '0';
    ans += n_s;
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> V(N);
    for (int c_id = 0; c_id < M; c_id++) {
        int pref_id, year;
        cin >> pref_id >> year;
        pref_id--;
        pair p = make_pair(year, c_id);
        V.at(pref_id).push_back(p);
    }

    vector<string> ans(M);
    for (int c = 0; c < N; c++) {
        int size = V.at(c).size();
        if (size > 0) {
            sort(V.at(c).begin(), V.at(c).end());
            for (int order = 0; order < size; order++) {
                string id = make_id(c + 1) + make_id(order + 1);
                int p_id = V.at(c).at(order).second;
                ans.at(p_id) = id;
            }

        }
    }

    for (string s: ans) cout << s << endl;
}