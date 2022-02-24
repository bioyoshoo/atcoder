#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int64_t, int64_t> M;
    for (int64_t i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        if (M.count(a)) M.at(a)++;
        else M[a] = 1;
    }

    vector<int64_t> V;
    for (auto m: M) {
        if (m.second >= 2) V.push_back(m.first);
    }

    if (V.empty() || V.size() < 2) cout << 0 << endl;
    else {
        sort(V.rbegin(), V.rend());
        if (M.at(V.at(0)) >= 4) cout << V.at(0) * V.at(0) << endl;
        else cout << V.at(0) * V.at(1) << endl;
    }
}
