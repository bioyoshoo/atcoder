#include <bits/stdc++.h>
using namespace std;
using my_tuple = tuple<int64_t, pair<int64_t, int64_t>>;
using pii = pair<int64_t, int64_t>;

int main() {
    int N;
    cin >> N;
    vector<my_tuple> V(N);

    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        pii p = make_pair(a, b);
        my_tuple m = {a + b, p};
        V.at(i) = m;
    }

    sort(V.rbegin(), V.rend());

    int64_t A = 0, B = 0;
    for (int i = 0; i < N; i++) {
        pii p;
        tie(ignore, p) = V.at(i);

        if (i % 2 == 0) A += p.first;
        else B += p.second;
    }

    cout << A - B << endl;
}