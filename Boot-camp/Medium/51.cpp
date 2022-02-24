#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int> V(N), W(N);
    for (int64_t i = 0; i < N; i++) cin >> V.at(i);

    W = V;
    sort(W.begin(), W.end());
    int64_t small, large;
    small = W.at(N / 2 - 1);
    large = W.at(N / 2);

    if (small == large) {
        for (int64_t i = 0; i < N; i++) cout << small << endl;
    }
    else {
        for (int64_t i = 0; i < N; i++) {
            if (V.at(i) <= small) cout << large << endl;
            else if (V.at(i) >= large) cout << small << endl;
        }
    }
}