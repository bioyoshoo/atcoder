#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> C(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (S.at(0) == 'E') C.at(0) = 1;
        }
        else if (S.at(i) == 'E') C.at(i) = C.at(i - 1) + 1;
        else C.at(i) = C.at(i - 1);
    }

    int ans = 1e6;
    for (int i = 0; i < N; i++) {
        int turn;
        if (i == 0) turn = C.at(N - 1) - C.at(0);
        else turn = (C.at(N - 1) - C.at(i)) + (i - C.at(i - 1));
        ans = min(ans, turn);
    }

    cout << ans << endl;
}