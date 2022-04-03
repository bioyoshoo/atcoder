#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();

    vector<int> V(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (S.at(0) == 'B') V.at(0) = 1;
            else V.at(0) = 0; 
        }
        else if (S.at(i) == 'B') V.at(i) = V.at(i - 1) + 1;
        else V.at(i) = V.at(i - 1);
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'W') ans += V.at(i);
    }

    cout << ans << endl;
}