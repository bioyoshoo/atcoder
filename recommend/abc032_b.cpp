#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int k;
    cin >> k;

    set<string> candidate;
    for (int i = 0; i < N; i++) {
        if (i + k - 1 >= N) continue;
        string cand = S.substr(i, k);
        candidate.insert(cand);
    }

    int ans = (int)candidate.size();
    cout << ans << endl;
}