#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e9;

int main() {
    int64_t N, K, S;
    cin >> N >> K >> S;
    vector<int64_t> ans(N);

    for (int i = 0; i < N; i++) {
        if (K > 0) {
            ans.at(i) = S;
            K--;
        }
        else {
            if (S != MAX) ans.at(i) = S + 1;
            else ans.at(i) = 1;
        }
    }

    for (int i: ans) cout << i << " ";
    cout << endl;
}