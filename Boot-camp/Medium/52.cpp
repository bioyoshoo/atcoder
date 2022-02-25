#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int64_t, int64_t>> V(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        V.at(i) = { b, a };
    }

    sort(V.begin(), V.end());

    int64_t start = 0;
    bool ans = true;
    for (auto v: V) {
        start += v.second;
        if (start > v.first) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}