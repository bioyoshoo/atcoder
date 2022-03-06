#include <bits/stdc++.h>
using namespace std;

vector<pair<int64_t, int64_t>> map2vec(map<int64_t, int64_t> &M) {
    vector<pair<int64_t, int64_t>> ans;
    for (auto m: M) ans.emplace_back(m);
    return ans;
}

void sort_second(vector<pair<int64_t, int64_t>> &V) {
    sort(V.begin(), V.end(), 
    [](const auto &x, const auto &y) {
        return (x.second > y.second);
    });
}

int main() {
    int n;
    cin >> n;
    map<int64_t, int64_t> Even, Odd;
    Even[0] = 0;
    Odd[0] = 0;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (i % 2 == 0) Even[v]++;
        else if (i % 2 == 1) Odd[v]++;
    }

    vector<pair<int64_t, int64_t>> Even_vec, Odd_vec;
    Even_vec = map2vec(Even);
    Odd_vec = map2vec(Odd);

    sort_second(Even_vec);
    sort_second(Odd_vec);

    pair<int64_t, int64_t> even_v, odd_v;
    int64_t ans;
    even_v = Even_vec.at(0);
    odd_v = Odd_vec.at(0);

    if (even_v.first == odd_v.first) {
        if (even_v.second >= odd_v.second) odd_v = Odd_vec.at(1);
        else even_v = Even_vec.at(1);
    }
    ans = n / 2 - even_v.second + n / 2 - odd_v.second;
    cout << ans << endl;
}