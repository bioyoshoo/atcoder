#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int64_t, int64_t>> cord(N);
    for (int i = 0; i < N; i++) {
        int64_t x, y;
        cin >> x >> y;
        cord.at(i) = make_pair(x, y);
    }

    map<pair<int64_t, int64_t>, int64_t> M;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int64_t x1, y1, x2, y2;
            tie(x1, y1) = cord.at(i);
            tie(x2, y2) = cord.at(j);
            pair key = make_pair(abs(x1 - x2), abs(y1 - y2));
            M[key]++;
        }
    }

    int64_t freq = 0;
    for (auto m: M) chmax(freq, m.second);

    cout << N - freq << endl;
}