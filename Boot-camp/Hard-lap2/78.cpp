#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = S.size();

    set<string> candidate;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= 5; k++) {
            if (i + k - 1 >= N) continue;
            string sub = S.substr(i, k);
            candidate.insert(sub);
        }
    }
    vector<string> V;
    for (string s: candidate) V.push_back(s);
    sort(V.begin(), V.end());
    string ans = V.at(K - 1);
    cout << ans << endl;
}