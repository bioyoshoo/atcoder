#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> X(N);
    for (int i = 0; i < N; i++) cin >> X.at(i);
    vector<int64_t> sort_X = X;
    sort(sort_X.begin(), sort_X.end());

    int64_t cand1 = sort_X[N / 2 - 1], cand2 = sort_X[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= cand1) cout << cand2 << endl;
        else cout << cand1 << endl;
    }
}