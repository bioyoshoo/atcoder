#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    map<int64_t, int64_t> mp;

    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        A.at(i) = a;
        mp[a]++;
    }

    int64_t sum = 0;
    for (auto m: mp) {
        sum += (m.second) * (m.second - 1) / 2;
    }

    for (int i = 0; i < N; i++) {
        cout << sum - (mp[A.at(i)] - 1) << endl;
    }
}