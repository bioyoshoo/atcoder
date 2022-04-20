#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<pair<int64_t, int64_t>> V(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        V.at(i) = {b, a};
    }

    sort(V.begin(), V.end());

    int64_t done = 0;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        tie(b, a) = V.at(i);
        done += a;
        if (done > b) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}